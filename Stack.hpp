#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
#include <sstream>
#include "Node.hpp"

class Stack {

    private:
        Node* head;
        Node* tail;
        bool isEmptyCheck;
        int counter = 0;

    public:
        Stack();
        bool isEmpty();
        void push(Encrypter* encrypt);
        Encrypter* pop();
        Encrypter* search(std::string userID, std::string password);
};
#endif