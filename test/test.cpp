#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../Encrypter.hpp"
//#include "../Node.hpp"
//#include "../Stack.hpp"
//#include "../HashStorage.hpp"

TEST_CASE("class Encrypter")
{
    //Test out the encryption process
    //std::string name = "Washington";
    Encrypter ae("Washington");
    REQUIRE(ae.getUserID() == "Washington");
    //ae.getPassword(); 
}