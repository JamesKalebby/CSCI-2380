#pragma once
#pragma once
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>

class superQueue {
private:
	node<T> * head;
	node<T> * tail;
	int size;

public:


	superQueue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	//stack section

	void push(T x)
	{
		if (head == NULL)
		{
			head = new node<T>;
			tail = head;
			head->data = x;
			size++;
		}
		else
		{
			tail->next = new node<T>;
			tail->next->previous = tail;
			tail = tail->next;
			tail->data = x;
			size++;
		}
	}

	T pop()
	{
		if (head == NULL)
		{
			
		}
		else
		{
			if (head == tail)
			{
				T temp = head->data;
				head = NULL;
				tail = NULL;
				size--;
				return temp;
			}
			else
			{
				T temp = tail->data;
				tail = tail->previous;
				delete tail->next;
				tail->next = NULL;
				size--;
				return temp;
			}
		}
	}

	T& operator[] (int pos)
	{
		node<T> * current = head;
		for (int i = 0; i <= pos; i++)
		{
			current = current->next;
		}
		return current->data;
	}

	bool empty()
	{
		if (head == NULL /*size == 0*/)
		{
			return true;
		}	
		else
		{
			return false;
		}
	}

	// queue section

	void enqueue(T x)
	{
		push(x);
	}

	T dequeue()
	{
		if (head == NULL)
		{

		}
		else
		{
			if (head->next == NULL)
			{
				T tmp = head->data;
				delete head;
				head = NULL;
				tail = NULL;
				size--;
				return tmp;
			}
			else
			{
				T tmp = head->data;
				node<T> * doomedNode = head;
				head = head->next;
				head->previous = NULL;
				doomedNode->next = NULL;
				delete doomedNode;
				size--;
				return tmp;
			}
		}
	}

	//pq section

	void recInsert(node<T> * nP, T x)
	{
		if (nP->data > x)
		{
			if (nP->previous == NULL)
			{
				nP->previous = new node<T>;
				nP->previous->next = nP;
				nP->previous->data = x;
				head = nP->previous;
				size++;
			}
			else 
			{
				nP = nP->previous;
				nP->next->previous = new node<T>;
				nP->next->previous->next = nP->next;
				nP->next = nP->next->previous;
				nP->next->previous = nP;
				nP->next->data = x;
				size++;
			}
			
			
		}
		else
		{
			if (nP->next == NULL)
			{
				nP->next = new node<T>;
				nP->next->data = x;
				nP->next->previous = nP;
				tail = nP->next;
				size++;
			}
			else 
			{
				recInsert(nP->next, x);
			}
			
		}
	}

	void insert(T x)
	{
		if (head == NULL)
		{
			head = new node<T>;
			head->data = x;
			tail = head;
			size++;
		}
		else
		{
			recInsert(head, x);
		}
	}

	T extractMin()
	{
		return dequeue();
	}


};