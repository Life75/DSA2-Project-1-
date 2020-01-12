#include "Encrypter.hpp"

Encrypter::Encrypter(std::string userID)
{
    this->userID = userID;
    
    //generate a random password full of small characters, needs to be 9 characters lowercase 
    /*while(i < 9)
    {

    }*/
}

std::string Encrypter::getUserID()
{
    return userID;
}
