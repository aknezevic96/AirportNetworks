#ifndef MYLIST_H
#define MYLIST_H
#include "mynode.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

class MyList {
private:
    MyNode * pHead;
    int length;

public:
    MyList();
    ~MyList();
	
    MyNode* getHead();
    int getLength();
    int getNthNode(int i);
    void push(int i);
    void pop(int i);
    bool contains(int x);
    void printList();
};
#endif