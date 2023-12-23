```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include the header file for the sensor driver and data processing
#include "sensor_driver.h"
#include "data_processing.h"

// Define the threshold for triggering an alert
#define ALERT_THRESHOLD 100

// Function to check the current sensor data and trigger an alert if necessary
void check_alert() {
    // Get the current sensor data
    int currentData = get_current_data();

    // If the current data exceeds the alert threshold, trigger an alert
    if (currentData > ALERT_THRESHOLD) {
        trigger_alert(currentData);
    }
}

// Function to trigger an alert
void trigger_alert(int data) {
    // Get the current time
    time_t now;
    time(&now);

    // Print an alert message with the current time and sensor data
    printf("ALERT! High solar radiation detected at %s. Sensor reading: %d\n", ctime(&now), data);

    // TODO: Implement additional alert actions (e.g., sending a notification)
}

// Function to get the current sensor data
// This is a placeholder function and should be replaced with actual sensor reading code
int get_current_data() {
    // For now, just return a random number
    return rand() % 200;
}
```
