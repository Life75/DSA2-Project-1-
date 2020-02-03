#include <iostream>
#include <sstream>
#include <string>
#include "Encrypter.hpp"
#include "Stack.hpp"
#include "fileMakerAndReader.hpp"
#include "Node.hpp"
/*
************************************************************************************************
Austyn Washington 2/2/20: The Main has been revised and reworked to operate with the reworkings of
FileMakerAndReader class. The main creates 2 dynamic arrays, one for the objects passing through by 
reference stated in FileMakerAndReader and the second is the actual hash table. The hash key is based 
off the ascii values sum of the UserID’s mod table size. The objects are placed into the table. After that 
portion searches through the first file contents in raw.txt and tried to find them in the table and stack 
through the search functionality implemented in Stack class based on UserID and Password.
************************************************************************************************
*/
int main()
{
    std::ifstream file;
    fileMakerAndReader creator;
    Encrypter* ae;
    int amountOfObjects = 88799;
    int size = 90000;

    Encrypter* enArray[88799];
    //enArray = new Encrypter[88799];
    for(int i=0; i < 88799; i++)
    {
        enArray[i] = new Encrypter();
    }

    creator.objectMaker2("lastNames.txt", enArray);
    creator.textMaker2("raw.txt", enArray);
    creator.objectMaker2("raw.txt", enArray);
    creator.textMaker2("encrypted.txt", enArray);
    
    
    int collisions = 0;
    int placed =0;

  
    Stack** hashTable;
    hashTable = new Stack*[size];

    for(int i=0; i < size; i++)
    {
        hashTable[i] = nullptr;
    }

    //placing hash stuff
    int i =0;
    while(i < amountOfObjects)
    {
        
        
        
        //encrypt->encryptPassword();
        //std::cout << "reached\n";
            
        
        int hashKey = enArray[i]->getSumOfUserID() % size;
        //std::cout << enArray[i]->getUserID() << std::endl;
        
        if(hashTable[hashKey] == nullptr)
        {
            hashTable[hashKey] = new Stack;
            hashTable[hashKey]->push(enArray[i]);
            

           // std::cout << hashKey << "\n";
            placed++;
        }

        else
        {
            hashTable[hashKey]->push(enArray[i]);
            placed++;
            collisions++;
        }
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
    //std::cout << "hashes placed: " << placed << "\n";
    //std::cout << "collisions: " << collisions << "\n";

/*
    int amount = 0;
    //Testing placements 
    j =0;
    while(j < size)
    {
        if(hashTable[j] != nullptr)
        {
            amount++;
            std::cout << j << "\n"; 
        }
        j++;
    }
  */
    std::cout << "Legal:" << std::endl;
    std::cout << "Userid    Password    Result" << std::endl;
    creator.objectMaker2("raw.txt", enArray);
    std::string userID = "";
    std::string password ="";
    std::string encrypted ="";
    int testing = 5;
    j=0;
    while(j < testing)
    {
       
        userID = enArray[j]->getUserID();
        password = enArray[j]->getPassword();
        Encrypter* example = new Encrypter(userID); 
        example->setPassword(password);
        example->encryptPassword();
        encrypted = example->getPassword();
        int hashKey = 0;
         hashKey = enArray[j]->getSumOfUserID() % size;

        if(hashTable[hashKey] != nullptr)
        {
           // std::cout << userID << password << "\n";
            example = hashTable[hashKey]->search(userID,encrypted);
            //std::cout << example->getUserID();
           /* 
            while(!hashTable[hashKey]->isEmpty())
            {
                example = hashTable[hashKey]->pop();
              //  if(example ==)
            }*/
         
        }
        else
        {
            std::cout << "Not Found\n";
        }

        if(example != nullptr) std::cout << userID << "   " << password << "   " << "match" << std::endl;
      
        j++;
    }

    std::cout << "\n";
    std::cout << "Illegal:" << std::endl;
    std::cout << "Userid    Password    Result" << std::endl;
    j=0;
    while(j < testing)
    {
        userID = enArray[j]->getUserID();
        password = enArray[j]->getPassword();
        Encrypter* example = new Encrypter(userID); 
        example->setPassword(password);
        example->encryptPassword();
        encrypted = example->getPassword();

        password.at(0) = 'x';
       //std::cout << password << "\n";
        int hashKey = 0;
         hashKey = enArray[j]->getSumOfUserID() % size;

        if(hashTable[hashKey] != nullptr)
        {
           // std::cout << userID << password << "\n";
            example = hashTable[hashKey]->search(userID,encrypted);
            //std::cout << example->getUserID();
           /* 
            while(!hashTable[hashKey]->isEmpty())
            {
                example = hashTable[hashKey]->pop();
              //  if(example ==)
            }*/
         
        }
        else
        {
            std::cout << "Not Found\n";
        }
        
        if(example != nullptr) std::cout << userID << "   " << password << "   " << "match" << std::endl;
        else std::cout << userID << "   " << password << "   " << "no match" << std::endl;
      
        j++;
    }








/*
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
        
    }*/
    
}

