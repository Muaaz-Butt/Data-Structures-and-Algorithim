#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
	int info;
	Node* next;
	Node* prev;
	Node();
	Node(int info);
};

#endif // !NODE_H
