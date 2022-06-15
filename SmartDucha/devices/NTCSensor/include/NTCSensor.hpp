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
    uint8_t value_;

    // TODO: Add ADC port information

public:
    
    /**
     * @brief NTCSensor constructor
     * 
     */
    NTCSensor(/* args */);
    
    ~NTCSensor();
    
    uint8_t readNTC();
};




#endif /* NTCSENSOR_HPP_ */