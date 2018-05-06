#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
	int data;
	int counter;
	double percent;
	node * left;
	node * right;

	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

class bst
{
public:
	node * root;

	bst()
	{
		root = NULL;
	}


	void recInsert(node * &p, int x)
	{
		if (p == NULL)
		{
			p = new node(x);
			p->counter = 0;
		}
		else if(x == p->data)
		{
				p->counter++;
		}
		else
		{
			if (x < p->data)
			{
				recInsert(p->left, x);
			}
			else
			{
				recInsert(p->right, x);
			}
		}
	}

	void insert(int x)
	{
		recInsert(root, x);
	}


	void recDisplay(node * p)
	{
		if (p == NULL)
		{
			//nothing to see here
		}
		else
		{
			recDisplay(p->left);
			cout << p->data << " " <<  p->percent << endl;
			recDisplay(p->right);
		}
	}

	void display()
	{
		recDisplay(root);
	}	

	void recPerc(node * p, double x)
	{
		if (p == NULL)
		{
			//nothing to see here
		}
		else
		{
			recPerc(p->left, x);
			p->percent = (p->counter / x) * 100;
			recPerc(p->right, x);
		}
	}

	void percentage(double x)
	{
		recPerc(root, x);
	}
};