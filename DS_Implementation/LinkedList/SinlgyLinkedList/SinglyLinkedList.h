#pragma once
#include <iostream>

struct Node
{
	int _value;
	Node* _next;

	Node(){
		std::cout<<"Node : Default Constructor Called"<<std::endl;
	}
	~Node(){
		std::cout<<"Node : Distructor Called"<<std::endl;
	}
	Node(int value)
	{
		this->_value = value;
		this->_next = nullptr;

		std::cout<<"Node : Constructor Called"<<std::endl;
	}
};

class SinglyLinkedList
{
private:
	Node* head;

public:
	SinglyLinkedList():head(nullptr)
	{
		std::cout<<"SingleLinkedList : Default Constructor Called"<<std::endl;
	}
	SinglyLinkedList(int value):head (new Node(value))
	{
		std::cout<<"SingleLinkedList : Constructor Called"<<std::endl;
	}
	~SinglyLinkedList(){
		std::cout<<"SingleLinkedList : Distructor Called"<<std::endl;
	}

	void insertAtTail(int);
	void insertAtHead(int);
	void insertAtPosition(unsigned, int);
	int deleteNode(unsigned);
	int SearchList(int);

	Node* reverse();
	
	void Display();
};
