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
#if defined(CONFIG_TASK_STARTUP_ENABLE) && (CONFIG_TASK_STARTUP_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskStartup,
                            TASK_STARTUP_NAME,        // Task name
                            TASK_STARTUP_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_STARTUP_PRIORITY,    // Task priority
                            &xTaskStartupHandle,      // Task handle poiter
                            TASK_STARTUP_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_STARTUP_ENABLE */


#if defined(CONFIG_TASK_HEARTBEAT_ENABLE) && (CONFIG_TASK_HEARTBEAT_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskHeartbeat,
                            TASK_HEARTBEAT_NAME,        // Task name
                            TASK_HEARTBEAT_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_HEARTBEAT_PRIORITY,    // Task priority
                            &xTaskHeartbeatHandle,      // Task handle poiter
                            TASK_HEARTBEAT_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_HEARTBEAT_ENABLE */


#if defined(CONFIG_TASK_APP_COMM_ENABLE) && (CONFIG_TASK_APP_COMM_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskAppComm,
                            TASK_APP_COMM_NAME,        // Task name
                            TASK_APP_COMM_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_APP_COMM_PRIORITY,    // Task priority
                            &xTaskAppCommHandle,      // Task handle poiter
                            TASK_APP_COMM_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_APP_COMM_ENABLE */


#if defined(CONFIG_TASK_INTERFACE_ENABLE) && (CONFIG_TASK_INTERFACE_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskInterface,
                            TASK_INTERFACE_NAME,        // Task name
                            TASK_INTERFACE_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_INTERFACE_PRIORITY,    // Task priority
                            &xTaskInterfaceHandle,    // Task handle poiter
                            TASK_INTERFACE_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_INTERFACE_ENABLE */


#if defined(CONFIG_TASK_POWER_CONTROL_ENABLE) && (CONFIG_TASK_POWER_CONTROL_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskPowerControl,
                            TASK_POWER_CONTROL_NAME,        // Task name
                            TASK_POWER_CONTROL_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_POWER_CONTROL_PRIORITY,    // Task priority
                            &xTaskPowerControlHandle,    // Task handle poiter
                            TASK_POWER_CONTROL_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_POWER_CONTROL_ENABLE */


#if defined(CONFIG_TASK_READ_SENSORS_ENABLE) && (CONFIG_TASK_READ_SENSORS_ENABLE == 1)
    xTaskCreatePinnedToCore(vTaskReadSensors,
                            TASK_READ_SENSORS_NAME,        // Task name
                            TASK_READ_SENSORS_STACK_SIZE,  // Task stack size
                            NULL,                       // Task optional parameters
                            TASK_READ_SENSORS_PRIORITY,    // Task priority
                            &xTaskReadSensorsHandle,    // Task handle poiter
                            TASK_READ_SENSORS_CORE);       // Task core affinity

#endif  /* CONFIG_TASK_INTERFACE_ENABLE */

}
