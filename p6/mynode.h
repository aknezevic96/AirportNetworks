#ifndef MYNODE_H
#define MYNODE_H
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

class MyNode {
private:
    int nodeNum;
    MyNode* pNext;

public:
    MyNode(int i);
	
    void setNext(MyNode* node);
    int getNum();
    MyNode* getNext();
};
#endif