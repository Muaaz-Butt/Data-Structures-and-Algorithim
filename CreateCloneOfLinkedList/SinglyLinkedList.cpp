#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

void SinglyLinkedList::insertNodeAtHead(int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

void SinglyLinkedList::insertNodeAtTail(int value) {
	Node* newNode = new Node(value);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

SinglyLinkedList SinglyLinkedList::createClone() {
	SinglyLinkedList clone;
	Node* temp = head;
	while (temp != nullptr) {
		clone.insertNodeAtTail(temp->data);
		temp = temp->next;
	}
	return clone;
}

void SinglyLinkedList::displayLinkedList() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}
