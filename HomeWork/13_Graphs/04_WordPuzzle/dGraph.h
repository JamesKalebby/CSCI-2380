#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

class directedGraph
{
private:
	class vertex
	{
	public:
		string data;
		vector< vertex* > neighbors;
		vertex* prior;
		bool mark;

		vertex(string x)
		{
			data = x;
			prior = NULL;
			mark = false;
		}
	};

	//master list of all vertices in graph
	//Slow, dumb data structure to store vertices.
	//Should switch to hash table or binary search tree
	//to improve search speed.
	vector<vertex*> vertexList;

	//find vertex with x as data field.
	//return NULL if x is not present
	vertex * findVertex(string x)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return NULL;
	}

	void breadthFirstSearch(vertex * s)
	{
		//step 0:  initialize all algorithm data (you do this)

		//step 1: set up Q, put s in Q
		queue<vertex*> Q;
		s->mark = true;
		Q.push(s);

		//step 3:  The bfs loop!
		while (!Q.empty())
		{
			vertex * x = Q.front();
			Q.pop();

			//to print items in bfs order, add cout HERE!
			//cout << x->data;

			for (int i = 0; i < x->neighbors.size(); i++)
			{
				vertex * y = x->neighbors[i];
				if (y->mark == false)
				{
					//update cost
					//y->distance = x->distance + 1;
					y->prior = x;

					//put y into Q
					y->mark = true;
					Q.push(y);
				}
			}
		}

	}

public:

	directedGraph()
	{

	}

	void addVertex(string x)
	{
		vertexList.push_back(new vertex(x));
	}

	//add a directed edge going from
	//x to y
	void addDirectedEdge(string x, string y)
	{
		vertex * xVert = findVertex(x);
		vertex * yVert = findVertex(y);

		if (xVert != NULL && yVert != NULL)
			xVert->neighbors.push_back(yVert);
		else
			cout << "You misspelled something..." << endl;
	}

	bool isOneApart(string& a, string& b)
	{
		int count = 0;
		int n = a.length();

		// Iterate through all characters and return false
		// if there are more than one mismatching characters
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i]) count++;
			if (count > 1) return false;
		}
		if (count == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	//add bi-directional edge
	void addEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	void edgeBuilder()
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			for (int j = i + 1; j < vertexList.size(); j++)
			{
				if (isOneApart(vertexList[i]->data, vertexList[j]->data))
				{
					addEdge(vertexList[i]->data, vertexList[j]->data);
				}
			}
		}
	}

	void wordPath(string x, string y)
	{
		vertex* xV = findVertex(x);

		breadthFirstSearch(xV);



		for (vertex* yV = findVertex(y); yV != NULL; yV = yV->prior)
		{
			cout << yV->data << endl;
		}
	}
};