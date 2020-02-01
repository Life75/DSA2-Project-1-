#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../Encrypter.hpp"
#include "../fileMakerAndReader.hpp"
#include "../Node.hpp"
#include "../Stack.hpp"
//#include "../HashStorage.hpp"

TEST_CASE("class Encrypter")
{
    //Test out the encryption process
    //std::string name = "Washington";
    Encrypter ae("Washington");
    REQUIRE(ae.getUserID() == "Washington");
    Encrypter ea("Washingtog");
    REQUIRE(ae.getPassword() != ea.getPassword());
    //std::cout << ae.getPassword() << "\n";

    //Encryption test 
    Encrypter test;
    test.setUserID("Cena");
    test.setPassword("raaaa");
    test.encryptPassword();
    REQUIRE(test.getPassword() == "aones");
    
    test.setPassword("zzzzz");
    test.encryptPassword();
    REQUIRE(test.getPassword() == "inmdr");

}

TEST_CASE("class fileMakerAndReader")
{
    fileMakerAndReader raw;
    fileMakerAndReader encryptReader;
   // Encrypter* userOne;
   // Encrypter* userTwo;
    Encrypter* example = new Encrypter();
    /*
    //reads the lastnames.txt and creates a file with the userIDs and passwords
    userOne = raw.rawTextMaker();
    REQUIRE("SMITH" == userOne->getUserID());
    std::cout << userOne->getPassword();

    userTwo = raw.rawTextMaker();
    REQUIRE(userOne->getUserID() != userTwo->getUserID());
    REQUIRE(userOne->getPassword() != userTwo->getPassword());
    */

   //Create an object called randomPasswordGenerator dedicated to generating random for the objects 
    //std::string passwordOne = "password";
   //std::string passwordTwo = "password";
    
    /*Passed testing need to get rid of it so it can properly 
    place all the data in file*/
    /*
    int i = 0;
    while(i < 2)
    {
        example = raw.objectMaker("lastNames.txt");
        //example->generatePassword();

        if(i == 0)
        {
            REQUIRE("SMITH" == example->getUserID());
          //  passwordOne = example->getPassword();
        }
       
       
        if(i == 1)
        {
            REQUIRE("JOHNSON" == example->getUserID()); 
            //passwordTwo = example->getPassword();
        }
        i++;
    }
   ///REQUIRE(passwordOne != passwordTwo); 
    */

    //creates raw.txt and creates encrypted.txt
    //raw.textMaker();
    Encrypter* enArray[88799];
    //enArray = new Encrypter[88799];
    for(int i=0; i < 88799; i++)
    {
        enArray[i] = new Encrypter();
    }
    raw.objectMaker2("lastNames.txt", enArray);
    //pass by reference an array

    REQUIRE(enArray[0]->getUserID() == "SMITH");
    REQUIRE(enArray[1]->getUserID() == "JOHNSON");

    raw.objectMaker2("raw.txt", enArray);



    /*This has a weird error if I function call within it to objectMaker2
    it won't read the file completely. README*/
    // raw.textMaker2("raw.txt", "encrypted.txt", enArray);
    

    
    //REQUIRE(enArray[0]->getUserID() == "SMITH");
    //REQUIRE(enArray[1]->getUserID() == "JOHNSON");

    
  // raw.textMaker();
/*
    encryptReader.encryptionReader();
   
    example = encryptReader.objectMaker("raw.txt");
    REQUIRE(example->getUserID() == "SMITH");
    
    int k =0;
    while(k < 2)
    {
        example = encryptReader.encryptionReader(); 
        std::cout << example->getUserID() << std::endl;
        k++;
    }
/*
    int i = 0;
    while(i < 2)
    {
        example = raw.encryptionReader();
        if(i == 0)
        {
            REQUIRE("SMITH" == example->getUserID());
           // passwordOne = example->getPassword();
        }
       
       
        if(i == 1)
        {
            REQUIRE("JOHNSON" == example->getUserID()); 
            //passwordTwo = example->getPassword();
        }
        i++;
    }*/

    //REQUIRE(example->getPassword == )
}

TEST_CASE("class Node")
{
    Encrypter* ex = new Encrypter();
    ex->setUserID("Washington");
    ex->setPassword("abcd");
    Node n(ex);
    REQUIRE(n.getValue()->getUserID() == "Washington");
    REQUIRE(n.getValue()->getPassword() == "abcd");
    REQUIRE(n.getNext() == nullptr);
}

TEST_CASE("class Stack")
{
    Stack s;
    Encrypter* ex = new Encrypter();
    Encrypter* xe = new Encrypter();
    Encrypter* dummy;
    Encrypter* dummy2;
    ex->setUserID("Washington");
    ex->setPassword("abcd");
    xe->setUserID("Austyn");
    xe->setPassword("password");
  
    s.push(ex);
    s.push(xe);

    
    REQUIRE(!s.isEmpty());

    //traversal
    dummy2 = s.search("Austyn", "password");
    REQUIRE(dummy2 != nullptr);
    
    dummy2 = s.search("Washington", "password");
    REQUIRE(dummy2 == nullptr);

    dummy2 = s.search("Washington", "abcd");
    REQUIRE(dummy2 != nullptr);

    dummy2 = s.search("nothing", "nothing");
    REQUIRE(dummy2 == nullptr);

    //pop 
    dummy = s.pop();
    REQUIRE(dummy->getUserID() == "Austyn");
    REQUIRE(dummy->getPassword() == "password");

    dummy = s.pop();
    REQUIRE(dummy->getUserID() == "Washington");
    REQUIRE(dummy->getPassword() == "abcd");


    
    REQUIRE(s.isEmpty());
}
