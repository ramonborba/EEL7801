/**
 * @file tasks_api.h
 * 
 * @brief Tasks API header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#ifndef TASKS_API_HPP_
#define TASKS_API_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

/**
 * @brief Create all tasks
 * 
 */
void create_tasks();


void create_event_groups();

#endif /* TASKS_API_HPP_ */
