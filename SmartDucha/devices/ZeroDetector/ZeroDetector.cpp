/**
 * @file ZeroDetector.cpp
 * 
 * @brief ZeroDetector device implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date26-07-2022 
 */

#include "ZeroDetector.hpp"
#include "driver/gpio.h"
#include "pin_defs.hpp"
#include "gpio_cxx.hpp"
#include "esp_log.h"

static const char* TAG = "ZeroDetector";

gpio_num_t gpio_to_driver_type(const idf::GPIONum &gpio_num)
{
    return static_cast<gpio_num_t>(gpio_num.get_num());
}

ZeroDetector::ZeroDetector( idf::GPIONum num ) : idf::GPIOInput( num ), isrMngr { idf::GPIOIntrManager::getInstance() } 
{

}


ZeroDetector& ZeroDetector::getInstance()
{
    static ZeroDetector singleton { idf::GPIONum(ZERO_DETECTOR_PIN) };
    return singleton;
}

void ZeroDetector::registerIsr(intr_handler_t isrHandle )
{
    ESP_LOGD(TAG, "Registering ZeroDetector ISR...");
    isrMngr.add_isr_handler(get_num(), isrHandle, NULL);
}

void ZeroDetector::removeIsr()
{
    ESP_LOGD(TAG, "Removing ZeroDetector ISRs...");
    isrMngr.remove_isr_handler(get_num());
}

void ZeroDetector::enableIntr()
{
    gpio_intr_enable(gpio_to_driver_type(get_num()));
}

void ZeroDetector::disableIntr()
{
    gpio_intr_disable(gpio_to_driver_type(get_num()));
}

