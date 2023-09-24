#pragma once
#ifndef CIRCULARLINNKEDLIST_H
#define CIRCULARLINNKEDLIST_H

#include "Node.h"

class CircularLinkedList {
private:
	Node* head;
	Node* tail;
public:
	CircularLinkedList();
	void insertAtHead(int value);
	void insertAtTail(int value);
	void insertAfter(int key, int value);
	void insertBefore(int key, int value);
	void updateValue(int prevValue, int updatedValue);
	void removeAtHead();
	void removeAtTail();
	bool removeNode(int key);
	bool removeAfter(int key);
	bool removeBefore(int key);
	void reverseList();
	void display();
};

#endif // ! CIRCULARLINNKEDLIST_H
