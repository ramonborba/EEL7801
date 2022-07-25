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

/* Task properties */
#define TASK_READ_SENSORS_NAME                 "TaskReadSensors"
#define TASK_READ_SENSORS_STACK_SIZE           2048
#define TASK_READ_SENSORS_PRIORITY             1
#define TASK_READ_SENSORS_PERIOD_MS            10000
#define TASK_READ_SENSORS_CORE                 0
#define TASK_READ_SENSORS_INIT_TIMEOUT_MS      2000

extern TaskHandle_t xTaskReadSensorsHandle;

/**
 * @brief Read sensors task
 * 
 * @param pvParameters Not used
 */
void vTaskReadSensors(void* pvParameters);

#endif /* READ_SENSORS_HPP_ */
