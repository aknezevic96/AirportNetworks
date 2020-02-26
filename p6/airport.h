#ifndef AIRPORT_H
#define AIRPORT_H
#include "mylist.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

class Airport {
private:
   int num;
   bool visited;
   MyList* trips;

public:
   Airport(int i);
   Airport();
   ~Airport();
   
   bool isVisited();
   void setVisted();
   void setNotVisited();
   void setNum(int i);
   int getNum();
   MyList* getList();
   void ins(int i);
   void del(int i);
   void show();
};
#endif