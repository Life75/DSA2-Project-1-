#ifndef FILEMAKERANDREADER_HPP_
#define FILEMAKERANDREADER_HPP_

#include "Encrypter.hpp"
#include "Stack.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

class fileMakerAndReader
{
    private:
    //std::ifstream file;
    std::string fileName = "lastNames.txt";
    int variable = 1;

    public:
    fileMakerAndReader();
    //change to Node data type so it can make objects and place them inside the hash 
    Encrypter* objectMaker(std::string fileName);
    Stack* objectMaker2(std::string filename, Encrypter* (&enArray)[88799]);
    void textMaker();
    void textMaker2(std::string filename, Encrypter* (&enArray)[88799]);
    Encrypter* encryptionReader();
    
    
    
};
#endif
