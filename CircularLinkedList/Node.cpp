#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() :info(0), next(nullptr), prev(nullptr) {}

Node::Node(int info) :info(info), next(nullptr), prev(nullptr) {}