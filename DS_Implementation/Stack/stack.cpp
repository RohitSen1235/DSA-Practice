#include "stack.h"

void Stack::push(int val)
{
    Node* currentNode =top;
    Node* newNode =new Node(val);
    
    newNode->prev=currentNode;
    
    top=newNode;
}

void Stack::pop()
{
    Node* currentNode =top;

    if(currentNode->prev!=nullptr)
    {
        top=currentNode->prev;
        currentNode->prev=nullptr;
    }

    else{
        std::cout<<"Stack is Empty, cannot pop"<<std::endl;
        return;
    }

}

void Stack::display()
{
    Node* currentNode=top;

    while(currentNode->prev!= nullptr)
    {
        std::cout<<currentNode->value<<" | ";
        currentNode=currentNode->prev;
    }
    std::cout<<"null"<<std::endl;
}