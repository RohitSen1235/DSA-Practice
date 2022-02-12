
#include "SinglyLinkedList.h"

void SinglyLinkedList::insertAtHead(int value)
{
	Node* newNode = new Node(value);

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	newNode->_next = head;
	head = newNode;

}

void SinglyLinkedList::insertAtTail(int value)
{
	Node* newNode = new Node(value);
	Node* currentNode = head;
	if (currentNode == nullptr)
	{
		currentNode = newNode;
		return;
	}
	while (currentNode->_next != nullptr)
	{
		currentNode = currentNode->_next;
	}
	currentNode->_next = newNode;

}

void SinglyLinkedList::insertAtPosition(unsigned index,int value)
{
	
	int count=0;
	if(index==0)
	{
		insertAtHead(value);
		return;
	}

	Node* currentNode = head;

	while(currentNode->_next!=nullptr)
	{
		
		if(count==index-1)
		{
			break;
		}
		currentNode=currentNode->_next;
		++count;
	}
	if(count<index-1)
	{
		std::cout<<"Index Out of Range,could not insert!!"<<std::endl;
		return;
	}
	Node* newNode =new Node(value);
	newNode->_next=currentNode->_next;
	currentNode->_next=newNode;

}

int SinglyLinkedList::deleteNode(unsigned  index)
{
	Node* currentNode = head;
	if (index == 0)
	{
		head = currentNode->_next;
		currentNode->_next = nullptr;
		delete currentNode;
		return 0;
	}

	Node* temp;
	unsigned _index = 0;
	
	while (currentNode->_next != nullptr)
	{
		if (_index == index-1)
		{
			temp = currentNode->_next;
			currentNode->_next = temp->_next;
			temp->_next = nullptr;
			delete temp;
			return 0;
		}
		currentNode = currentNode->_next;
		_index++;
	}
	
	return -1;
}
int SinglyLinkedList::SearchList(int value)
{
	Node* currentNode = head;
	int index = 0;
	while (currentNode != nullptr)
	{
		if (currentNode->_value == value)
		{
			return index;
		}
		currentNode = currentNode->_next;
		index++;
	}
	return -1;
}

void SinglyLinkedList::Display()
{
	Node* currentNode = head;

	while (currentNode != nullptr)
	{
		std::cout << currentNode->_value << "->";
		currentNode = currentNode->_next;
	}
	std::cout << "null" << std::endl;
}