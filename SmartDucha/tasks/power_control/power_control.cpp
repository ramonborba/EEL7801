/**
 * @file power_control.cpp
 * 
 * @brief Power control task implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#include "power_control.hpp"
#include "Profile.hpp"
#include "ShowerDevice.hpp"
#include "NTCSensor.hpp"
#include "Triac.hpp"
#include "freertos/portmacro.h"
#include "esp_log.h"
#include "freertos/projdefs.h"
#include <sys/_stdint.h>

TaskHandle_t xTaskPowerControlHandle;
StaticTask_t xTaskPowerControlBuffer;
StackType_t  xTaskPowerControlStack[TASK_POWER_CONTROL_STACK_SIZE];

static const char* TAG = "Power Control Task";

static bool checkTimeout( TickType_t elapsed, TickType_t max )
{
    if (elapsed < max)
    {
        return true;
    }
    else
    {
        ESP_LOGI(TAG, "Shower timeout reached!");
        return false;
    }

}

static bool waitInerrupt()
{
    uint32_t nValue = 0;
    if ( xTaskGenericNotifyWait(0, 0x0UL, 0xFFFFFFFFUL, &nValue, pdMS_TO_TICKS(POWER_CONTROL_INTERRUPT_TIMEOUT) ) )
    {
        return true;
    }
    else
    {
        ESP_LOGI(TAG, "Interupt timed out!");
        return false;
    }
}
void vTaskPowerControl(void *pvParameters)
{

    ESP_LOGI(TAG, "Created Power Control Task");
    ProfileManager& profile = ProfileManager::getInstance();
    ShowerDevice& shower = ShowerDevice::getInstance();
    NTCSensor& tempSensor = NTCSensor::getInstance();
    Triac& triac = Triac::getInstance();
    
    TickType_t startTime = xTaskGetTickCount();
    TickType_t maxTime = profile.getShowerConfig().tempo_maximo * 60 * xPortGetTickRateHz();

    while (true)
    {
        while ( waitInerrupt() && checkTimeout( (xTaskGetTickCount() - startTime), maxTime ) )
        {
            ESP_LOGD(TAG, "<zero detected>");
            shower.delay();
            triac.pulse();
            shower.updateToff(tempSensor.getTemp(), profile.getShowerConfig().temperatura);
        }
        ESP_LOGI(TAG, "Suspending task...");
        triac.set_low();
        vTaskSuspend(xTaskPowerControlHandle);
    }
    
}


