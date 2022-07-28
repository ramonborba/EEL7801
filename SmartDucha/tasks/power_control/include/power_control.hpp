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
#include "freertos/portmacro.h"
#include "freertos/task.h"

/* Task properties */
#define TASK_POWER_CONTROL_NAME                 "TaskPowerControl"
#define TASK_POWER_CONTROL_STACK_SIZE           2048
#define TASK_POWER_CONTROL_PRIORITY             1
#define TASK_POWER_CONTROL_PERIOD_MS            10000
#define TASK_POWER_CONTROL_CORE                 1
#define TASK_POWER_CONTROL_INIT_TIMEOUT_MS      2000

extern TaskHandle_t xTaskPowerControlHandle;
extern StaticTask_t xTaskPowerControlBuffer;
extern StackType_t  xTaskPowerControlStack[TASK_POWER_CONTROL_STACK_SIZE];


#define POWER_CONTROL_INTERRUPT_TIMEOUT         20

/**
 * @brief Power control task
 * 
 * @param pvParameters Not used
 */
void vTaskPowerControl(void* pvParameters);

#endif /* POWER_CONTROL_HPP_ */
