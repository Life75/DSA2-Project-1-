#include "Encrypter.hpp"




Encrypter::Encrypter()
{
    userID = "";
    password = "";
}

Encrypter::Encrypter(std::string userID)
{
    this->userID = userID;
    this->password = "";
  
   
   // std::cout << password << "\n";

}

void Encrypter::generatePassword()
{
    int i = 0;
    //generate a random password full of small characters, needs to be 9 characters lowercase 
    char character[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    srand((unsigned)time (0)); // makes random numbers for every run
    while(i < 9)
    {
       //random num generator  
       int randomNum = (rand() % 25) + 0;
       password += character[randomNum];
       i++; 
    }
}

std::string Encrypter::getUserID()
{
    return userID;
}

std::string Encrypter::getPassword()
{
    return password;
}
