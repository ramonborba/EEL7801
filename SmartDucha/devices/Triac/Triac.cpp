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
#include "esp_rom_sys.h"
#include "gpio_cxx.hpp"
#include "pin_defs.hpp"
#include "esp_log.h"

static const char* TAG = "TRIAC";

Triac::Triac(idf::GPIONum num) : idf::GPIO_Output(num) {}


Triac& Triac::getInstance()
{
    static Triac singleton {idf::GPIONum(TRIAC_PIN)};
    return singleton;
}

void Triac::pulse()
{
    ESP_LOGV(TAG, "<Pulsing Triac>");
    set_high();
    esp_rom_delay_us(TRIAC_PULSE_WIDTH_US);
    set_low();
    esp_rom_delay_us(TRIAC_PULSE_WIDTH_US);
}
