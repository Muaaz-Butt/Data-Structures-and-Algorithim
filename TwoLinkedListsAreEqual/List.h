#pragma once
#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList();
	void insertNodeAtHead(int value);
	bool isEqual(SinglyLinkedList& list);
	void displayLinkedList();
};

#endif // !SINGLYLINKEDLIST_H
