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

Triac::Triac() : idf::GPIO_Output(idf::GPIONum(HEARTBEAT_LED_PIN)) {}


Triac& Triac::getInstance()
{
    static Triac singleton;
    return singleton;
}

void Triac::pulse()
{
    ESP_LOGV(TAG, "<Pulsing Triac>");
    set_high();
    esp_rom_delay_us(50000);
    set_low();
    esp_rom_delay_us(50000);
}
