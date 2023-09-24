#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() :head(nullptr), tail(nullptr) {}

bool DoublyLinkedList::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}

void DoublyLinkedList::insertAtHead(int value) {
	DNode* newNode = new DNode(value);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void DoublyLinkedList::insertAtTail(int value) {
	DNode* newNode = new DNode(value);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
}

bool DoublyLinkedList::searchValueInLinkedList(int value) {
	DNode* temp = head;
	while (temp != nullptr) {
		if (temp->info == value) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void DoublyLinkedList::insertAfter(int key, int value) {
	if (isEmpty()) {
		return;
	}
	DNode* temp = head;
	bool isFound = true;
	while (temp != nullptr && isFound) {
		if (temp->info == key) {
			isFound = false;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp == tail) {
		insertAtTail(value);
		return;
	}
	if (!isFound) {
		DNode* newNode = new DNode(value);
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		temp->next = newNode;
	}
}

void DoublyLinkedList::insertBefore(int key, int value) {
	if (head == nullptr) {
		return;
	}
	DNode* temp = head;
	bool isFound = true;
	while (temp != nullptr && isFound)
	{
		if (temp->info == key) {
			isFound = false;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp == head) {
		insertAtHead(value);
		return;
	}
	if (!isFound) {
		DNode* newNode = new DNode(value);
		newNode->prev = temp->prev;
		newNode->next = temp;
		temp->prev->next = newNode;
		temp->prev = newNode;
		return;
	}
}

void DoublyLinkedList::updateValue(int prevValue, int updatedValue) {
	DNode* temp = head;
	while (temp != nullptr) {
		if (temp->info == prevValue) {
			temp->info = updatedValue;
			return;
		}
		temp = temp->next;	
	}
}

void DoublyLinkedList::removeAtHead() {
	if (head == nullptr) {
		return;
	}
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	DNode* temp = head;
	head = head->next;
	delete temp;
}

void DoublyLinkedList::removeAtTail() {
	if (head == nullptr) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	DNode* temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;
}

void DoublyLinkedList::removeNode(int key) {
	if (head == nullptr) {
		return;
	}
	DNode* temp = head;
	bool isFound = true;
	while (temp != nullptr && isFound) {
		if (temp->info == key) {
			isFound = false;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp == head) {
		removeAtHead();
		return;
	}
	if (temp == tail) {
		removeAtTail();
		return;
	}
	if (!isFound) {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
}

void DoublyLinkedList::removeAfter(int key) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	DNode* temp = head;
	bool isFound = true;
	while (temp->next != nullptr && isFound) {
		if (temp->info == key) {
			isFound = false;
		}
		temp = temp->next;
	}
	if (!isFound) {
		removeNode(temp->info);
		return;
	}
}

void DoublyLinkedList::removeBefore(int key) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	DNode* temp = head;
	bool isFound = true;
	while (temp != nullptr && isFound) {
		if (temp->info == key) {
			isFound = false;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp == head) {
		return;
	}
	if (!isFound) {
		temp = temp->prev;
		removeNode(temp->info);
		return;
	}
}

void DoublyLinkedList::reverseDisplay() {
	DNode* temp = tail;
	while (temp != nullptr) {
		cout << temp->info << " ";
		temp = temp->prev;
	}
	cout << "\n";
}

void DoublyLinkedList::reverseList() {
	DNode* current = head;
	DNode* next = nullptr;
	DNode* temp = head;
	head = tail;
	tail = temp;
	DNode* prev = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
}

void DoublyLinkedList::sortList() {
	DNode* temp = head;
	DNode* temp1 = nullptr;
	int swap;
	while (temp->next != nullptr) {
		temp1 = temp->next;
		while (temp1 != nullptr) {
			if (temp->info > temp1->info) {
				swap = temp->info;
				temp->info = temp1->info;
				temp1->info = swap;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}

void DoublyLinkedList::display() {
	DNode* temp = head;
	while (temp != nullptr) {
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << "\n";
}