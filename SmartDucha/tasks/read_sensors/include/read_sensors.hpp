/**
 * @file read_sensors.h
 * 
 * @brief Read sensors task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */
#ifndef READ_SENSORS_HPP_
#define READ_SENSORS_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t xTaskReadSensorsHandle;

/**
 * @brief Read sensors task
 * 
 * @param pvParameters Not used
 */
void vTaskReadSensors(void* pvParameters);

#endif /* READ_SENSORS_HPP_ */