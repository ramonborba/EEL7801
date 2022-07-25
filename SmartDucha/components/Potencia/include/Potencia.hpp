/**
 * @file Potencia.hpp
 * 
 * @brief Potencia class header file
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

    static const uint16_t _tempos[];

    uint8_t _potencia_anterior;

    uint8_t _Temp2Pot(uint8_t temperatura_atual, uint8_t temperatura_alvo);

public:
    Potencia();
    ~Potencia() = default;

    uint16_t setInitialPower( uint8_t initialPower );
    uint16_t tempo(uint8_t temperatura_atual, uint8_t temperatura_alvo); // achei melhor assim para caso queiranois alterar depois
};

#endif /* POTENCIA_HPP_ */
