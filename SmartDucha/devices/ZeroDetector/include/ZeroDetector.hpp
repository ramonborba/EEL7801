/**
 * @file ZeroDetector.hpp
 * 
 * @brief ZeroDetector device header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date26-07-2022 
 */

#pragma once

#include "gpio_cxx.hpp"

class ZeroDetector : public idf::GPIOInput
{
public:
    ~ZeroDetector() = default;

    static ZeroDetector& getInstance();

    using idf::GPIOInput::set_intr_type;
    using idf::GPIOInput::set_pull_mode;

    void registerIsr(intr_handler_t);
    void removeIsr();
    void enableIntr();
    void disableIntr();

private:
    ZeroDetector( idf::GPIONum );
    ZeroDetector(const ZeroDetector &) = default;
    ZeroDetector &operator=(const ZeroDetector &);
    idf::GPIOIntrManager& isrMngr;
    
};
