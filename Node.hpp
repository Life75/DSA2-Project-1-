#ifndef NODE_HPP_
#define NODE_HPP_

#include "Encrypter.hpp"
#include <iostream>


/*
************************************************************************************************
Node Banter: 
Austyn Washington 2/2/20: Simply creates node usage for the Stack usage 
************************************************************************************************
*/
class Node
{
    private:
        Encrypter* encrypt;
        Node* next = nullptr;

    public: 
        Node(Encrypter* encrypt, Node* next = nullptr);
        Encrypter* getValue();
        Node* getNext();
        void setNext(Node* newNext);
};
#endif