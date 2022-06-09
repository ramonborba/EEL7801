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

extern TaskHandle_t xTaskAppCommHandle;

/**
 * @brief App communications task
 * 
 * @param pvParameters Not used
 */
void vTaskAppComm(void* pvParameters);

#endif /* APP_COMM_HPP_ */