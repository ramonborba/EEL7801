/**
 * @file app_comm.h
 * 
 * @brief App communications task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */
#ifndef APP_COMM_HPP_
#define APP_COMM_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task properties */
#define TASK_APP_COMM_NAME                 "TaskAppComm"
#define TASK_APP_COMM_STACK_SIZE           2048
#define TASK_APP_COMM_PRIORITY             1
#define TASK_APP_COMM_PERIOD_MS            10000
#define TASK_APP_COMM_CORE                 0
#define TASK_APP_COMM_INIT_TIMEOUT_MS      2000


extern TaskHandle_t xTaskAppCommHandle;

/**
 * @brief App communications task
 * 
 * @param pvParameters Not used
 */
void vTaskAppComm(void* pvParameters);

#endif /* APP_COMM_HPP_ */
