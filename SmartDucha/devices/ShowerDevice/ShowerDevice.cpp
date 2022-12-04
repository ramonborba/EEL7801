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
#include "ZeroDetector.hpp"
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

    xTaskReadSensorsHandle = xTaskCreateStaticPinnedToCore(vTaskReadSensors, 
                                                            TASK_READ_SENSORS_NAME, 
                                                            TASK_READ_SENSORS_STACK_SIZE, 
                                                            NULL, 
                                                            TASK_READ_SENSORS_PRIORITY, 
                                                            xTaskReadSensorsStack, 
                                                            &xTaskReadSensorsBuffer, 
                                                            TASK_READ_SENSORS_CORE);
    if ( !xTaskReadSensorsHandle )
    {
        ESP_LOGE(TAG, "Error creating read sensors task!");
    }

#endif /* CONFIG_TASK_READ_SENSORS_ENABLE */

    // open valve

    // Create power control task
#if defined(CONFIG_TASK_POWER_CONTROL_ENABLE) && (CONFIG_TASK_POWER_CONTROL_ENABLE == 1)

    xTaskPowerControlHandle = xTaskCreateStaticPinnedToCore(vTaskPowerControl, 
                                                            TASK_POWER_CONTROL_NAME, 
                                                            TASK_POWER_CONTROL_STACK_SIZE, 
                                                            NULL, 
                                                            TASK_POWER_CONTROL_PRIORITY, 
                                                            xTaskPowerControlStack, 
                                                            &xTaskPowerControlBuffer, 
                                                            TASK_POWER_CONTROL_CORE);
    if ( !xTaskPowerControlHandle )
    {
        ESP_LOGE(TAG, "Error creating power control task!");
    }

    ZeroDetector& zdet = ZeroDetector::getInstance();
    zdet.enableIntr();


#endif /* CONFIG_TASK_POWER_CONTROL_ENABLE */
}

void ShowerDevice::stop()
{
    TaskHandle_t xPCHandle = xTaskPowerControlHandle;
    TaskHandle_t xRSHandle = xTaskReadSensorsHandle;
    ZeroDetector& zdet = ZeroDetector::getInstance();

    zdet.disableIntr();
    // delete power control task
    xTaskPowerControlHandle = NULL;
    vTaskDelete(xPCHandle);
    ESP_LOGI(TAG, "Deleted power control task.");

    // delete read sensors task
    xTaskReadSensorsHandle = NULL;
    vTaskDelete(xRSHandle);
        ESP_LOGI(TAG, "Deleted read sensors task.");
    
    // set triac to low
    Triac& triac = Triac::getInstance();
    triac.set_low();
    
    // close valve
}

void ShowerDevice::delay()
{
    esp_rom_delay_us(_Toff);
}

void ShowerDevice::updateToff( float currentTemp, float userTemp )
{
    _Toff = tempo(currentTemp, userTemp);
}
