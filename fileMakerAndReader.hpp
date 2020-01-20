#ifndef FILEMAKERANDREADER_HPP_
#define FILEMAKERANDREADER_HPP_

#include "Encrypter.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class fileMakerAndReader
{
    private:
    std::ifstream file;

    public:
    fileMakerAndReader();
    //change to Node data type so it can make objects and place them inside the hash 
    Encrypter* rawTextMaker();
    
    
};
#endif
