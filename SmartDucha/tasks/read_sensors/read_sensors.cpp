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

#include "read_sensors.hpp"
#include "NTCSensor.hpp"
#include "esp_log.h"

TaskHandle_t xTaskReadSensorsHandle;
StaticTask_t xTaskReadSensorsBuffer;
StackType_t xTaskReadSensorsStack[TASK_READ_SENSORS_STACK_SIZE];

static const char *TAG = "Read Sensors Task";

void vTaskReadSensors(void *pvParameters)
{
    ESP_LOGI(TAG, "Created Read Sensors Task");

    NTCSensor& tempSensor = NTCSensor::getInstance();

    while (true)
    {
        TickType_t lastWakeTime = xTaskGetTickCount();

        uint8_t buffer = {0};

        ESP_LOGI(TAG, "Reading water temperature.");
        buffer = tempSensor.readNTC();
        ESP_LOGD(TAG, "Water temperature: %d", buffer);

        xTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(TASK_READ_SENSORS_PERIOD_MS));
    }
    
}
