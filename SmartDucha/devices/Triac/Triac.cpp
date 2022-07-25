/**
 * @file Triac.cpp
 * 
 * @brief Triac device interface implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 22-07-2022
 */


#include "Triac.hpp"
#include "esp_log.h"
#include "esp_rom_sys.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio_cxx.hpp"
#include "pin_defs.hpp"
#include "esp_log.h"

static const char* TAG = "TRIAC";

Triac::Triac() : idf::GPIO_Output(idf::GPIONum(TRIAC_PIN)) {}


Triac& Triac::getInstance()
{
    static Triac singleton;
    return singleton;
}

void Triac::pulse()
{
    ESP_LOGI(TAG, "<Pulsing Triac>");
    set_high();
    vTaskDelay(pdMS_TO_TICKS(500));
    // esp_rom_delay_us(100);
    set_low();
}
