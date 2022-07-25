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

TaskHandle_t xTaskPowerControlHandle;

void vTaskPowerControl(void *pvParameters)
{

    ProfileManager& profile = ProfileManager::getInstance();
    ShowerDevice& shower = ShowerDevice::getInstance();
    NTCSensor& tempSensor = NTCSensor::getInstance();
    Triac& triac = Triac::getInstance();
    
    TickType_t startTime = xTaskGetTickCount();
    TickType_t maxTime = profile.getShowerConfig().tempo_maximo * 60 * xPortGetTickRateHz();

    shower.setInitialPower(20);

    while ( true && ( (xTaskGetTickCount() - startTime) <= maxTime ) )
    {
        shower.delay();
        triac.pulse();
        // shower.updateToff(tempSensor.getTemp(), profile.getShowerConfig().temperatura);
    }
    
}
