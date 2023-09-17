#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
	int data;
	Node* next;
	Node();
	Node(int d);
};

#endif // !NODE_H

