#include "Encrypter.hpp"

Encrypter::Encrypter(std::string userID)
{
    this->userID = userID;
    this->password = "";
    int i = 0;
    //generate a random password full of small characters, needs to be 9 characters lowercase 
    char character[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    while(i < 9)
    {
       //random num generator  
       int randomNum = (rand() % 25) + 0;
       password += character[randomNum];
       i++; 
    }
    std::cout << password << "\n";

}

std::string Encrypter::getUserID()
{
    return userID;
}
