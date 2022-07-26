/**
 * @file heartbeat.cpp
 * 
 * @brief Heartbeat task implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#include "heartbeat.hpp"
#include "gpio_cxx.hpp"
#include "pin_defs.hpp"
#include "esp_log.h"


TaskHandle_t xTaskHeartbeatHandle;

static const char* TAG = "Heartbeat Task";

void vTaskHeartbeat(void *pvParameters)
{
    ESP_LOGI(TAG, "Created Heartbeak Task");
    idf::GPIO_Output Hearbeat_LED(idf::GPIONum(HEARTBEAT_LED_PIN));
    uint8_t active = 0;

    while (true)
    {
        TickType_t lastWakeTime = xTaskGetTickCount();
        if (active)
        {
            Hearbeat_LED.set_high();
        }
        else
        {
            Hearbeat_LED.set_low();
        }
        active = (active > 0) ? 0 : 1;

        xTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(TASK_HEARTBEAT_PERIOD_MS));
    }
    

}
