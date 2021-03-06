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

/* Task properties */
#define TASK_POWER_CONTROL_NAME                 "TaskPowerControl"
#define TASK_POWER_CONTROL_STACK_SIZE           2048
#define TASK_POWER_CONTROL_PRIORITY             1
#define TASK_POWER_CONTROL_PERIOD_MS            10000
#define TASK_POWER_CONTROL_CORE        tskNO_AFFINITY
#define TASK_POWER_CONTROL_INIT_TIMEOUT_MS      2000

extern TaskHandle_t xTaskPowerControlHandle;

/**
 * @brief Power control task
 * 
 * @param pvParameters Not used
 */
void vTaskPowerControl(void* pvParameters);

#endif /* POWER_CONTROL_HPP_ */