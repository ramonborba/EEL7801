/**
 * @file interface.h
 * 
 * @brief Interface task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */
#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t xTaskInterfaceHandle;

/**
 * @brief User interface task
 * 
 * @param pvParameters Not used
 */
void vTaskInterface(void* pvParameters);

#endif /* INTERFACE_HPP_ */