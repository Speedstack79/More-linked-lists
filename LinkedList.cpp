#include <iostream>
#include <stdlib.h>
using namespace std;

/**
*Prints all of the nodes in the list in ascending order by NAME.
*/
template <typename T>
void LinkedList<T>::printAllNames()
{
    int counter = 0;
        Node *ptr = head; //mine has first node's data empty maybe FIX
        cout << "\nNames & weights sorted(ascending) by name: ";
        while(ptr)
        {
            cout << ptr->name << " - " << ptr->weight << ", ";
            //cout << ptr->name << " -> "; to print just the names sorted
            ptr = ptr->next;
        }
    cout << endl;

}

/**
*Prints all of the nodes in the list in ascending order by WEIGHT.
*/
template <typename T>
void LinkedList<T>::printAllWeights()
{

        Node *ptr = tail;
        cout << "\nNames & weights sorted(ascending) by weight: ";
        while(ptr)
        {
            cout << ptr->name << " - " << ptr->weight << ", ";
            //cout << ptr->weight << " -> "; to print just the weights sorted
            ptr = ptr->prev;
        }
}

/**
*Adds name and weight to list, sorts both data as it is inserted into the list.
*/
template <typename T>
void LinkedList<T>::add (T item1, T item2)
{
    int temp;
    const char * c = item2.c_str();
    temp = atoi(c);

    Node *ptr = head;
    if (size == 0) //by default there is 1 node with nothing in it
    {
        biggest = temp;
        biggestS = item1;
        ptr->name = item1;
        ptr->weight = item2;
        tail->weight = item2;
        tail->name = item1;
    }
    else //if there is at least one filled node..
    {
        Node *newNode = new Node;
        newNode->name = item1;
        newNode->weight = item2;
        if (item1 <= biggestS) //if new node can go IN list without rearranging the null terminator
        {
            if (ptr->name >= item1) //if it goes in the first node
            {
                newNode->next = ptr;
                head = newNode;
            }
            else //if it goes after first but behind the last
            {
                for (ptr = head; ptr->next; ptr = ptr->next) //this alone sorted the entire list but stopped working for some reason
                {
                    if(item1 <= ptr->next->name)
                    {
                        break;
                    }
                }
                newNode->next = ptr->next;
                ptr->next = newNode;
            }
        }
        else //outside list
        {
            for (ptr = head; ptr->next; ptr = ptr->next)
            {

            }
            newNode->next = ptr->next; //ptr->next is null
            ptr->next = newNode;
        }
    ptr = tail;
    //----------------------------------------- essentially same algorithm but for weights
    if (temp <= biggest) //if new node can go IN list without rearranging the null terminator
        {
            if (atof((ptr->weight).c_str()) >= temp) //if it goes in the first node
            {
                newNode->prev = ptr;
                tail = newNode;
            }
            else //if it goes after first but behind the last
            {
                for (ptr = tail; ptr->prev; ptr = ptr->prev) //this alone sorted the entire list but stopped working for some reason
                {
                    if(temp <= atof((ptr->prev->weight).c_str()))
                    {
                        break;
                    }
                }
                newNode->prev = ptr->prev;
                ptr->prev = newNode;
            }
        }
        else //outside list
        {
            for (ptr = tail; ptr->prev; ptr = ptr->prev)
            {

            }
            newNode->prev = ptr->prev; //ptr->prev should be null anyway
            ptr->prev = newNode;
        }

    }

    if (item1 > biggestS)
    {
        biggestS = item1;
    }
    if (temp > biggest)
    {
        biggest = temp;
    }
        ++size;
}
/**
*Destructor to remove all the nodes once the program ends.
*/
template <typename T> //if linkedlist object is created without this... error
LinkedList<T>::~LinkedList()
{
	Node *ptr = head;
	Node *ptr2;
	while(ptr != 0)
	{
		ptr2 = ptr;
		ptr = ptr->next;
		delete ptr2;
	}
	size = 0;
}
