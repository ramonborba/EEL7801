/**
 * @file read_sensors.cpp
 * 
 * @brief Read sensors task implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#include <cstdint>
#include "read_sensors.hpp"
#include "NTCSensor.hpp"
#include "esp_log.h"

TaskHandle_t xTaskReadSensorHandle;
static const char *READ_SENSORS_TAG = "Read Sensors Task";

void vTaskReadSensor(void *pvParameters)
{
    NTCSensor WaterTempSensor;

    while (true)
    {
        TickType_t lastWakeTime = xTaskGetTickCount();

        uint8_t buffer;

        ESP_LOGI(READ_SENSORS_TAG, "Reading water temperature.");
        buffer = WaterTempSensor.readNTC();
        ESP_LOGI(READ_SENSORS_TAG, "Water temperature: %d", buffer);
        // TODO: Store values

        xTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(TASK_READ_SENSORS_PERIOD_MS));
    }
    
}
