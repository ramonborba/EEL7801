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

/* Task properties */
#define TASK_INTERFACE_NAME                 "TaskInterface"
#define TASK_INTERFACE_STACK_SIZE           4096
#define TASK_INTERFACE_PRIORITY             1
#define TASK_INTERFACE_PERIOD_MS            10000
#define TASK_INTERFACE_CORE                 0
#define TASK_INTERFACE_INIT_TIMEOUT_MS      2000

extern TaskHandle_t xTaskInterfaceHandle;

/**
 * @brief User interface task
 * 
 * @param pvParameters Not used
 */
void vTaskInterface(void* pvParameters);

#endif /* INTERFACE_HPP_ */
