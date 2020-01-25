#ifndef NODE_HPP_
#define NODE_HPP_

#include "Encrypter.hpp"
#include <iostream>

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