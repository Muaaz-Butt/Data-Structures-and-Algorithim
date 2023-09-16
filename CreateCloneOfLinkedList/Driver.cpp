#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList list1, list2, l;
	list1.insertNodeAtHead(3);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(1);
	list2.insertNodeAtHead(1);
	list2.insertNodeAtHead(2);
	list2.insertNodeAtHead(3);
	list2.insertNodeAtHead(4);
	l = list2.createClone();
	l.displayLinkedList();
}