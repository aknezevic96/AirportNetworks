#ifndef NETWORKS_H
#define NETWORKS_H
#include "airport.h"
#include "mylist.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

class TravelNetwork {
private:
    int size;
    Airport* darr;
    MyList* fileList;

public:
    TravelNetwork();
    ~TravelNetwork();
	
    void processCommandLoop (FILE* inFile);
    void showCommands();
    void doTravel();
    void doResize();
    void doInsert();
    void doDelete();
    void doList();
    void doFile();
	void depthFirstSearchHelper(int x, int y);
    bool dfs(int a, int b);
};
#endif