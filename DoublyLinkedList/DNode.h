#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

class DNode {
public:
	int info;
	DNode* next;
	DNode* prev;
	DNode();
	DNode(int info);
};

#endif // !DOUBLELINKEDLIST_H
