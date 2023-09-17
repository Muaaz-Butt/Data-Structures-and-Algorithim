#pragma once
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "Node.h"

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList();
	void insertNodeAtHead(int value);
	void deleteAlternateNodes();
	void displayLinkedList();
};

#endif // !SINGLYLINKEDLIST_H
