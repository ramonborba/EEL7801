/**
 * @file Potencia.cpp
 * 
 * @brief Potencia class implementation
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 20-07-2022
 */

#include "Potencia.hpp"
#include <cstdint>

const uint16_t Potencia::_tempos[] = { 8333, 7367, 7109, 6925, 6777, 6650, 6538, 6437, 6344, 6257, 6176,
                                6099, 6026, 5956, 5889, 5825, 5762, 5702, 5643, 5586, 5531,
                                5476, 5423, 5371, 5320, 5270, 5220, 5171, 5124, 5077, 5030,
                                4984, 4938, 4893, 4848, 4804, 4760, 4716, 4673, 4630, 4587,
                                4544, 4502, 4460, 4417, 4373, 4334, 4292, 4250, 4208, 4167,
                                4125, 4083, 4042, 4000, 3958, 3916, 3874, 3832, 3789, 3747,
                                3704, 3661, 3617, 3574, 3530, 3484, 3440, 3395, 3350, 3304,
                                3257, 3210, 3162, 3113, 3064, 3013, 2962, 2910, 2857, 2803,
                                2747, 2690, 2631, 2571, 2509, 2444, 2377, 2307, 2234, 2158,
                                2076, 1990, 1896, 1795, 1683, 1556, 1408, 1224, 967, 0 }; // tempos em us

Potencia::Potencia() : _potencia_anterior { 30 } { }

uint16_t Potencia::setInitialPower(uint8_t initialPower)
{
    _potencia_anterior = initialPower;
    return _tempos[initialPower];
}

uint8_t Potencia::_Temp2Pot(uint8_t temperatura_atual, uint8_t temperatura_alvo)
{
    if (temperatura_atual > temperatura_alvo)
    {
        return _potencia_anterior--;
    }
    else if (temperatura_atual < temperatura_alvo)
    {
        return _potencia_anterior++;
    }
    else
    {
        return _potencia_anterior;
    }
}

uint16_t Potencia::tempo(uint8_t temperatura_atual, uint8_t temperatura_alvo)
{
    uint8_t potencia= _Temp2Pot(temperatura_atual, temperatura_alvo);

    if (potencia < POTMIN)
    {
        return -1;
    }
    else if (potencia > POTMAX)
    {
        return _tempos[POTMAX];
    }
    else
    {
        return _tempos[potencia];
    }
}
