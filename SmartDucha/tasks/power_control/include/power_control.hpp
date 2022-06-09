/**
 * @file power_control.h
 * 
 * @brief Power control task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */
#ifndef POWER_CONTROL_HPP_
#define POWER_CONTROL_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t xTaskPowerControlHandle;

/**
 * @brief Power control task
 * 
 * @param pvParameters Not used
 */
void vTaskPowerControl(void* pvParameters);

#endif /* POWER_CONTROL_HPP_ */