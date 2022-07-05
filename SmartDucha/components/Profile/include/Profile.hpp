/**
 * @file Profile.hpp
 * 
 * @brief Profile class header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 18-06-2022
 */

#ifndef PROFILE_HPP_
#define PROFILE_HPP_

#include <string>

struct ShowerConfig
{
    uint8_t temperatura;
    uint8_t vazao;
    uint8_t tempo_maximo;
    uint8_t vazao_maximo;
};


struct UserData
{
    std::string username_;
    uint16_t profileID_;
    bool admin;
    ShowerConfig config;
};


class ProfileManager
{
private:
    UserData defaultUser;
    UserData *currentUser;
    UserData users[5];
    ProfileManager();
    void setUsername( std::string );
    void setProfileID( uint16_t );
    // void setShowerConfig( ShowerConfig );
public:
    uint8_t checkValidID( uint16_t );
    void setCurrentUser( uint16_t );
    std::string getUsername();
    uint16_t getProfileID();
    UserData getUserData();
    ShowerConfig getShowerConfig();
    void updateUserProfile( UserData, uint16_t = 0 );
    void deleteUserProfile( uint16_t );
    static ProfileManager getInstance();
};

#endif /* PROFILE_HPP_ */