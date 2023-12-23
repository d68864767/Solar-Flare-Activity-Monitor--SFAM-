```c
#include <stdio.h>
#include <stdlib.h>

// Include the header files for the sensor driver, data processing, and alert system
#include "sensor_driver.h"
#include "data_processing.h"
#include "alert_system.h"

// Define the frequency of sensor readings (in seconds)
#define SENSOR_READING_FREQUENCY 5

int main() {
    // Initialize the sensor
    if (init_sensor() != 0) {
        fprintf(stderr, "Failed to initialize sensor\n");
        return -1;
    }

    // Main loop
    while (1) {
        // Read data from the sensor
        int data = read_sensor_data();
        if (data < 0) {
            fprintf(stderr, "Failed to read sensor data\n");
            return -1;
        }

        // Log the sensor data
        log_data(data);

        // Check for alerts
        check_alert();

        // Wait for the next sensor reading
        sleep(SENSOR_READING_FREQUENCY);
    }

    // Close the sensor
    close_sensor();

    return 0;
}
```
