#include <iostream>
#include "DNode.h"

using namespace std;

DNode::DNode() : info(0), next(nullptr), prev(nullptr) {}

DNode::DNode(int info) : info(info), next(nullptr), prev(nullptr) {}