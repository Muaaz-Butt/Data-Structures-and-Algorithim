#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
	while (head != nullptr) {
		removeNodeAtHead();		
	}
}

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

bool SinglyLinkedList::insertNodeAtSpecificIndex(int index, int value) {
	Node* newNode = new Node(value); 
	if (head == nullptr) {
		if (index == 1) {
			head = newNode;
			return true;
		}
		else {
			return false;
		}
	}
	else if (head != nullptr && index == 1) {
		newNode->next = head;
		head = newNode;
	}
	else {
		int i = 1;
		Node* temp = head;
		while (i < index - 1 && temp != nullptr) {
			temp = temp->next;
			i++;
		}
		if (temp != nullptr) {
			newNode->next = temp->next;
			temp->next = newNode;
			return true;
		}
		return false;
	}
}

int SinglyLinkedList::searchNode(int value) {
	Node* currNode = head;
	int currentIndex = 1;
	while (currNode && currNode->data != value) {
		currNode = currNode->next;
		currentIndex++;
	}
	if (currNode) {
		return currentIndex;
	}
	return 0;
}

bool SinglyLinkedList::updateValueInNode(int prevValue, int updatedValue) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == prevValue) {
			temp->data = updatedValue;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool SinglyLinkedList::insertAfter(int key, int value) {
	if (head == nullptr) {
		return false;
	}
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == key) {
			Node* newNode = new Node(value);
			newNode->next = temp->next;
			temp->next = newNode;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool SinglyLinkedList::insertBefore(int key, int value) {
	if (head == nullptr) {
		return false;
	}
	Node* temp = head;
	if (temp->data == key) {
		insertNodeAtHead(value);
		return true;
	}
	while (temp->next != nullptr) {
		if (temp->next->data == key) {
			Node* newNode = new Node(value);
			newNode->next = temp->next;
			temp->next = newNode;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void SinglyLinkedList::removeNodeAtHead() {
	if (head == nullptr) {
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}

void SinglyLinkedList::removeNodeAtTail() {
	if (head == nullptr) {
		return;
	}
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	Node* temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}

bool SinglyLinkedList::deleteNode(int value) {
	if (head == nullptr) {
		return false;
	}
	bool flag = false;
	Node* temp = head;
	Node* addressOfPrevNode = nullptr;
	while (temp != nullptr) {
		if (temp->data == value) {
			flag = true;
			break;
		}
		addressOfPrevNode = temp;
		temp = temp->next;
	}
	if (!flag) {
		return false;
	}
	else {
		if (head == temp) {
			head = head->next;
			return true;
		}
		else {
			addressOfPrevNode->next = temp->next;
			delete temp;
			return true;
		}
	}
}

bool SinglyLinkedList::removeAfter(int key) {
	if (head == nullptr || head->next == nullptr) {
		return false;
	}
	Node* temp = head;
	Node* addressOfSecondNode = nullptr;
	while (temp->next != nullptr) {
		if (temp->data == key) {
			addressOfSecondNode = temp->next->next;
			delete temp->next;
			temp->next = addressOfSecondNode;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool SinglyLinkedList::removeBefore(int key) {
	if (head == nullptr || head->data == key) {
		return false;
	}
	if (head->next->data == key) {
		removeNodeAtHead();
		return true;
	}
	Node* temp = head->next->next;
	Node* prevAddress = head;
	while (temp != nullptr) {
		if (temp->data == key) {
			delete prevAddress->next;
			prevAddress->next = temp;
			return true;
		}
		prevAddress = prevAddress->next;
		temp = temp->next;
	}
	return false;
}

void SinglyLinkedList::displayLinkedList() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}
 