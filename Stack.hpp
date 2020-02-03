#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
#include <sstream>
#include "Node.hpp"

/*
************************************************************************************************
Austyn Washington 2/2/20; Creates stack functionalities needed in making the external hash table. 
One of the anomalies is the search functionality. It goes through the nodes searching for the particular 
object in the stack based on the UserID and Password. It will return that object once found, if not then
it will return nullptr. 
************************************************************************************************
*/
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