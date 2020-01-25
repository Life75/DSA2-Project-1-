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
    Encrypter* encrypt;
    int collisions = 0;

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
        
        if(i == 0)
        {
           encrypt = creator.objectMaker();
           std::cout << "reached\n";
            
        }
        int hashKey = encrypt->getSumOfUserID() % 90000;
        
        if(hashTable[hashKey] == nullptr)
        {
            hashTable[hashKey] = new Stack;
            hashTable[hashKey]->push(encrypt);
            std::cout << hashKey << "\n";
        }

        if(hashTable[hashKey] != nullptr)
        {
            hashTable[hashKey]->push(encrypt);
            collisions++;
        }
        //std::cout << creator.objectMaker()->getUserID();
        //std::cout << creator.objectMaker()->getUserID() << "\n";
        //creator.objectMaker()->encryptPassword();
        //std::cout << creator.objectMaker()->getUserID();
        //std::cout << creator.objectMaker()->getPassword() << "\n";
        i++;
    }

    int placed =0;
    int j = 0;
    while(j < 88799)
    {
        if(hashTable[j] != nullptr)
        {
            placed++;
        }
        j++;
    }
    std::cout << "hashes placed: " << placed << "\n";
    std::cout << "collisions: " << collisions << "\n";
}

