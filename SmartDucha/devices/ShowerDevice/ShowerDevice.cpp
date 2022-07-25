/**
 * @file ShowerDevice.cpp
 * 
 * @brief Shower device class header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 13-07-2022
 */

#include "freertos/FreeRTOS.h"
#include "ShowerDevice.hpp"
#include "power_control.hpp"
#include "esp_rom_sys.h"


ShowerDevice::ShowerDevice() : Potencia(), _config { }
{

}

ShowerDevice& ShowerDevice::getInstance()
{
    static ShowerDevice singleton;
    return singleton;
}

void ShowerDevice::setConfig( ShowerConfig new_config )
{
    _config = new_config;
}

ShowerConfig ShowerDevice::getConfig()
{
    return _config;
}

void ShowerDevice::start()
{
    // open valve

    // Create power control task
    xTaskCreatePinnedToCore(vTaskPowerControl,
                            TASK_POWER_CONTROL_NAME,        // Task name
                            TASK_POWER_CONTROL_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_POWER_CONTROL_PRIORITY,    // Task priority
                            &xTaskPowerControlHandle,    // Task handle poiter
                            TASK_POWER_CONTROL_CORE);       // Task core affinity
}

void ShowerDevice::stop()
{
    // suspend power control task
    vTaskDelete(xTaskPowerControlHandle);
    
    
    // close valve
}

void ShowerDevice::delay()
{
    esp_rom_delay_us(_Toff);
}

void ShowerDevice::updateToff( uint8_t currentTemp, uint8_t userTemp )
{
    _Toff = tempo(currentTemp, userTemp);
}
