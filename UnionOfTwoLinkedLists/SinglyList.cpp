#include <iostream>
#include "SinglyList.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

void SinglyLinkedList::insertNodeAtHead(int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

SinglyLinkedList SinglyLinkedList::unionOfTwoLinkedLists(SinglyLinkedList& l2) {
	if (head == nullptr && l2.head == nullptr) {
		return *this;
	}
	Node* tempForL1 = head;
	Node* tempForL2 = l2.head;
	SinglyLinkedList unionList;
	while (tempForL1 != nullptr) {

		unionList.insertNodeAtHead(tempForL1->data);
		tempForL1 = tempForL1->next;
	}
	bool flag = true;
	Node* p = head;
	while (tempForL2 != nullptr) {
		while (p != nullptr) {
			if (p->data == tempForL2->data) {
				flag = false;
				break;
			}
			p = p->next;
		}
		if (flag) {
			unionList.insertNodeAtHead(tempForL2->data);
		}
		p = head;
		flag = true;
		tempForL2 = tempForL2->next;
	}
	return unionList;
}

void SinglyLinkedList::displayLinkedList() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}
