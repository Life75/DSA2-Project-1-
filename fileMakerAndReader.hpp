#ifndef FILEMAKERANDREADER_HPP_
#define FILEMAKERANDREADER_HPP_

#include "Encrypter.hpp"
#include "Stack.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

/*
************************************************************************************************
Austyn Washington 2/2/20. The FileMakerAndReader has been revised and reworked to operate more 
effective and able to be dynamic enough for multiple different file usage explaining the objectMaker2() 
and textMaker2(). FileMakerAndReader main functionalities are to read in the files and place the data in an array 
and create the files from the array from multiple references. ObjectMaker2() creates the objects based from the files, 
it takes in an array as well and does array of references allowing no need for returning anything with the objects being 
made as encrypter objects and placed into the array. TextMaker2() creates the text files from the objects taken in the array
and creates the file with the name given. 
************************************************************************************************
*/

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
