#include <iostream>
#include "List.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

void SinglyLinkedList::insertNodeAtHead(int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

bool SinglyLinkedList::isEqual(SinglyLinkedList& list) {
	Node* tempForList1 = head;
	Node* tempForList2 = list.head;
	bool flag;
	int noOfNodesInList1 = 0, noOfNodesInList2 = 0;
	while (tempForList1 != nullptr) {
		noOfNodesInList1++;
		tempForList1 = tempForList1->next;
	}
	while (tempForList2 != nullptr)
	{
		noOfNodesInList2++;
		tempForList2 = tempForList2->next;
	}
	if (noOfNodesInList1 != noOfNodesInList2) {
		return false;
	}
	tempForList1 = head;
	tempForList2 = list.head;
	while (tempForList1 != nullptr) {
		flag = false;
		while (tempForList2 != nullptr) {
			if (tempForList2->data == tempForList1->data) {
				flag = true;
				break;
			}
			else {
				flag = false;
			}
			tempForList2 = tempForList2->next;
		}
		if (!flag) {
			return false;
		}
		tempForList2 = list.head;
		tempForList1 = tempForList1->next;
	}
	return true;
}

void SinglyLinkedList::displayLinkedList() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

