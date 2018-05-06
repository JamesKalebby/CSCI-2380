#pragma once
class stack
{
public:

	double items[100];
	int numItems;

	stack()
	{
		numItems = 0;
	}

	void push(double x)
	{
		items[numItems] = x;
		numItems++;
	}

	//remove and return top item from stack
	double pop()
	{
		numItems--;
		return items[numItems];
	}

	bool empty()
	{
		if (numItems == 0)
			return true;
		else
			return false;
	}

};

class queue
{
public:
	stack s1;
	stack s2;

	queue()
	{
	}

	void enqueue(double x)
	{
		s1.push(x);
	}

	double dequeue()
	{
		if (!s2.empty())
		{
			return s2.pop();
		}
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.pop());
			}

			return s2.pop();
		}
	}

	bool empty()
	{
		if (s1.empty() && s2.empty())
			return true;
		else
			return false;
	}

};