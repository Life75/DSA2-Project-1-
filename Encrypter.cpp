#include "Encrypter.hpp"




Encrypter::Encrypter()
{
    userID = "";
    password = "";
}

Encrypter::Encrypter(std::string userID)
{
    this->userID = userID;
    this->password = "";
    
    int i = 0;
    int j = 0;
    //generate a random password full of small characters, needs to be 9 characters lowercase 
    char character[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    int userIDLength = 0;
    userIDLength = userID.size();

   
    while(j < userIDLength)
    {
        char c;
        c = userID.at(j);
        sumOfUserID += int(c);
        j++;
    }
    srand(sumOfUserID); // makes random numbers for every run
    while(i < 9)
    {
       //random num generator  
       int randomNum = (rand() % 25) + 0;
       password += character[randomNum];
       i++; 
    }
   
   // std::cout << password << "\n";

}

void Encrypter::generatePassword()
{
    this->password = "";
    int i = 0;
    //generate a random password full of small characters, needs to be 9 characters lowercase 
    char character[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    srand((unsigned)time (0)); // makes random numbers for every run
    while(i < 9)
    {
       //random num generator  
       int randomNum = (rand() % 15) + 0;
       password += character[randomNum];
       i++; 
    }
}


void Encrypter::setPassword(std::string password)
{
    this->password = password;
}

void Encrypter::setUserID(std::string userID)
{
    this->userID = userID;
}

std::string Encrypter::getUserID()
{
    return userID;
}

std::string Encrypter::getPassword()
{
    return password;
}

int Encrypter::getSumOfUserID()
{
    return sumOfUserID;
}
void Encrypter::encryptPassword()
{
    std::string encryption ="";
    std::ostringstream oss;
    int i=0;
    int counter =0;
    int change = 0;
    savedPassword = password;

    
    while(i < password.size())
    {
        counter++;
        char c;
        char aChar;
        change = 0;
        c = password.at(i);

        if(counter == 1)
        {
            if(int(c) < 114)
            {
                change = int(c) + 9;
            }  
    
            else
            {
                change = int(c) - 17;
            }
            //std::cout << int(c) << "\n";
            //std::cout << change << "\n"; 


            aChar = change;
            oss << aChar;
        }

        if(counter == 2)
        {
            if(int(c) < 109)
            {
                change = int(c) + 14;
            }

            else
            {
                change = int(c) - 12;
            }
            //std::cout << int(c) << "\n";
           // std::cout << change << "\n"; 


            aChar = change;
            oss << aChar;
        }
        
        if(counter == 3)
        {
            if(int(c) < 110)
            {
                change = int(c) + 13;
            }
            
            else
            {
                change = int(c) - 13;
            }

            aChar = change;
            oss << aChar;
        }

        if(counter == 4)
        {
            if(int(c) < 119)
            {
                change = int(c) + 4;
            }
            else
            {
                change = int(c) - 22;
            }

            aChar = change;
            oss << aChar;
        }

        if(counter == 5)
        {
            if(int(c) < 105)
            {
                change = int(c) + 18;
            }
            else
            {
                change = int(c) - 8;
            }

            aChar = change;
            oss << aChar;
            counter = 0;
        }
        i++;
    }
    password = oss.str();
}