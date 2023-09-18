#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList list1;
	list1.insertNodeAtHead(4);
	list1.insertNodeAtHead(3);
	list1.insertNodeAtHead(1);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(1);
	list1.insertNodeAtHead(3);
	list1.insertNodeAtHead(7);
	list1.insertNodeAtHead(9);
	list1.insertNodeAtHead(19);
	list1.insertNodeAtHead(7);
	list1.sortLinkedList();
	list1.displayLinkedList();
}
