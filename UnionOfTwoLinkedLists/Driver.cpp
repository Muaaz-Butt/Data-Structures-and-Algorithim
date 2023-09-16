#include <iostream>
#include "SinglyList.h"

using namespace std;

int main() {
	SinglyLinkedList list1, list2;

	list1.insertNodeAtHead(1);
	list1.insertNodeAtHead(2);
	list1.insertNodeAtHead(3);
	list2.insertNodeAtHead(4);
	list2.insertNodeAtHead(5);
	list2.insertNodeAtHead(6);
	SinglyLinkedList l3 = list1.unionOfTwoLinkedLists(list2);
	l3.displayLinkedList();
}
