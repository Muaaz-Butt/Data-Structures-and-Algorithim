#pragma once
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "Node.h"

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	void insertNodeAtHead(int value);
	void insertNodeAtTail(int value);
	bool insertNodeAtSpecificIndex(int index, int value);
	int searchNode(int value);
	bool updateValueInNode(int prevValue, int updatedValue);
	bool insertAfter(int key, int value);
	bool insertBefore(int key, int value);
	void removeNodeAtHead();
	void removeNodeAtTail();
	bool deleteNode(int value);
	bool removeAfter(int key);
	bool removeBefore(int key);
	void displayLinkedList();
};

#endif // !SINGLYLINKEDLIST_H
