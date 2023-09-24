#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
	DoublyLinkedList l1;
	l1.insertAtTail(3);
	l1.insertAtTail(2);
	l1.insertAtTail(1);
	l1.insertAtTail(4);
	l1.sortList();
	//l1.reverseList();
	//l1.reverseDisplay();
	//l1.removeBefore(5);
	//l1.removeNode(4);
	//l1.removeAtTail();
	//l1.updateValue(3, 5);
	//l1.insertBefore(4,5);
	l1.display();

	return 0;
}