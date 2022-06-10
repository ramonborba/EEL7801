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
#include "config.hpp"
#include "heartbeat.hpp"
#include "app_comm.hpp"
#include "interface.hpp"
#include "power_control.hpp"
#include "read_sensors.hpp"
#include "startup.hpp"

void create_tasks()
{
#if defined(CONFIG_TASK_HEARTBEAT_ENABLE) && (CONFIG_TASK_HEARTBEAT_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskHeartbeat,
                            TASK_HEARTBEAT_NAME,        // Task name
                            TASK_HEARTBEAT_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_HEARTBEAT_PRIORITY,    // Task priority
                            &xTaskHeartbeatHandle,      // Task handle poiter
                            TASK_HEARTBEAT_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_HEARTBEAT_ENABLE */

#if defined(CONFIG_TASK_STARTUP_ENABLE) && (CONFIG_TASK_STARTUP_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskHeartbeat,
                            TASK_HEARTBEAT_NAME,        // Task name
                            TASK_HEARTBEAT_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_HEARTBEAT_PRIORITY,    // Task priority
                            &xTaskHeartbeatHandle,      // Task handle poiter
                            TASK_HEARTBEAT_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_STARTUP_ENABLE */

}
