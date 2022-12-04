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
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_log.h"
#include "hal/adc_types.h"
#include <math.h>
#include <sys/_stdint.h>

static const char* NTC_SENSOR_TAG = "NTCSensor";

NTCSensor::NTCSensor( adc_config_t config ) : _value {38.0f}, _ntcChars { }, _config { config } 
{
    esp_adc_cal_characterize(_config.unit, _config.atten, _config.bit_width, 1100, &_ntcChars);
    if (config.unit == ADC_UNIT_1)
    {
        adc1_config_channel_atten((adc1_channel_t)config.channel, config.atten);
        adc1_config_width(config.bit_width);
    }
}

NTCSensor::~NTCSensor() { }

NTCSensor& NTCSensor::getInstance()
{
    static NTCSensor singleton (adc_config_t { .atten = NTC_ADC_ATTEN, .channel = NTC_ADC_CHANNEL, .unit = NTC_ADC_UNIT, .bit_width = NTC_ADC_BIT_WIDTH });
    return singleton;
}

double NTCSensor::readNTC()
{
    uint32_t voltage {0};
    ESP_LOGD(NTC_SENSOR_TAG, "Reading NTC value.");
    // TODO: implemenent ADC readind
    esp_adc_cal_get_voltage(_config.channel, &_ntcChars, &voltage);
    ESP_LOGD(NTC_SENSOR_TAG, "Voltage: %d", voltage);
    double res = (10000.0 * voltage) / (3300 - voltage);
    ESP_LOGD(NTC_SENSOR_TAG, "Resistance: %f", res);
    res = res/10000.0;
    double log = std::log10(res)/3950.0;
    _value = 1/((1/298.15) + log);
    _value -= 273.15;
    ESP_LOGD(NTC_SENSOR_TAG, "Temp: %f", _value);
    return _value;
}

double NTCSensor::getTemp()
{
    return _value;
}
