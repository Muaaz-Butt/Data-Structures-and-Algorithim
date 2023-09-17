#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

void SinglyLinkedList::insertNodeAtHead(int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

void SinglyLinkedList::deleteAlternateNodes() {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	Node* temp = head;
	Node* p = nullptr;
	while (temp != nullptr && temp->next != nullptr) {
		p = temp->next->next;
		delete temp->next;
		temp->next = p;
		temp = temp->next;
	}
}

void SinglyLinkedList::displayLinkedList() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}
