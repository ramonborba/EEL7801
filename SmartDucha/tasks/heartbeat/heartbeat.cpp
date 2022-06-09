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

#include <cstdio>
#include "heartbeat.hpp"
#include "gpio_cxx.hpp"

using namespace idf;

TaskHandle_t xTaskHeartbeatHandle;

void vTaskHeartbeat(void *pvParameters)
{
    
    GPIO_Output Hearbeat_LED(GPIONum(HEARTBEAT_LED_PIN));
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

        xTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(500));
    }
    

}
