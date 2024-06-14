#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>

int main(void) 
{
    const struct device *lsm9ds1_ag = device_get_binding("LSM9DS1");
    //struct device *lsm9ds1_m = device_get_binding("LSM9DS1_M");

    if (!lsm9ds1_ag) {
        printk("Failed to find LSM9DS1 device\n");
        return -1;
    }

    struct sensor_value accel[3];
    struct sensor_value gyro[3];
    //struct sensor_value magn[3];

    while (1) {
        // Fetch sensor data
        sensor_sample_fetch(lsm9ds1_ag);
        //sensor_sample_fetch(lsm9ds1_m);

        // Get acceleration data
        sensor_channel_get(lsm9ds1_ag, SENSOR_CHAN_ACCEL_XYZ, accel);

        // Get gyroscope data
        sensor_channel_get(lsm9ds1_ag, SENSOR_CHAN_GYRO_XYZ, gyro);

        // Get magnetometer data
        //sensor_channel_get(lsm9ds1_m, SENSOR_CHAN_MAGN_XYZ, magn);

        printk("Accel: x=%f, y=%f, z=%f\n",
               sensor_value_to_double(&accel[0]),
               sensor_value_to_double(&accel[1]),
               sensor_value_to_double(&accel[2]));

        printk("Gyro: x=%f, y=%f, z=%f\n",
               sensor_value_to_double(&gyro[0]),
               sensor_value_to_double(&gyro[1]),
               sensor_value_to_double(&gyro[2]));

        //printk("Magn: x=%f, y=%f, z=%f\n",
               //sensor_value_to_double(&magn[0]),
               //sensor_value_to_double(&magn[1]),
               //sensor_value_to_double(&magn[2]));

        k_sleep(K_MSEC(1000));
    }
}

