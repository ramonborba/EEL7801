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

#define HEARTBEAT_LED_PIN     2

extern TaskHandle_t xTaskHeartbeatHandle;

/**
 * @brief Heartbeat task
 * 
 * @param pvParameters Not used
 */
void vTaskHeartbeat(void *pvParameters);

#endif  /* HEARBEAT_H_ */