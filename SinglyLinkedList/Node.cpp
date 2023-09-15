#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() : next(nullptr) {}

Node::Node(int d) : data(d), next(nullptr) {}