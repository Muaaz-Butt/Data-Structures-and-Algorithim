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
	void insertNodeAtTail(int value);
	int noOfNodesInLinkedList();
	void splitList(SinglyLinkedList& list1, SinglyLinkedList& list2);
	void displayLinkedList();
};

#endif // !SINGLYLINKEDLIST_H
