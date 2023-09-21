#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList list1, list2, l;
	list1.insertNodeAtHead(4);
	list1.insertNodeAtHead(3);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(1);
	list1.removeDuplicateNodesInLinkedList();
	list1.displayLinkedList();
}

