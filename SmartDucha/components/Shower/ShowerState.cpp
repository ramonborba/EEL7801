/**
 * @file ShowerState.cpp
 * 
 * @brief Shower states implementation for the state machine
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 24-06-2022
 */

#include "ShowerState.hpp"
#include "esp_log.h"

static const char* TAG = "ShowerState";

/**
 * @brief IdleState definitions
 * 
 */

void IdleState::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering IdleState...");
}

void IdleState::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing IdleState...");
    
    /** Display idle screen
     * call display functinos to write on screen
     */

    /** Wait key press
     * set up queue to receive key presses
     */

    if (true /* key pressed */)
    {
        // Change to  state
        ssm->setState( SelectUser::getInstance() );
        return;
    }
    
    /** Check if sync is needed
     * set up a way to check bluetooth communication
     */

    if (false /* bluetooth received */)
    {
        // Change to SyncApp state
        ssm->setState( SyncApp::getInstance() );
        return;
    }
    
}

void IdleState::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting IdleState...");
}

ShowerState& IdleState::getInstance()
{
    static IdleState singleton;
    return singleton;
}

/**
 * @brief  SelectUser definition
 * 
 */

void SelectUser::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering SelectUser...");
}

void SelectUser::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing SelectUser...");
    
    /** Prompt user for profileID
     * 
     * queue to receive keypad info
     * check if ID valid
     */
    uint8_t typedID = 0;

    if (true /* ID valid */)
    {
        ssm->userManager.setCurrentUser( typedID /* profileID */ );
        ssm->setState( BeginShower::getInstance() );
    }
}

void SelectUser::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting SelectUser...");
}


ShowerState& SelectUser::getInstance()
{
    static SelectUser singleton;
    return singleton;
}


/**
 * @brief BeginShower definitions
 * 
 */

void BeginShower::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering BeginShower...");
}

void BeginShower::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing BeginShower...");
    
    /** start shower and go to manial control
     * 
     * set initial shower config from profile
     * start power control
     * go to manual mode
     */
     
    // ShowerDevice& shower = ShowerDevice::getInstance();
    // shower.setConfig( ssm->userManager.getShowerConfig() );
    // shower.start();
    
    ssm->setState( ManualControl::getInstance() );
}

void BeginShower::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting BeginShower...");
}

ShowerState& BeginShower::getInstance()
{
    static BeginShower singleton;
    return singleton;
}


/**
 * @brief ManualControl definitions
 * 
 */

void ManualControl::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering ManualControl...");
}

void ManualControl::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing ManualControl...");
    
    /** Change configure manually through the keypad
     * 
     * queue to receive valid keypad commands
     * update config base on received command
     */

    // while (showerOn)
    {
    // ShowerDevice& shower = ShowerDevice::getInstance();
    // switch (command)
    // case X
        // shower.updateX( newValue );
    }
    
    ssm->setState( EndShower::getInstance() );
}

void ManualControl::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting ManualControl...");
}

ShowerState& ManualControl::getInstance()
{
    static ManualControl singleton;
    return singleton;
}


/**
 * @brief EndShower definitions
 * 
 */

void EndShower::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering EndShower...");
}

void EndShower::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing EndShower...");
    // ShowerDevice& shower = Shower::getInstance();
    // shower.stop();
    ssm->setState( IdleState::getInstance() );
}

void EndShower::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting EndShower...");
}

ShowerState& EndShower::getInstance()
{
    static EndShower singleton;
    return singleton;
}


/**
 * @brief SyncApp definitions
 * 
 */
void SyncApp::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering SyncApp...");
}

void SyncApp::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing SyncApp...");
    
    /** Get bluetooth data
     * 
     * queue to receive bluetooth data
     * 
     * updateprofile with new data
     */
    
    // ssm->userManager.updateUserProfile( newData, profileID );
    
    ssm->setState( IdleState::getInstance() );
}

void SyncApp::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting SyncApp...");
}

ShowerState& SyncApp::getInstance()
{
    static SyncApp singleton;
    return singleton;
}

/**
 * @brief NULLState definitions
 * 
 */
void NULLState::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering NULLState...");
}

void NULLState::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing NULLState...");
}

void NULLState::exit( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Exiting NULLState...");
}


ShowerState& NULLState::getInstance()
{
    static NULLState singleton;
    return singleton;
}
