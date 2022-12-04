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

#include <cstddef>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/portmacro.h"
#include "freertos/projdefs.h"
#include "interface.hpp"
#include "Shower.hpp"
#include "startup.hpp"
#include "gpio_cxx.hpp"
#include "isr_handlers.hpp"
#include "esp_log.h"

TaskHandle_t xTaskInterfaceHandle;

static const char* TAG = "Interface Task";

void vTaskInterface(void *pvParameters)
{
    ESP_LOGI(TAG, "Created Interface Task");

    idf::GPIOInput nextBtn (idf::GPIONum(18));
    nextBtn.set_intr_type(idf::GPIOIntrType::FALLING_EDGE());
    idf::GPIOIntrManager& intrMngr = idf::GPIOIntrManager::getInstance();
    intrMngr.add_isr_handler(nextBtn.get_num(), nextButton, NULL);

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
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    
}
