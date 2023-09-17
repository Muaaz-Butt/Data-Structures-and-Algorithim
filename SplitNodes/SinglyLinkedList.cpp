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

int SinglyLinkedList::noOfNodesInLinkedList() {
	Node* temp = head;
	int count = 0;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

void SinglyLinkedList::splitList(SinglyLinkedList& list1, SinglyLinkedList& list2) {
	if (head == nullptr) {
		return;
	}
	int noOfNodes = noOfNodesInLinkedList();
	int i = noOfNodes / 2;
	int j = noOfNodes - i;
	Node* temp = head;
	while (i > 0) {
		list1.insertNodeAtTail(temp->data);
		temp = temp->next;
		i--;
	}
	while (j > 0) {
		list2.insertNodeAtTail(temp->data);
		temp = temp->next;
		j--;
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