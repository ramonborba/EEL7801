/**
 * @file Shower.hpp
 * 
 * @brief Shower controller class header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 18-06-2022
 */

#ifndef SHOWER_HPP_
#define SHOWER_HPP_

#include "Profile.hpp"
#include "ShowerState.hpp"

class ShowerState;

class ShowerStateMachine
{
private:
    ShowerState* currentState;
public:
    ShowerStateMachine();
    ~ShowerStateMachine() = default;
    void startStateMachine();
    void runMachine();
    void setState(ShowerState& nextState);
    ProfileManager userManager;    
};


#endif /* SHOWER_HPP_ */
