#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/of.h>
#include <linux/videodev2.h>
#include <media/v4l2-subdev.h>
#include <media/v4l2-device.h>
#include <media/videobuf2-core.h>
#include <media/videobuf2-v4l2.h>
#include <media/videobuf2-dma-contig.h>

#define OV5640_I2C_ADDR 0x3C
#define REG_CHIP_ID_HIGH  0x300A
#define REG_CHIP_ID_LOW   0x300B
#define OV5640_CHIP_ID    0x5640

struct ov5640 {
    struct i2c_client *client;
    struct video_device vdev;
    struct v4l2_device v4l2_dev;
    struct vb2_queue queue;
    struct mutex lock;
};

/* I2C Read Function */
static int ov5640_read_reg(struct i2c_client *client, u16 reg)
{
    u8 buf[2] = { reg >> 8, reg & 0xFF };
    u8 val;
    struct i2c_msg msgs[2] = {
        { client->addr, 0, 2, buf },
        { client->addr, I2C_M_RD, 1, &val }
    };

    if (i2c_transfer(client->adapter, msgs, 2) < 0)
        return -1;
    return val;
}

/* Probe Function */
static int ov5640_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    struct ov5640 *sensor;
    int chip_id_high, chip_id_low;

    sensor = devm_kzalloc(&client->dev, sizeof(*sensor), GFP_KERNEL);
    if (!sensor)
        return -ENOMEM;

    sensor->client = client;
    mutex_init(&sensor->lock);

    /* Read Chip ID */
    chip_id_high = ov5640_read_reg(client, REG_CHIP_ID_HIGH);
    chip_id_low = ov5640_read_reg(client, REG_CHIP_ID_LOW);
    
    if (((chip_id_high << 8) | chip_id_low) != OV5640_CHIP_ID) {
        dev_err(&client->dev, "OV5640 not detected\n");
        return -ENODEV;
    }

    /* Initialize V4L2 Device */
    v4l2_device_register(&client->dev, &sensor->v4l2_dev);

    /* Register Video Device */
    strlcpy(sensor->vdev.name, "ov5640-camera", sizeof(sensor->vdev.name));
    sensor->vdev.v4l2_dev = &sensor->v4l2_dev;
    sensor->vdev.fops = &ov5640_fops;
    sensor->vdev.release = video_device_release_empty;
    video_register_device(&sensor->vdev, VFL_TYPE_GRABBER, -1);

    dev_info(&client->dev, "OV5640 Camera Registered with V4L2\n");
    return 0;
}

/* Remove Function */
static int ov5640_remove(struct i2c_client *client)
{
    struct ov5640 *sensor = i2c_get_clientdata(client);
    video_unregister_device(&sensor->vdev);
    v4l2_device_unregister(&sensor->v4l2_dev);
    return 0;
}

/* I2C Device ID Table */
static const struct i2c_device_id ov5640_id[] = {
    { "ov5640", 0 },
    { }
};
MODULE_DEVICE_TABLE(i2c, ov5640_id);

/* Device Tree Match */
static const struct of_device_id ov5640_of_match[] = {
    { .compatible = "ovti,ov5640" },
    { }
};
MODULE_DEVICE_TABLE(of, ov5640_of_match);

/* I2C Driver */
static struct i2c_driver ov5640_driver = {
    .driver = {
        .name = "ov5640",
        .of_match_table = ov5640_of_match,
    },
    .probe = ov5640_probe,
    .remove = ov5640_remove,
    .id_table = ov5640_id,
};

/* Register I2C Driver */
module_i2c_driver(ov5640_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("OV5640 I2C V4L2 Camera Driver with Buffering");

