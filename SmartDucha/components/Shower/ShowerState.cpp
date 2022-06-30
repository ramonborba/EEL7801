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
 * @brief SelectUser definition
 * 
 */

void SelectUser::enter( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Entering SelectUser...");
}

void SelectUser::run( ShowerStateMachine* ssm )
{
    ESP_LOGD(TAG, "Executing SelectUser...");
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
