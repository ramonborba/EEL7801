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

ProfileManager::ProfileManager() : defaultUser { }, currentUser { &defaultUser }, users { defaultUser } { }

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