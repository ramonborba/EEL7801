/**
 * @file ShowerDevice.hpp
 * 
 * @brief Shower device class header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 13-07-2022
 */

#include "Profile.hpp"
#include "Potencia.hpp"
#include <sys/_stdint.h>

class ShowerDevice : public Potencia
{
private:
    ShowerDevice();
    ShowerDevice(const ShowerDevice &) = default;
    ShowerDevice &operator=(const ShowerDevice &);
    
    uint16_t _Toff = {0};
    ShowerConfig _config;

public:
    ~ShowerDevice() = default;
    static ShowerDevice& getInstance();
    void setConfig( ShowerConfig );
    ShowerConfig getConfig();
    void start();
    void stop();
    void delay();
    void updateToff( uint8_t, uint8_t );
};
