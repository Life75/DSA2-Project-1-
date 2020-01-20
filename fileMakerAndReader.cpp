#include "fileMakerAndReader.hpp"

fileMakerAndReader::fileMakerAndReader()
{

}

Encrypter* fileMakerAndReader::rawTextMaker()
{
    //first read in lastnamees and create the objects of Encry
    std::string fileName = "lastNames.txt";
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
        std::cout << "eof";
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