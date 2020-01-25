#ifndef ENCRYPTER_HPP_
#define ENCRYPTER_HPP_

#include <iostream>
#include <sstream>
#include <time.h>

class Encrypter
{
    private:
    std::string userID;
    std::string password;
    std::string savedPassword;
    int sumOfUserID =0;

    public:
    Encrypter();
    Encrypter(std::string userID); //generate the password when taking in the userID
    void generatePassword();
    void setUserID(std::string userID);
    void setPassword(std::string password);
    std::string getUserID();
    std::string getPassword();
    void encryptPassword();
    int getSumOfUserID();
};
#endif