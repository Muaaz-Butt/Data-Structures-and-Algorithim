#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DNode.h"

class DoublyLinkedList {
private:
	DNode* head;
	DNode* tail;
public:
	DoublyLinkedList();
	bool isEmpty();
	bool searchValueInLinkedList(int value);
	void insertAtHead(int value);
	void insertAtTail(int value);
	void insertAfter(int key, int value);
	void insertBefore(int key, int value);
	void updateValue(int prevValue, int updatedValue);
	void removeAtHead();
	void removeAtTail();
	void removeNode(int key);
	void removeAfter(int key);
	void removeBefore(int key);
	void reverseDisplay();
	void reverseList();
	void sortList();
	void display();
};

#endif // !DOUBLYLINKEDLIST_H
