/**
 * @file startup.h
 * 
 * @brief Statup task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */
#ifndef STARTUP_HPP_
#define STARTUP_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t xTaskStartupHandle;

/**
 * @brief Power control task
 * 
 * @param pvParameters Not used
 */
void vTaskStartup(void* pvParameters);

#endif /* STARTUP_HPP_ */