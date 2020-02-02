#include "fileMakerAndReader.hpp"

fileMakerAndReader::fileMakerAndReader()
{
   
}

Encrypter* fileMakerAndReader::objectMaker(std::string filename)
{
    //first read in lastnamees and create the objects of Encry
    std::fstream file;
    filename = fileName; 
    std::string lastName;
    std::string contents;
    std::string str;
    std::string info;

    if(!file.is_open())
    {
        file.open(fileName.c_str());
        //std::cout << "opened";
    }

    if(file.eof())
    {
        //std::cout << "eof";
        file.close();
    }
//This parses for a single line in the file, main will be holding a loop for all 8800 names 
    for(int i=0; i < 1; i++)
    {
        std::getline(file, str);
        contents = str;
        
        if(i == 0)
        {
            info = contents;
            std::istringstream ss(info);
            ss >> lastName;
            //std::cout << lastName << "\n";
        }
    }

    Encrypter* encrypt = new Encrypter(lastName);
    return encrypt;
    //delete encrypt;
}

void fileMakerAndReader::textMaker()
{
    //creates file 
    std::fstream file;
    std::ofstream fout;
    std::fstream encryptTxt;
    std::ofstream foutEncrypt;

    Encrypter* encrypt;
    if(!file.is_open())
    {
        file.open(fileName.c_str());
        //std::cout << "opened";
    }
    fout.open("raw.txt",std::ios::out);
    foutEncrypt.open("encrypted.txt",std::ios::out);

    int i=0;
    while(i < 88799)
    {
        encrypt = objectMaker("lastnames.txt");
        fout << encrypt->getUserID() << "\n" << encrypt->getPassword() << "\n";

        encrypt->encryptPassword();
        foutEncrypt << encrypt->getUserID() << "\n" << encrypt->getPassword() << "\n";
        i++;
    }

    while(i < 88799)
    {
        encrypt = objectMaker("raw.txt");
        encrypt->encryptPassword();
        foutEncrypt << encrypt->getUserID() << "\n" << encrypt->getPassword() << "\n";
    }
    fout.close();
    file.close();
}

Encrypter* fileMakerAndReader::encryptionReader()
{
    std::ifstream fileZ;
    std::string fileNameZ = "encrypted.txt";
    std::string userID;
    std::string password;
    std::string contents;
    std::string str;
    std::string info;

    if(!fileZ.is_open())
    {
        fileZ.open(fileNameZ.c_str());
        //std::cout << "opened";
    }

    if(fileZ.eof())
    {
        std::cout << "eof";
        fileZ.close();
    }
//This parses for a single line in the file, main will be holding a loop for all 8800 names 
    for(int i=0; i < 1; i++)
    {
        std::getline(fileZ, str);
        contents = str;
        
        if(i == 0)
        {
            info = contents;
            std::istringstream ss(info);
            ss >> userID;
            //std::cout << userID << "\n";
        }

        if(i == 1)
        {
            info = contents;
            std::istringstream ss(info);
            ss >> password;
        }

    }

    Encrypter* encrypt = new Encrypter();
    encrypt->setUserID(userID);
    encrypt->setPassword(password);
    return encrypt;
    //delete encrypt;
}

//Try to make this with recursion next time instead of having a dedicated stack
Stack* fileMakerAndReader::objectMaker2(std::string filename,  Encrypter* (&enArray)[88799])
{
    
    std::fstream file;
    std::string userID;
    Stack* stack = new Stack();

    int i = 1;
    int j = 0;
    file.open(filename.c_str());
    Encrypter* object;
    std::string password = "";
    if(filename == "lastNames.txt")
    {
        while (file >> userID)
        {
            if(i == 1 )
            {
                //std::cout << userID << std::endl;

                Encrypter* object = new Encrypter(userID);
            
            // std::cout << object->getUserID() << "\n";
                stack->push(object);
                enArray[j] = object;
                j++;
            }

            if(i == 2)
            {
            // std::cout << userID << "2nd\n";
            }

            if(i == 3)
            {
                //std::cout << userID << "3rd\n";
            }

            if(i == 4)
            {
            //  std::cout << userID << "4th\n";
                i=0;
            }

            /* if(i == 3)
            {
                std::cout << "3rd \n";
                i = 0;
            } */
            i++;
        }
       //  std::cout << j << std::endl;
        //file.close();
    }
    
    else
    {
        j = 0;
        while (file >> userID >> password)
        {
                
                object = new Encrypter(userID);
                object->setPassword(password);

              // std::cout << userID << std::endl;
               // std::cout << password << std::endl;
            
                //std::cout << object->getUserID() << "\n";
                //std::cout << password << std::endl;
                //stack->push(object);
                enArray[j] = object;
                j++;
        }
    if(filename == "encrypted.txt")
    {
          //  std::cout << j << std::endl;

    }

           // file >>userID << password;
        
           // 
        

    }
    return stack;
}

void fileMakerAndReader::textMaker2(std::string filename,Encrypter* (&enArray)[88799])
{
    std::fstream file;
    std::ofstream fout;

    fout.open(filename,std::ios::out);
    //foutEncrypt.open("encrypted.txt",std::ios::out);

    if(filename == "raw.txt")
    {
        int i=0;
        while(i < 88799)
        {
        
            fout << enArray[i]->getUserID() << " " << enArray[i]->getPassword() << "\n";
            i++;
        }
    }

    if(filename == "encrypted.txt")
    {
        int i=0;
        while(i < 88799)
        {
            enArray[i]->encryptPassword();
            fout << enArray[i]->getUserID() << " " << enArray[i]->getPassword() << "\n";
            i++;
        }
    }
    

    
    //std::cout << enArray[1]->getUserID() << std::endl;
    fout.close();
}