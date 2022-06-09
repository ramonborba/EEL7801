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

#include "tasks_api.hpp"

extern "C" void app_main(void)
{
    create_tasks();
}
