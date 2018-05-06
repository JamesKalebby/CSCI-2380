#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class node
{
public:
	T data;
	node * next;
	node * previous;

	node()
	{
		next = NULL;
		previous = NULL;
	}

};