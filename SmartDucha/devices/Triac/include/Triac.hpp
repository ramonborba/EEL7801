/** 
 * @brief Triac device header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date22-07-2022 
 */
#pragma once

#include "gpio_cxx.hpp"

#define TRIAC_PULSE_WIDTH_US            10

class Triac : private idf::GPIO_Output
{
public:
    ~Triac() = default;
    void pulse();
    static Triac& getInstance();

    using idf::GPIO_Output::set_low;

private:
    Triac(idf::GPIONum num);
};
