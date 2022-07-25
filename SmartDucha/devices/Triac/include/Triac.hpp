/**
 * @file Triac.hpp
 * 
 * @brief Triac device header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date22-07-2022 
 */

#include "gpio_cxx.hpp"


class Triac : private idf::GPIO_Output
{
public:
    ~Triac() = default;
    void pulse();
    static Triac& getInstance();

private:
    Triac();
};
