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

void SinglyLinkedList::sortLinkedList() {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	int swap;
	Node* temp = head;
	Node* temp1 = head;
	while (temp->next != nullptr) {
		temp1 = temp->next;
		while (temp1 != nullptr) {
			if (temp->data > temp1->data) {
				swap = temp1->data;
				temp1->data = temp->data;
				temp->data = swap;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}

void SinglyLinkedList::removeDuplicateNodesInLinkedList() {
	sortLinkedList();
	Node* temp = head;
	Node* temp1 = nullptr;
	while (temp != nullptr) {
		temp1 = temp->next;
		while (temp1 != nullptr && temp1->data == temp->data) {
			Node* p = temp1->next;
			temp1 = temp1->next;
			delete temp->next;
			temp->next = p;
		}
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
