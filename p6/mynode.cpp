#include "mynode.h"

MyNode::MyNode(int i) {
	nodeNum = i;
	pNext = NULL;
}

void MyNode::setNext(MyNode* node) {
    pNext = node;
}

int MyNode::getNum() {
    return nodeNum;
}

MyNode* MyNode::getNext() {
    return pNext;
}
