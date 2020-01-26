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
   
    //Automatic testing and user interaction testing
    int counter =0;
    std::cout << "Testing hashes from file...\n";
    while(counter < 10)
    {
        if(counter == 0)
        {
            userID = "SMITH";
            password = "qrnbskjyx";
        }

        if(counter == 1)
        {
            userID = "JOHNSON";
            password = "ftxwwxqts";
        }

        if(counter == 2)
        {
            userID = "WILLIAMS";
            password = "gndswrben";
        }

        if(counter == 3)
        {
            userID = "JONES";
            password = "konekfoyp";
        }

        
        if(counter == 4)
        {
            userID = "BROWN";
            password = "gcbuojpre";
        }

        if(counter == 5)
        {
            userID = "DAVIS";
            password = "oyiataiea";
        }

        if(counter == 6)
        {
            std::cout << "Now testing false results...\n";
            userID = "SMITH";
            password = "password";
        }

        if(counter == 7)
        {
            std::cout << "Now testing false results...\n";
            userID = "JOHNSON";
            password = "password";
        }

        if(counter == 8)
        {
            std::cout << "Now testing false results...\n";
            userID = "WILLIAMS";
            password = "password";
        }

        if(counter == 9)
        {
            std::cout << "Now testing false results...\n";
            userID = "JONES";
            password = "password";
        }

         if(counter == 10)
        {
            std::cout << "Now testing false results...\n";
            userID = "DAVIS";
            password = "password";
        }




        Encrypter* autoF = new Encrypter(userID);
        autoF->setPassword(password);
        autoF->encryptPassword();
        password = autoF->getPassword();
        int sum = autoF->getSumOfUserID();

        int hashKey = sum % 90000;
        
        autoF = nullptr;
        if(hashTable[hashKey] != nullptr)
        {
            autoF = hashTable[hashKey]->search(userID,password);
        }
        
        if(autoF == nullptr)
        {
            std::cout << "UserID: " << userID << " Password: " << password <<" Not found\n";
        }
        else
        {
            std::cout << "UserID: " << userID << " Password: " << password <<" Found!\n";
        }
        counter++;
    }

    while(userID != "q")
    {
        
        std::cout << "Please enter UserID you wish to search for or q to quit: ";
        std::cin >> userID;
    
        if(userID == "q") break;
        std::cout << "Please enter password (the ones above are encrypted, you'll need to use the raw.txt): ";
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

