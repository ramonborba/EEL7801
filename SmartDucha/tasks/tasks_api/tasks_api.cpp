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
    xTaskCreatePinnedToCore(vTaskHeartbeat, "TaskHeartbeat", 2048, NULL, 1, &xTaskHeartbeatHandle, tskNO_AFFINITY);

}
