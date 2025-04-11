#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>
#include <x264.h>

#define DEVICE "/dev/video0"
#define WIDTH  1280
#define HEIGHT 720
#define PIXEL_FORMAT V4L2_PIX_FMT_YUYV
#define BUFFER_COUNT 4
#define VIDEO_DURATION 5  

struct buffer {
    void   *start;
    size_t length;
};

struct thread_args {
    int fd;
    struct buffer *buffers;
    int buffer_index;
    size_t captured_bytes;
    int flag;
    int f;
    pthread_mutex_t lock;
    pthread_cond_t cond;
};

void* cap_video(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
    struct v4l2_buffer buf_img = {0};  
    buf_img.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf_img.memory = V4L2_MEMORY_MMAP;

    while (args->flag) {
        if (ioctl(args->fd, VIDIOC_DQBUF, &buf_img) < 0) {
            perror("Failed to dequeue buffer");
            continue;
        }
        pthread_mutex_lock(&args->lock);

        args->buffer_index = buf_img.index;  
        args->captured_bytes = buf_img.bytesused;
        args->f = 1;  
        pthread_cond_signal(&args->cond);  
        pthread_mutex_unlock(&args->lock);
    }
    return NULL;
}

void* write_video(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
 //  FILE *file = fopen("video.mjpeg", "wb");
    FILE *file = fopen("video.yuv", "wb");
//    x264_nal_encode(args->buffers,"video.h264");
    if (!file) {
        perror("Failed to open video file");
        return NULL;
    }

    struct timespec start_time, current_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    while (args->flag) {
        pthread_mutex_lock(&args->lock);
        while (!args->f) {  
            pthread_cond_wait(&args->cond, &args->lock);  
        }

        clock_gettime(CLOCK_MONOTONIC, &current_time);
        if ((current_time.tv_sec - start_time.tv_sec) >= VIDEO_DURATION) {
            args->flag = 0;
        }

        fwrite(args->buffers[args->buffer_index].start, args->captured_bytes, 1, file);
        args->f = 0;  

        struct v4l2_buffer buf_file = {0};
        buf_file.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf_file.memory = V4L2_MEMORY_MMAP;
        buf_file.index = args->buffer_index;
        ioctl(args->fd, VIDIOC_QBUF, &buf_file);

        pthread_mutex_unlock(&args->lock);
    }

    fclose(file);
    return NULL;
}

int main() {
    int fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open video device");
        return -1;
    }

    struct thread_args args;
    args.fd = fd;
    args.buffer_index = -1;
    args.captured_bytes = 0;
    args.flag = 1;
    args.f = 0;
    pthread_mutex_init(&args.lock, NULL);
    pthread_cond_init(&args.cond, NULL);

    struct buffer buffers[BUFFER_COUNT];
    args.buffers = buffers;

    struct v4l2_capability cap;
    ioctl(fd, VIDIOC_QUERYCAP, &cap);

    struct v4l2_format fmt = {0};
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = WIDTH;
    fmt.fmt.pix.height = HEIGHT;
    fmt.fmt.pix.pixelformat = PIXEL_FORMAT;
    ioctl(fd, VIDIOC_S_FMT, &fmt);

    struct v4l2_requestbuffers req = {0};
    req.count = BUFFER_COUNT;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;
    ioctl(fd, VIDIOC_REQBUFS, &req);

    struct v4l2_buffer buf = {0};
    for (int i = 0; i < BUFFER_COUNT; i++) {
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;
        ioctl(fd, VIDIOC_QUERYBUF, &buf);
        buffers[i].length = buf.length;
        buffers[i].start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
        ioctl(fd, VIDIOC_QBUF, &buf);
    }

    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ioctl(fd, VIDIOC_STREAMON, &type);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, cap_video, &args);
    pthread_create(&t2, NULL, write_video, &args);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    ioctl(fd, VIDIOC_STREAMOFF, &type);
    for (int i = 0; i < BUFFER_COUNT; i++) {
        munmap(buffers[i].start, buffers[i].length);
    }

    close(fd);
    pthread_mutex_destroy(&args.lock);
    pthread_cond_destroy(&args.cond);

    return 0;
}

