#pragma once
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>

class vector {
private:
	node<T> * head;
	node<T> * tail;
	int s;

public:

	int size()
	{
		return s;
	}

	int capacity()
	{
		return s; //it's a linked list, so the capacity is the same as it's size
	}

	T back()
	{
		return tail->data;
	}

	T& operator[] (int pos)
	{
		node<T> * current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->next;
			/*if (current = NULL)
			{
				cout << "you've fallen off the list" << endl;
				break;
			}*/
		}
		return current->data;
	}

	//adds one new node to the end of the list without declaring it's data
	void addBack()
	{
		if (head == NULL)
		{
			head = new node<T>;
			tail = head;
			//tail->next = NULL;
			//head->previous = NULL;
			s++;
		}
		if (s > 0)
		{
			tail->next = new node<T>;
			tail->next->previous = tail;
			tail = tail->next;
			s++;
		}
	}

	void push_back(T x)
	{
		if (head == NULL)
		{
			head = new node<T>;
			tail = head;
			head->data = x;
			s++;
		}
		if (s > 0)
		{
			tail->next = new node<T>;
			tail->next->previous = tail;
			tail = tail->next;
			tail->data = x;
			s++;
		}
	}

	T pop_back()
	{
		if (head == NULL)
		{
			cout << "you can't pop an empty vector silly" << endl;
		}
		else
		{
			if (head == tail)
			{
				T temp = head->data;
				head = NULL;
				tail = NULL;
				s--;
				return temp;
			}
			else
			{
				T temp = tail->data;
				tail = tail->previous;
				delete tail->next;
				tail->next = NULL;
				return temp;
			}
		}
	}

	vector()
	{
		head = NULL;
		tail = NULL;
		s = 0;
	}

	vector(int x)
	{
		for (int i = 0; i < x; i++)
		{
			addBack();
		}
	}

	vector(int x, T y)
	{
		for (int i = 0; i < x; i++)
		{
			push_back(y);
		}
	}
	

};