/**
 * @file POTENCIA.hpp
 * 
 * @brief POTENCIA class header file
 * 
 */
#ifndef POTENCIA_HPP_
#define POTENCIA_HPP_

#include <cstdint>

class Potencia
{
private:

    const uint8_t POTMIN = 10;// o detector de zero n�o � preciso o suficiente e precisamos ver se o MOC vai responder bem para ten��es baixas do inicio da onda
    const uint8_t POTMAX = 95;


// Tabela de hor�rios para definir triacs (em micro segundos)
// � o tempo em micro segundos ap�s o cruzamento de zero que devemos esperar antes de ativar o
// triac, onde o �ndice da matriz � a potencia aplicado de 1 a 100%,. Essa matriz �
// calculado com base na equa��o da pot�ncia efetiva aplicado a uma carga resistiva sobre o
// tempo, assumindo uma onda senoidal de 60HZ.
// deixar na memoria flash
//come�a em 1% e vai a 100% 

    static const uint8_t _tempos[];

    uint8_t _potencia_anterior;

    uint8_t _Temp2Pot(uint8_t temperatura_atual, uint8_t temperatura_alvo)
    {
        if (temperatura_atual > temperatura_alvo)
            return _potencia_anterior--;
        else if (temperatura_atual < temperatura_alvo)
            return _potencia_anterior++;
        else
            return _potencia_anterior;

    }

public:
    Potencia(/* args */) : _potencia_anterior { 50 } { }

    ~Potencia() { }

    int tempo(uint8_t temperatura_atual, uint8_t temperatura_alvo) // achei melhor assim para caso queiranois alterar depois
    {
        uint8_t potencia;
        potencia = _Temp2Pot(temperatura_atual, temperatura_alvo);
        if (potencia < POTMIN)
            return -1;// sistema desligado
        else if (potencia > POTMAX)
            return _tempos[POTMAX];
        else
            return _tempos[potencia];
    }
};

static const uint8_t _tempos[] = { 8333, 7367, 7109, 6925, 6777, 6650, 6538, 6437, 6344, 6257, 6176,
                                6099, 6026, 5956, 5889, 5825, 5762, 5702, 5643, 5586, 5531,
                                5476, 5423, 5371, 5320, 5270, 5220, 5171, 5124, 5077, 5030,
                                4984, 4938, 4893, 4848, 4804, 4760, 4716, 4673, 4630, 4587,
                                4544, 4502, 4460, 4417, 4373, 4334, 4292, 4250, 4208, 4167,
                                4125, 4083, 4042, 4000, 3958, 3916, 3874, 3832, 3789, 3747,
                                3704, 3661, 3617, 3574, 3530, 3484, 3440, 3395, 3350, 3304,
                                3257, 3210, 3162, 3113, 3064, 3013, 2962, 2910, 2857, 2803,
                                2747, 2690, 2631, 2571, 2509, 2444, 2377, 2307, 2234, 2158,
                                2076, 1990, 1896, 1795, 1683, 1556, 1408, 1224, 967, 0 }; // tempos em us


#endif /* POTENCIA_HPP_ */