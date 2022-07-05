/**
 * @file Profile.cpp
 * 
 * @brief Profile class source code
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 18-06-2022
 */

#include "Profile.hpp"
#include "esp_log.h"

static const char* TAG = "Profile Manager";

ProfileManager::ProfileManager() : defaultUser { }, currentUser { &defaultUser }, users { defaultUser } 
{
    ESP_LOGD(TAG, "Profile manager object created");
    ESP_LOGD(TAG, "Default user parameters:");
    ESP_LOGD(TAG, "Username: %s", defaultUser.username_.c_str());
    ESP_LOGD(TAG, "UserID: %i", defaultUser.profileID_);
    ESP_LOGD(TAG, "Is admin: %i", defaultUser.admin == true ? 1 : 0);
    ESP_LOGD(TAG, "Shower temp: %i", defaultUser.config.temperatura);
    ESP_LOGD(TAG, "Shower timer: %i", defaultUser.config.tempo_maximo);
    ESP_LOGD(TAG, "Shower valve pos: %i", defaultUser.config.vazao);
    ESP_LOGD(TAG, "Shower valve max: %i", defaultUser.config.vazao_maximo);
}

void ProfileManager::setUsername( std::string new_name )
{
    currentUser->username_ = new_name;
}

uint8_t ProfileManager::checkValidID( uint16_t newID )
{
    if (newID <= 9999)
    {
        return 1;
    }

    return 0; 
}

void ProfileManager::setProfileID( uint16_t newID )
{
    if (checkValidID( newID ))
    {
        currentUser->profileID_ = newID;
    }
    else
    {
        ESP_LOGE(TAG, "Invalid profile ID.");
    }
    
}


// void ProfileManager::setShowerConfig( ShowerConfig newConfig )

void ProfileManager::setCurrentUser( uint16_t newUserID )
{
    if ( checkValidID(newUserID) )
    {
        for (auto &user : users)
        {
            if (newUserID == user.profileID_)
            {
                currentUser = &user;
                return;
            }
        }
        ESP_LOGE(TAG, "Error changing current user.");
    }
}


std::string ProfileManager::getUsername()
{
    return currentUser->username_;
}


uint16_t ProfileManager::getProfileID()
{
    return currentUser->profileID_;
}


UserData ProfileManager::getUserData()
{
    return *currentUser;
}


ShowerConfig ProfileManager::getShowerConfig()
{
    return currentUser->config;
}

void ProfileManager::updateUserProfile( UserData new_user, uint16_t previousID )
{
    // Add error check
    for (auto &user : users)
    {
        if (user.profileID_ == previousID)
        {
            user = new_user;
            break;
        }
    }   
}


void ProfileManager::deleteUserProfile( uint16_t deleteID )
{
    // Add error check
    for (auto &user : users)
    {
        if (user.profileID_ == deleteID)
        {
          user = defaultUser;
            break;
        }        
    }
    
}


ProfileManager ProfileManager::getInstance()
{
    static ProfileManager singleton;
    return singleton;
}