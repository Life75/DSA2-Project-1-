#include "Stack.hpp"

Stack::Stack()
{
    this->head = nullptr;
    this->tail = nullptr;
    isEmptyCheck = true;
}

void Stack::push(Encrypter* encrypt)
{
    Node* newNode = new Node(encrypt, this->head);
    this->head = newNode;
    isEmptyCheck = false;
}

bool Stack::isEmpty()
{
    return this->head == nullptr;
}

Encrypter* Stack::pop()
{
    Encrypter* result;
    
    if(this->head != nullptr)
    {
        Node* end = this->head;
        this->head = this->head->getNext();
        result = end->getValue();
        delete end;
       // isEmptyCheck = true;
    }
    return result;
}

Encrypter* Stack::search(std::string userID, std::string password)
{
    Encrypter* result;
    Node* currentNode = this->head;
    
    while(currentNode != nullptr)
    {
        if(currentNode->getValue()->getUserID() == userID)
        {
            if(currentNode->getValue()->getPassword() == password)
            {
                return currentNode->getValue();
            }
            else return nullptr;
            
        }
        else currentNode = currentNode->getNext();
    }
    return nullptr;
    

}