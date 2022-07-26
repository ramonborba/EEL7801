/**
 * @file startup.cpp
 * 
 * @brief Statup task implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#include "startup.hpp"
#include "esp_log.h"

TaskHandle_t xTaskStartupHandle;

static const char* TAG = "Startup Task";

void vTaskStartup(void *pvParameters)
{
    ESP_LOGI(TAG, "Created Startup Task");
}
