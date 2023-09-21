#pragma once
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "Node.h"

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList();                                                  //Default constructor
	void insertNodeAtHead(int value);                                    //Insert Node at the start of linked list
	void insertNodeAtTail(int value);                                    //Insert node at the end of the list
	void removeDuplicateNodesInLinkedList();                             //Remove duplicate nodes in linked list
	void sortLinkedList();                                               //Sort the linked list
	void displayLinkedList();                                            //Prints Linked list on console
};

#endif // !SINGLYLINKEDLIST_H
