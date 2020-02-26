#include "mylist.h"

MyList::MyList() {
	pHead = NULL;
	length = 0;
}

MyList::~MyList() {
	if(pHead == NULL){
		return;
	}
	
	MyNode* temp = NULL;
	
	while(pHead != NULL) {
		temp = pHead;
		pHead = pHead->getNext();
		delete temp;
	}
	
	delete pHead;
}

MyNode* MyList::getHead() {
    return pHead;
}

int MyList::getLength() {
	return length;
}

int MyList::getNthNode(int i) {
	MyNode* temp = pHead;
	int count = 0;
	
	while(temp != NULL){
		if(count == i){
			return temp->getNum();
		}
		count++;
		temp = temp->getNext();
	}
	
	return -999;
}
	
void MyList::push(int i) {
	MyNode* temp = pHead;
	MyNode* newNode = new MyNode(i);
	length++;

	if(pHead == NULL){
		pHead = newNode;
		return;
	}
	
	while (temp->getNext() != NULL) {
		temp = temp->getNext();
	}
	
	temp->setNext(newNode);
	return;
}

void MyList::pop(int i) {
	MyNode* temp = pHead , * prev;

	if(temp != NULL && temp->getNum() == i)
	{
		pHead = temp->getNext();
		delete temp;
		length--;
		return;
	}

	while(temp != NULL && temp->getNum() != i)
	{
		prev = temp;
		temp = temp->getNext();
	}

	if(temp == NULL)
		return;
	
	prev->setNext(temp->getNext());

	delete temp;
	length--;
}

bool MyList::contains(int x) {
	MyNode* temp = pHead;
	
	while (temp != NULL) {
		if(temp->getNum() == x){
			return true;
		}
		
		temp = temp->getNext();
	}
	
	return false;
}

void MyList::printList(){
	if(pHead == NULL)
		return;

	MyNode* temp = pHead;
	
	while (temp != NULL) {
		std::cout << temp->getNum() << "->";
		temp = temp->getNext();
	}
	
	std::cout << std::endl;
}
