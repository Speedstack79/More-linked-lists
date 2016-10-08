#include <iostream>
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
using namespace std;

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T weight;
		T name;
		Node * next, * prev;
	};
	Node * head;
	Node * tail;


public:
int size;
int biggest;
string biggestS;
	LinkedList()
	{
		//"dummy" node removes need for some special cases does not store data in itself
		head = new Node;
		head->next = 0; //not the head itself but the node it is initially pointing at
		tail = new Node;
		tail->prev = 0;
		size = 0;
	}
	~LinkedList();
	void add(T item1, T item); //since stack removes from top, this will remove only the most recent item
	void printAllNames(); //print names ascending by name
	void printAllWeights(); //


};

#include "LinkedList.cpp"
#endif
