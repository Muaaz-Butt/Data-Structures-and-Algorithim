#include <iostream>
#include "List.h"

using namespace std;

int main() {
	SinglyLinkedList list1, list2;
	list1.insertNodeAtHead(1);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(3);
	list2.insertNodeAtHead(1);
	list2.insertNodeAtHead(2);
	list2.insertNodeAtHead(3);
	list2.insertNodeAtHead(4);
	cout << list1.isEqual(list2);
}
