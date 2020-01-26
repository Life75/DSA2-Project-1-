#include "fileMakerAndReader.hpp"

fileMakerAndReader::fileMakerAndReader()
{
   
}

Encrypter* fileMakerAndReader::objectMaker()
{
    //first read in lastnamees and create the objects of Encry
    
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
        encrypt = objectMaker();
        fout << encrypt->getUserID() << "\n" << encrypt->getPassword() << "\n";

        encrypt->encryptPassword();
        foutEncrypt << encrypt->getUserID() << "\n" << encrypt->getPassword() << "\n";
        i++;
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