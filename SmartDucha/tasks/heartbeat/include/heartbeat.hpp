/**
 * @file heartbeat.h
 * 
 * @brief Heartbeat task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#ifndef HEARBEAT_H_
#define HEARBEAT_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task properties */
#define TASK_HEARTBEAT_NAME                 "TaskHeartbeat"
#define TASK_HEARTBEAT_STACK_SIZE           2048
#define TASK_HEARTBEAT_PRIORITY             1
#define TASK_HEARTBEAT_PERIOD_MS            500
#define TASK_HEARTBEAT_CORE        tskNO_AFFINITY
#define TASK_HEARTBEAT_INIT_TIMEOUT_MS      2000

#define HEARTBEAT_LED_PIN     2

extern TaskHandle_t xTaskHeartbeatHandle;

/**
 * @brief Heartbeat task
 * 
 * @param pvParameters Not used
 */
void vTaskHeartbeat(void *pvParameters);

#endif  /* HEARBEAT_H_ */