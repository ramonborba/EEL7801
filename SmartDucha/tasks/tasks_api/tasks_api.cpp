/**
 * @file tasks_api.cpp
 * 
 * @brief Tasks API implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#include <cstdio>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "tasks_api.hpp"

void create_tasks()
{
    xTaskCreatePinnedToCore(vTaskHeartbeat,
                            TASK_HEARTBEAT_NAME,        // Task name
                            TASK_HEARTBEAT_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_HEARTBEAT_PRIORITY,    // Task priority
                            &xTaskHeartbeatHandle,      // Task handle poiter
                            TASK_HEARTBEAT_CORE);       // Task core affinity

}
