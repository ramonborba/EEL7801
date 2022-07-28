/**
 * @file SmartDucha.cpp
 * 
 * @brief Application entry point
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
#include "esp_log.h"
#include "tasks_api.hpp"

extern "C" void app_main(void)
{
    /**
     * @brief Set application log level
     *
     * Levels: ESP_LOG_[NONE, ERROR, DEBUG, INFO, VERBOSE]
     */
    // esp_log_level_set("*", ESP_LOG_INFO);
    esp_log_level_set("*", ESP_LOG_DEBUG);
    create_event_groups();
    create_tasks();
}
