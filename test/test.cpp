#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../Encrypter.hpp"
#include "../fileMakerAndReader.hpp"
//#include "../Node.hpp"
//#include "../Stack.hpp"
//#include "../HashStorage.hpp"

TEST_CASE("class Encrypter")
{
    //Test out the encryption process
    //std::string name = "Washington";
    Encrypter ae("Washington");
    REQUIRE(ae.getUserID() == "Washington");
    ae.generatePassword();
    std::cout << ae.getPassword() << "\n";
}

TEST_CASE("class fileMakerAndReader")
{
    fileMakerAndReader raw;
   // Encrypter* userOne;
   // Encrypter* userTwo;
    Encrypter* example;
    /*
    //reads the lastnames.txt and creates a file with the userIDs and passwords
    userOne = raw.rawTextMaker();
    REQUIRE("SMITH" == userOne->getUserID());
    std::cout << userOne->getPassword();

    userTwo = raw.rawTextMaker();
    REQUIRE(userOne->getUserID() != userTwo->getUserID());
    REQUIRE(userOne->getPassword() != userTwo->getPassword());
    */
    std::string passwordOne = "";
    std::string passwordTwo = "";
    int i = 0;
    while(i < 2)
    {
        example = raw.rawTextMaker();
        
        if(i == 0)
        {
            REQUIRE("SMITH" == example->getUserID());
            passwordOne = example->getPassword();
        }
        example->generatePassword();
       
        if(i == 1)
        {
            REQUIRE("JOHNSON" == example->getUserID()); 
            passwordTwo = example->getPassword();
        }
        i++;
    }
    REQUIRE(passwordOne != passwordTwo);
    
}