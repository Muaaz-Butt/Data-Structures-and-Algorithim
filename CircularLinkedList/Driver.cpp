#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main() 
{
	CircularLinkedList l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(7);
	l.insertAtTail(5);
	l.reverseList();
	//l.removeBefore(2);
	//l.updateValue(3, 5);
	//l.insertBefore(4, 5);
	l.display();
}
