/**
 * @file isr_handlers.cpp
 * 
 * @brief isr handlers implementations
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-07-2022
 */

#include <cstdint>
#include "isr_handlers.hpp"
#include "power_control.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void ISR_zeroDetector (void* pvParameters)
{
    BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
    uint32_t nValue = 0;
    if ( xTaskPowerControlHandle )
    {
        xTaskGenericNotifyFromISR(xTaskPowerControlHandle, 0, 0, eNoAction, &nValue, &pxHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(pxHigherPriorityTaskWoken);
    }
}

