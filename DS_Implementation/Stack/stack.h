#include <iostream>

struct Node
{
    int value;
    Node* prev;

    Node(){}

    Node(int val):value(val),prev(nullptr){}

    ~Node(){}

};

class Stack
{
    Node* top;

public:

    Stack()
    {
        top =new Node(0);
    }
    ~Stack(){}

    void push(int );
    void pop();
    void display();
};

