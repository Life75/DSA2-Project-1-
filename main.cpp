#include <iostream>
#include <sstream>
#include <string>
#include "Encrypter.hpp"
#include "Stack.hpp"
#include "fileMakerAndReader.hpp"
#include "Node.hpp"

int main()
{
    std::ifstream file;
    fileMakerAndReader creator;
    creator.textMaker();
    Encrypter* encrypt;
    int collisions = 0;
    int placed =0;

    Stack** hashTable;
    hashTable = new Stack*[90000];

    for(int i=0; i < 90000; i++)
    {
        hashTable[i] = nullptr;
    }

    //placing hash stuff
    int i =0;
    while(i < 88799)
    {
        
      
        encrypt = creator.objectMaker();
        encrypt->encryptPassword();
        //std::cout << "reached\n";
            
        
        int hashKey = encrypt->getSumOfUserID() % 90000;
        
        if(hashTable[hashKey] == nullptr)
        {
            hashTable[hashKey] = new Stack;
            hashTable[hashKey]->push(encrypt);
            //std::cout << hashKey << "\n";
            placed++;
        }

        else
        {
            hashTable[hashKey]->push(encrypt);
            placed++;
            collisions++;
        }
        //std::cout << creator.objectMaker()->getUserID();
        //std::cout << creator.objectMaker()->getUserID() << "\n";
        //creator.objectMaker()->encryptPassword();
        //std::cout << creator.objectMaker()->getUserID();
        //std::cout << creator.objectMaker()->getPassword() << "\n";
        i++;
    }

    
    int j = 0;
    while(j < 88799)
    {
        if(hashTable[j] != nullptr)
        {
            //placed++;
        }
        j++;
    }
    std::cout << "hashes placed: " << placed << "\n";
    std::cout << "collisions: " << collisions << "\n";

    std::string userID = "default";
    std::string password ="";
   
    while(userID != "q")
    {
        
        std::cout << "Please enter UserID or q to quit: ";
        std::cin >> userID;
    
        if(userID == "q") break;
        std::cout << "Please enter password: ";
        std::cin >> password;

        Encrypter* finder = new Encrypter(userID);

        finder->setPassword(password);
        finder->encryptPassword();
        password = finder->getPassword();
        int sum = finder->getSumOfUserID();

        int hashKey = sum % 90000;
        
        finder = nullptr;

        if(hashTable[hashKey] != nullptr)
        {
            finder = hashTable[hashKey]->search(userID,password);
        }
        
        if(finder == nullptr)
        {
            std::cout << "Not found\n";
        }
        else
        {
            std::cout << "Found!\n";
        }
        
    }
    
}

