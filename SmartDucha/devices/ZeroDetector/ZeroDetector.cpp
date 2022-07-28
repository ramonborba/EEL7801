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
#include "pin_defs.hpp"
#include "gpio_cxx.hpp"
#include "esp_log.h"

static const char* TAG = "ZeroDetector";


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
