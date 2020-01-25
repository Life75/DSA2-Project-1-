#include "Node.hpp"

Node::Node(Encrypter* encrypt, Node* next)
{
    this->encrypt = encrypt;
    this->next = next;
}

Encrypter* Node::getValue()
{
    return this->encrypt;
}

Node* Node::getNext()
{
    return this->next;
}

void Node::setNext(Node* newNext)
{
    this->next = newNext;
}