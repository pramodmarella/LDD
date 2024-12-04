#include <stdio.h>
#include<stdlib.h>

// Define function prototypes for operations
int ADD(int,int);
int device_open(void);
int device_close(void);
ssize_t device_read(char *buffer, size_t length);
ssize_t device_write(const char *buffer, size_t length);

// Mimic the Linux file_operations struct
struct file_operations {
   int (*add_1)(int,int);
    int (*open)(void);
    int (*release)(void);
    ssize_t (*read)(char *buffer, size_t length);
    ssize_t (*write)(const char *buffer, size_t length);
};

int ADD(int n1,int n2)
{
	printf("sum %d\n",n1+n2);
	return 0;
}
// Implement the functions
int device_open(void) {
    printf("Device opened.\n");
    return 0; // Success
}

int device_close(void) {
    printf("Device closed.\n");
    return 0; // Success
}

ssize_t device_read(char *buffer, size_t length) {
    printf("Reading %zu bytes from device.\n", length);
    // Mimic reading by filling the buffer
    for (size_t i = 0; i < length; i++) {
        buffer[i] = 'A'; // Example data
    }
    return length; // Number of bytes read
}

ssize_t device_write(const char *buffer, size_t length) {
    printf("Writing %zu bytes to device: ", length);
    for (size_t i = 0; i < length; i++) {
        putchar(buffer[i]);
    }
    putchar('\n');
    return length; // Number of bytes written
}

// Create an instance of the operations structure
struct file_operations fops = {
    .open = device_open,
    .release = device_close,
    .read = device_read,
    .write = device_write,
    .add_1=ADD,
};

// Simulate user interaction with the "device"
int main(int argc,char **argv) {
    char read_buffer[10];

    // Mimic opening the device
    fops.open();

    // Mimic reading from the device
    fops.read(read_buffer, sizeof(read_buffer));
    printf("Data read: ");
    for (size_t i = 0; i < sizeof(read_buffer); i++) {
        putchar(read_buffer[i]);
    }
    putchar('\n');

    // Mimic writing to the device
    fops.write("Hello", 5);
    int n1=atoi(argv[1]);
    int n2=atoi(argv[2]);
    fops.add_1(n1,n2);

    // Mimic closing the device
    fops.release();

    return 0;
}
