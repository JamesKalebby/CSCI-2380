#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;


template <class T>
class stackQueue
{
private:
	T * items;
	int front;
	int back;
	int capacity;
	int numItems;

	//was encouraged to put the resize in private
	void resize(int newCap)
	{
		T * temp = new T[newCap];

		for (int i = 0; i < newCap / 2; i++)
		{
			temp[i] = items[front];
			front = (front + 1) % capacity;
		}

		delete[] items;
		items = temp;
		front = 0;
		back = (newCap / 2) - 1;
		capacity = newCap;
	}

public:
	stackQueue()
	{
		capacity = 10;
		items = new T[capacity];
		front = -1; //initially, I was trying to write this using NULL as my 'flag' but
		back = -1; //the program would never run properly. After changing this to -1 it works perfectly?
		numItems = 0; //I still have not figured out why this would be
	}

	void addBack(T x)
	{
		if (front == -1)
		{
			front = 0;
			back = 0;
			items[0] = x;
			numItems++;
		}
		else
		{
			if ((back + 1) % capacity == front)
			{
				resize(capacity * 2);
			}

			back = (back + 1) % capacity;
			items[back] = x;
			numItems++;
		}
	}

	void addFront(T x)
	{
		if (front == -1)
		{
			front = 0;
			back = 0;
			items[0] = x;
			numItems++;
		}
		else
		{
			if ((back + 1) % capacity == front)
			{
				resize(capacity * 2);
			}

			if (front == 0)
			{
				front = capacity - 1;
			}
			else
			{
				front = (front - 1) % capacity;
			}

			items[front] = x;
			numItems++;
		}
	}

	T removeBack()
	{
		T output = items[back];
		back = (back - 1) % capacity;
		numItems--;

		if (front == (back + 1) % capacity)
		{
			front = -1;
			back = -1;
		}
		else if (back < 0)
		{
			back = capacity - 1;
		}

		return output;
	}

	
	T removeFront()
	{
		T output = items[front];
		front = (front + 1) % capacity;
		numItems--;

		if (front == (back + 1) % capacity)
		{
			front = -1;
			back = -1;
		}
		else if (front < 0)
		{
			front = capacity - 1;
		}

		return output;
	}

	bool empty()
	{
		if (numItems == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	srand(time(0));
	stackQueue<string> gengo;

	gengo.addFront("English");
	gengo.addBack("Nihongo");
	gengo.addBack("Zhongwen");
	
	cout << gengo.removeFront() << endl;;
	cout << gengo.removeBack() << endl;
	cout << gengo.removeBack() << endl;

	stackQueue<int> nums;

	for (int i = 0; i < 10000; i++)
	{
		nums.addFront(rand() % 100);
	}

	for (int i = 0; i < 10000; i++)
	{
		cout << nums.removeBack() << endl;
	}



	return 0;
}