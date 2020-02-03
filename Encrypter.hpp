#ifndef ENCRYPTER_HPP_
#define ENCRYPTER_HPP_

#include <iostream>
#include <sstream>
#include <time.h>

/*
************************************************************************************************
Austyn Washington 2/2/20. The encrypter class functionalities are: Storing/hosting the UserID and Password,
encrypts the password stored, also gets the sum of the ascii values of the UserID to help in the hashkey placements 
in main.

************************************************************************************************
*/

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