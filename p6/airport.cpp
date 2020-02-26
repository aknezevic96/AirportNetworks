#include "airport.h"
 
Airport::Airport(int i) {
   num = i;
   visited = false;
   trips = new MyList;
}

Airport::Airport() {
   num = 0;
   visited = false;
   trips = new MyList;
}

Airport::~Airport() {
   num = 0;
   visited = false;
   delete trips;
}

bool Airport::isVisited() {
   return visited;
}

void Airport::setVisted() {
   visited = true;
}

void Airport::setNotVisited() {
   visited = false;
}

void Airport::setNum(int i) {
   num = i;
}

int Airport::getNum() {
   return num;
}

MyList* Airport::getList() {
   return trips;
}

void Airport::ins(int i) {
   trips->push(i);
}

void Airport::del(int i) {
   trips->pop(i);
}

void Airport::show() {
   trips->printList();
}