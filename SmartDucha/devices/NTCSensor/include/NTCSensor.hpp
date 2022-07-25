/**
 * @file NTCSensor.hpp
 * 
 * @brief NTCSensor class header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 14-06-2022
 */
#ifndef NTCSENSOR_HPP_
#define NTCSENSOR_HPP_

#include <cstdint>

class NTCSensor
{
private:
    /**
     * @brief Raw reading from adc
     * 
     */
    uint8_t _value;

    NTCSensor(/* args */);
    // TODO: Add ADC port information

public:
    
    /**
     * @brief NTCSensor constructor
     * 
     */
    
    ~NTCSensor();
    
    static NTCSensor& getInstance();
    uint8_t readNTC();
    uint8_t getTemp();
};




#endif /* NTCSENSOR_HPP_ */
