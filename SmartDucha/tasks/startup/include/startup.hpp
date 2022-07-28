/**
 * @file startup.h
 * 
 * @brief Statup task header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */
#ifndef STARTUP_HPP_
#define STARTUP_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

/* Task properties */
#define TASK_STARTUP_NAME                 "TaskStartup"
#define TASK_STARTUP_STACK_SIZE           2048
#define TASK_STARTUP_PRIORITY             1
#define TASK_STARTUP_CORE                 1

extern TaskHandle_t xTaskStartupHandle;
extern StaticEventGroup_t xStartupEventGroupBuffer;
extern EventGroupHandle_t xStartupEventGroupHandle;


/**
 * @brief Power control task
 * 
 * @param pvParameters Not used
 */
void vTaskStartup(void* pvParameters);

#endif /* STARTUP_HPP_ */
