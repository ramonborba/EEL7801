/**
 * @file interface.cpp
 * 
 * @brief Interface task implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-05-2022
 */

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/portmacro.h"
#include "freertos/projdefs.h"
#include "interface.hpp"
#include "Shower.hpp"
#include "startup.hpp"
#include "esp_log.h"

TaskHandle_t xTaskInterfaceHandle;

static const char* TAG = "Interface Task";

void vTaskInterface(void *pvParameters)
{
    ESP_LOGI(TAG, "Created Interface Task");

    if (pdFAIL == xEventGroupWaitBits(xStartupEventGroupHandle, 1, 0x0UL, false, portMAX_DELAY /* pdMS_TO_TICKS(TASK_INTERFACE_INIT_TIMEOUT_MS) */))
    {
        ESP_LOGE(TAG, "Interface task init timeout! Suspending task...");
        vTaskSuspend(xTaskInterfaceHandle);
    };

    ShowerStateMachine shower;

    shower.startStateMachine();
    while (true)
    {
        shower.runMachine();
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
    
}
