#ifndef ENCRYPTER_HPP_
#define ENCRYPTER_HPP_

#include <iostream>
#include <sstream>

class Encrypter
{
    private:
    std::string userID;
    std::string password;

    public:
    Encrypter();
    Encrypter(std::string userID); //generate the password when taking in the userID
    void generatePassword();
    std::string getUserID();
    std::string getPassword();
};
#endif