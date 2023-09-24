#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList() :head(nullptr), tail(nullptr) {}

void CircularLinkedList::insertAtHead(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	tail->next = head;
	head->prev = tail;
}

void CircularLinkedList::insertAtTail(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	tail->next = head;
}

void CircularLinkedList::insertAfter(int key, int value)
{
	if (head == nullptr)
	{
		return;
	}
	Node* temp = head;
	bool isFound = true;
	do 
	{
		if (temp->info == key) 
		{
			isFound = false;
		}
		else
		{
			temp = temp->next;
		}
	} while (temp != head && isFound);
	if (temp == tail)
	{
		insertAtTail(value);
		return;
	}
	if (!isFound)
	{
		Node* newNode = new Node(value);
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
}

void CircularLinkedList::insertBefore(int key, int value)
{
	if (head == nullptr)
	{
		return;
	}
	Node* temp = head;
	bool isFound = true;
	do
	{
		if (temp->info == key)
		{
			isFound = false;
		}
		else
		{
			temp = temp->next;
		}
	} while (temp != nullptr && isFound);
	if (temp == head) 
	{
		insertAtHead(value);
		return;
	}
	if (!isFound)
	{
		Node* newNode = new Node(value);
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
	}
}

void CircularLinkedList::updateValue(int prevValue, int updatedValue)
{
	if (head == nullptr)
	{
		return;
	}
	Node* temp = head;
	do
	{
		if (temp->info == prevValue)
		{
			temp->info = updatedValue;
			return;
		}
		temp = temp->next;
	} while (temp != nullptr);
}

void CircularLinkedList::removeAtHead()
{
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	Node* temp = head;
	head = head->next;
	tail->next = head;
	delete temp;
}

void CircularLinkedList::removeAtTail()
{
	if (head == tail)
	{
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	Node* temp = tail;
	tail = tail->prev;
	tail->next = head;
	head->prev = tail;
	delete temp;
}

bool CircularLinkedList::removeNode(int key)
{
	if (head == nullptr)
	{
		return false;
	}
	Node* temp = head;
	bool isFound = true;
	do
	{
		if (temp->info == key)
		{
			isFound = false;
		}
		else
		{
			temp = temp->next;
		}
	} while (temp != head && isFound);
	if (temp == head)
	{
		removeAtHead();
		return true;
	}
	if (temp == tail)
	{
		removeAtTail();
		return true;
	}
	if (!isFound)
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		return true;
	}
	return false;
}

bool CircularLinkedList::removeAfter(int key)
{
	if (head == nullptr || head->next == nullptr)
	{
		return false;
	}
	Node* temp = head;
	bool isFound = true;
	do
	{
		if (temp->info == key)
		{
			isFound = false;
		}
		temp = temp->next;
	} while (temp != head && isFound);
	if (!isFound)
	{
		removeNode(temp->info);
		return true;
	}
	return false;
}

bool CircularLinkedList::removeBefore(int key)
{
	if (head == nullptr || head->next == nullptr)
	{
		return false;
	}
	Node* temp = tail;
	bool isFound = true;
	do
	{
		if (temp->info == key)
		{
			isFound = false;
		}
		temp = temp->prev;
	} while (temp != tail && isFound);
	if (!isFound)
	{
		removeNode(temp->info);
		return true;
	}
	return false;
}

void CircularLinkedList::reverseList()
{
	Node* prev = tail;
	Node* current = head;
	Node* next;

	do {
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	} while (current != head);
	head->next = prev;
	head = prev;
}


void CircularLinkedList::display()
{
	if (head == nullptr) 
	{
		return;
	}
	Node* temp = head;
	do 
	{
		cout << temp->info << " ";
		temp = temp->next;
	} while (temp != head);
	cout << "\n";
}