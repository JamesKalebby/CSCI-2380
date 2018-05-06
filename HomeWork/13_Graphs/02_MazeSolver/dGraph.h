#pragma once

#include <vector>
#include <iostream>
#include "charMazer.h"
#include <queue>
using namespace std;

class directedGraph
{
private:
	class vertex
	{
	public:
		char data;
		vector< vertex* > neighbors;
		bool visited;
		vertex* prior;
		rollCall xy;

		vertex(char x, rollCall ab)
		{
			data = x;
			visited = false;
			xy = ab;
			prior = NULL;
		}
	};

	//master list of all vertices in graph
	//Slow, dumb data structure to store vertices.
	//Should switch to hash table or binary search tree
	//to improve search speed.
	vector<vertex*> vertexList;

	//perform a breadThFirst search from start vertex s
	void breadthFirstSearch(vertex * s)
	{
		//step 0:  initialize all algorithm data (you do this)

		//step 1: set up Q, put s in Q
		queue<vertex*> Q;
		s->visited = true;
		Q.push(s);

		//step 3:  The bfs loop!
		while (!Q.empty())
		{
			vertex * x = Q.front();
			Q.pop();

			//to print items in bfs order, add cout HERE!
			//cout << x->data << endl;

			for (int i = 0; i < x->neighbors.size(); i++)
			{
				vertex * y = x->neighbors[i];
				if (y->visited == false)
				{
					//update cost
					//y->distance = x->distance + 1;
					y->prior = x;

					//put y into Q
					y->visited = true;
					Q.push(y);
				}
			}
		}

	}

public:
	//find vertex with x as data field.
	//return NULL if x is not present
	vertex * findVertex(rollCall ab)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->xy == ab)
				return vertexList[i];
		}
		return NULL;
	}

	vertex * findVertex(char x)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return NULL;
	}

	directedGraph()
	{

	}

	void addVertex(char x, rollCall ab)
	{
		vertexList.push_back(new vertex(x, ab));
		if (x == '#')
		{
			//findVertex(ab)->visited = true;
		}
	}

	//add a directed edge going from
	//x to y
	void addDirectedEdge(rollCall ab, rollCall cd)
	{
		vertex * xVert = findVertex(ab);
		vertex * yVert = findVertex(cd);

		if (xVert != NULL && yVert != NULL)
			xVert->neighbors.push_back(yVert);
		else
		{
			//do nothing
		}
	}

	//add bi-directional edge
	void addEdge(rollCall ab, rollCall cd)
	{
		addDirectedEdge(ab, cd);
		addDirectedEdge(cd, ab);
	}

	void edgeBuilder(char ** charMaze, rollCall rowCol)
	{
		rollCall ab;
		rollCall cd;
		for (int i = 0; i < rowCol.rows - 1; i++)
		{
			for (int j = 0; j < rowCol.cols; j++)
			{
				ab.rows = i;
				ab.cols = j;
				cd.rows = i + 1;
				cd.cols = j;
				addEdge(ab, cd);
			}
		}
		for (int i = 0; i < rowCol.rows; i++)
		{
			for (int j = 0; j < rowCol.cols - 1; j++)
			{
				ab.rows = i;
				ab.cols = j;
				cd.rows = i;
				cd.cols = j + 1;
				addEdge(ab, cd);
			}
		}
	}

	char** bfs(char** charMaze)
	{
		breadthFirstSearch(findVertex('s'));

		for (vertex * x = findVertex('e'); x != NULL; x = x->prior)
		{
			if (charMaze[x->xy.rows][x->xy.cols] != 's' && charMaze[x->xy.rows][x->xy.cols] != 'e')
			{
				charMaze[x->xy.rows][x->xy.cols] = '.';
				x->data = '.';
			}
		}
		return charMaze;
	}

	void testDisplay()
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			cout << vertexList[i]->data << " goes to: ";
			for (int j = 0; j < vertexList[i]->neighbors.size(); j++)
			{
				cout << vertexList[i]->neighbors[j]->data << ", ";
			}
			cout << endl;
		}
	}
};