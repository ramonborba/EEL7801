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


void ProfileManager::setProfileID( uint8_t newID )
{
    currentUser->profileID_ = newID;
}


// setShowerConfig( shower config  );


std::string ProfileManager::getUsername()
{
    return currentUser->username_;
}


uint8_t ProfileManager::getProfileID()
{
    return currentUser->profileID_;
}


// getShowerConfig();


UserData ProfileManager::getUserData()
{
    return *currentUser;
}


void ProfileManager::updateUser( UserData new_user, uint8_t previousID )
{
    for (auto &user : users)
    {
        if (user.profileID_ == previousID)
        {
            user = new_user;
            break;
        }
    }   
}


void ProfileManager::deleteUser( uint8_t deleteID )
{
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