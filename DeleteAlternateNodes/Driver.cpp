#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList list1;
	list1.insertNodeAtHead(3);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(1);
	list1.insertNodeAtHead(0);
	list1.deleteAlternateNodes();
	list1.displayLinkedList();
}