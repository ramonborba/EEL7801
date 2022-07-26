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
#include "config.hpp"
#include "power_control.hpp"
#include "read_sensors.hpp"
#include "esp_rom_sys.h"
#include "Triac.hpp"
#include "esp_log.h"

static const char* TAG = "ShowerDevice";

ShowerDevice::ShowerDevice() : Potencia(), _Toff { setInitialPower(30) }, _config { }
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
    _Toff = setInitialPower(30);

    // Create read sensors task
#if defined(CONFIG_TASK_READ_SENSORS_ENABLE) && (CONFIG_TASK_READ_SENSORS_ENABLE == 1)
    if( !xTaskCreatePinnedToCore(vTaskReadSensors,
                            TASK_READ_SENSORS_NAME,        // Task name
                            TASK_READ_SENSORS_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_READ_SENSORS_PRIORITY,    // Task priority
                            &xTaskReadSensorsHandle,    // Task handle poiter
                            TASK_READ_SENSORS_CORE) )       // Task core affinity
    {
        ESP_LOGE(TAG, "Error creating read sensors task!");
    }
#endif /* CONFIG_TASK_READ_SENSORS_ENABLE */

    // open valve

    // Create power control task
#if defined(CONFIG_TASK_POWER_CONTROL_ENABLE) && (CONFIG_TASK_POWER_CONTROL_ENABLE == 1)
    if ( !xTaskCreatePinnedToCore(vTaskPowerControl,
                            TASK_POWER_CONTROL_NAME,        // Task name
                            TASK_POWER_CONTROL_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_POWER_CONTROL_PRIORITY,    // Task priority
                            &xTaskPowerControlHandle,    // Task handle poiter
                            TASK_POWER_CONTROL_CORE) )       // Task core affinity
    {
        ESP_LOGE(TAG, "Error creating power control task!");
    }
#endif /* CONFIG_TASK_POWER_CONTROL_ENABLE */
}

void ShowerDevice::stop()
{
    // suspend power control task
    vTaskDelete(xTaskPowerControlHandle);
    if ( xTaskPowerControlHandle )
    {
        ESP_LOGI(TAG, "Deleted power control task.");
    }
    else
    {
        ESP_LOGE(TAG, "Error deleting power control task!");
    }

    // delete read sensors task
    vTaskDelete(xTaskReadSensorsHandle);
    if ( xTaskReadSensorsHandle )
    {
        ESP_LOGI(TAG, "Deleted read sensors task.");
    }
    else
    {
        ESP_LOGE(TAG, "Error deleting read sensors task!");
    }
    
    // set triac to low
    Triac& triac = Triac::getInstance();
    triac.set_low();
    
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
