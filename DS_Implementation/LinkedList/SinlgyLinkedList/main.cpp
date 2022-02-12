#include "SinglyLinkedList.h"


int main()
{
	SinglyLinkedList list(1);
	list.Display();
	list.insertAtTail(2);
	list.Display();
	list.insertAtTail(5);
	list.Display();
	list.insertAtHead(45);
	list.Display();
	list.insertAtTail(7);
	list.Display();
	list.insertAtTail(22);
	list.Display();

	/*int n = 22;
	int a=list.SearchList(n);
	std::cout <<"found "<<n<<" @ index: " << a << std::endl;
	std::cout <<"Size of List : " << sizeof(list) << std::endl;*/

	list.deleteNode(0);
	list.Display();
	list.insertAtPosition(2,458);
	list.Display();
	list.insertAtPosition(0,558);
	list.Display();
	list.deleteNode(4);
	list.Display();

	//std::cin.get();
	return 0;
}