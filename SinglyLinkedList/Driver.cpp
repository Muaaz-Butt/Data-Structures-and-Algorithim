#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList list;
	list.insertNodeAtHead(11);
	list.insertNodeAtHead(10);
	list.insertNodeAtTail(12);
	//list.removeBefore(10);
	//list.removeAfter(10);
	//list.insertNodeAtSpecificIndex(1, 10);
	//list.insertNodeAtSpecificIndex(4, 1);
	//list.insertNodeAtSpecificIndex(5, 14);
	//list.insertNodeAtSpecificIndex(7, 16);
	//list.updateValueInNode(1, 13);
	//list.insertAfter(16, 17);
	//list.insertBefore(10, 9);
	//list.removeNodeAtHead();
	//list.removeNodeAtTail();
	list.displayLinkedList();
	//cout << list.searchNode(16) << "\n";
}