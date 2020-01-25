#include <iostream>
#include <sstream>
#include <string>
#include "Encrypter.hpp"
#include "Stack.hpp"
#include "fileMakerAndReader.hpp"
#include "Node.hpp"

int main()
{
    Stack** hashTable;
    hashTable = new Stack*[90000];

    for(int i=0; i < 90000; i++)
    {
        hashTable[i] = nullptr;
    }


}
