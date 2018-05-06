#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class binarySearchTree {
private:
	class node {
	public:
		double data;
		node * left;
		node * right;

		node (double x)
		{
			left = NULL;
			right = NULL;
			data = x;
		}
	};

	node * root;

	void recInsert(double x, node * &p)//takes on avg O(log(n)) worstcase O(n)
	{
		if (p == NULL)
		{
			p = new node(x);
		}
		else
		{
			if (x > p->data)
			{
				recInsert(x, p->right);
			}
			else
			{
				recInsert(x, p->left);
			}
		}
	}

	int recNumItems(node * p) //O(n)
	{
		if (p == NULL)
			return 0;
		else
		{
			return 1 + recNumItems(p->left) + recNumItems(p->right);
		}
	}

	int recNumLeaves(node * p) //O(n)
	{
		if (p == NULL)
			return 0;
		else
		{
			if (p->left == NULL && p->right == NULL)
			{
				return 1;
			}
			else
			{
				return recNumLeaves(p->left) + recNumLeaves(p->right);
			}
		}
	}

	int recGetH(node * p) //O(n)
	{
		if (p == NULL)
			return -1;
		else
		{
			int lDepth = recGetH(p->left);
			int rDepth = recGetH(p->right);

			if (lDepth > rDepth)
				return(lDepth + 1);
			else 
				return(rDepth + 1);
		}
	}

	int recFullN(node * p) //O(n)
	{
		if (p == 0)
			return 0;
		else
		{
			if (p->left != NULL && p->right != NULL)
			{
				return 1 + recFullN(p->left) + recFullN(p->right);
			}
			else
			{
				return recFullN(p->left) + recFullN(p->right);
			}
		}
	}

	node * &recFindN(node * &p, double x)// avg O(log(n)) worst-case O(n)
	{
		if (p == NULL)
		{

		}
		else if (p->data == x)
		{
			return p;
		}
		else
		{
			if (p->data > x)
				return recFindN(p->left, x);
			else if (p->data < x)
				return recFindN(p->right, x);
		}
	}

	void recInorder(node * &p)
	{
		if (p == NULL)
		{

		}
		else 
		{
			recInorder(p->left);
			cout << p->data << endl;
			recInorder(p->right);
		}
	}

	void recPreorder(node * &p) 
	{
		if (p == NULL)
		{

		}
		else
		{
			cout << p->data << endl;
			recInorder(p->left);
			recInorder(p->right);
		}
	}

	void recPostorder(node * p)
	{
		if (p == NULL)
		{

		}
		else
		{
			recInorder(p->left);
			recInorder(p->right);
			cout << p->data << endl;
		}
	}

	void recDisplay(node * p)
	{
		displayInorder();
	}

public:

	binarySearchTree()
	{
		root = NULL;
	}

	//O(nlogn)
	binarySearchTree(double items[], int numItems)
	{
		vector<double> myvector;
		myvector.assign(items, items + numItems); //o(n) This step could potentially be ommited but I couldn't make stable_sort() play nice with double * items
		stable_sort (myvector.begin(), myvector.end());// sorting takes avg O(nlogn)
		/* //testing purposes
		for (int i = 0; i < numItems; i++)
			cout << myvector[i] << " ";
			*/
		root = perfectTree(myvector, 0, numItems - 1);
	}

	node * perfectTree(vector<double> items, int start, int end)//O(n) walks through each item in array once
	{
		if (start > end)
		{
			return NULL;
		}
		else
		{
			int mid = (start + end) / 2;
			node * p = new node(items[mid]);	
			p->left = perfectTree(items, start, mid - 1);
			p->right = perfectTree(items, mid + 1, end);

			return p;
		}
	}

	void insert(double x)
	{
		recInsert(x, root);
	}

	void displayInorder()
	{
		recInorder(root);
	}

	void displayPreorder()
	{
		recPreorder(root);
	}

	void displayPostorder()
	{
		recPostorder(root);
	}

	int numItems()
	{
		return recNumItems(root);
	}

	int numLeaves()
	{
		return recNumLeaves(root);
	}

	int getHeight()
	{
		return recGetH(root);
	}

	int fullNodes()
	{
		return recFullN(root);
	}

	node * &findNode(double x)
	{
		return recFindN(root, x);
	}

	node * &findMin(node * &p)
	{
		if (p->left == NULL)
		{
			return p;
		}
		else
		{
			return findMin(p->left);
		}
	}

	node * &findMax(node * &p)
	{
		if (p->right == NULL)
		{
			return p;
		}
		else
		{
			return findMax(p->right);
		}
	}

	double extractMin()
	{
		//find min
		node * &p = findMin(root); // avg O(log(n))
		//remove node and return value
		//O(1)
		double x = p->data;

		if (p->right == NULL)
		{
			p = NULL;
			delete p;
			return x;
		}
		else
		{
			node * &temp = findMin(p->right);//some number of steps <= n - 1; is that O(1)?
			p->data = temp->data;
			temp = NULL;
			delete temp;
			return x;
		}


	}

	double extractMax()//same runtimes as extractMin()
	{
		//find min
		node * &p = findMax(root);
		//remove node and return value
		double x = p->data;

		if (p->left == NULL)
		{
			p = NULL;
			delete p;
			return x;
		}
		else
		{
			node * &temp = findMax(p->left);
			p->data = temp->data;
			temp = NULL;
			delete temp;
			return x;
		}
	}

	void display()
	{
		recInorder(root);
	}

	void remove(double x)
	{
		node * &p = findNode(x); //avg O(log(n))
		if (p == NULL)
		{

		}
		else
		{
			if (p->left == NULL && p->right == NULL)
			{
				p = NULL;
				delete p;
			}
			else if (p->right != NULL)
			{
				node * &temp = findMin(p->right);
				p->data = temp->data;
				temp = NULL;
				delete temp;
			}
			else
			{
				node * &temp = findMax(p->left);
				p->data = temp->data;
				temp = NULL;
				delete temp;
			}
		}
	}

	void levelOrderDisplay()
	{
		queue<node*> Q;

		Q.push(root);

		while (!Q.empty())
		{
			node * x = Q.front();
			Q.pop();

			cout << x->data << endl;

			if (x->left != NULL)
				Q.push(x->left);
			if (x->right != NULL)
				Q.push(x->right);
		}
	}
};