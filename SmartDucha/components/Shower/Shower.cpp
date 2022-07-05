/**
 * @file Shower.cpp
 * 
 * @brief Shower controller class source code
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 18-06-2022
 */

#include "Shower.hpp"

ShowerStateMachine::ShowerStateMachine() : currentState{ &NULLState::getInstance() }, userManager{ ProfileManager::getInstance() }
{
}

void ShowerStateMachine::startStateMachine()
{
    setState( IdleState::getInstance() );
}
void ShowerStateMachine::runMachine()
{
    currentState->run(this);
}

void ShowerStateMachine::setState( ShowerState& nextState )
{
    currentState->exit(this);
    currentState = &nextState;
    currentState->enter(this);
}