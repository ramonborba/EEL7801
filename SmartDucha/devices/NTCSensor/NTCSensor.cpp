/**
 * @file NTCSensor.cpp
 * 
 * @brief NTCSensor class
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 14-06-2022
 */

#include "NTCSensor.hpp"
#include "esp_log.h"

static const char* NTC_SENSOR_TAG = "NTCSensor";

NTCSensor::NTCSensor(/* args */) : value_ {0} { }

NTCSensor::~NTCSensor() { }

uint8_t NTCSensor::readNTC()
{
    ESP_LOGD(NTC_SENSOR_TAG, "Reading NTC value.");
    // TODO: implemenent ADC readind
    // Convert value to temperature
    // value_ = temp
    return value_;
}