#pragma once //bfs from class notes
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
		int data;
		vector< vertex* > neighbors;

		bool mark;
		int distance;
		vertex * prior;

		vertex(int x)
		{
			data = x;
			mark = false;
			distance = 0;
			prior = NULL;
		}
	};

	//master list of all vertices in graph
	vector<vertex*> vertexList;

	//find vertex with x as data field.
	//return NULL if x is not present
	vertex * findVertex(int x)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return NULL;
	}

	//perform a breadThFirst search from start vertex s
	void breadthFirstSearch(vertex * s)
	{
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
			cout << x->data << ", ";

			for (int i = 0; i < x->neighbors.size(); i++)
			{
				vertex * y = x->neighbors[i];
				if (y->mark == false)
				{
					//update cost
					y->distance = x->distance + 1;
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

	void addVertex(int x)
	{
		vertexList.push_back(new vertex(x));
	}

	//add a directed edge going from
	//x to y
	void addDirectedEdge(int x, int y)
	{
		vertex * xVert = findVertex(x);
		vertex * yVert = findVertex(y);

		if (xVert != NULL && yVert != NULL)
			xVert->neighbors.push_back(yVert);
		else
			cout << "You misspelled something..." << endl;
	}

	//add bi-directional edge
	void addEdge(int x, int y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	void infected(int x)
	{
		breadthFirstSearch(findVertex(x));
	}
};