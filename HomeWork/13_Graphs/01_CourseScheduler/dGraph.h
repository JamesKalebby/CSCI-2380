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
		bool visited;
		vertex * prior;

		vertex(string x)
		{
			data = x;
			visited = false;
		}
	};

	//master list of all vertices in graph
	//Slow, dumb data structure to store vertices.
	//Should switch to hash table or binary search tree
	//to improve search speed.
	vector<vertex*> vertexList;
public:
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

	queue<string> bag;
	void recPreReq(vertex * V)
	{
		//mark vert as visited
		V->visited = true;

		for (int i = 0; i < V->neighbors.size(); i++)
		{
			if(V->neighbors[i]->visited == false)
				recPreReq(V->neighbors[i]);
		}

		bag.push(V->data);
	}

public:

	void preReqDisplay()
	{

		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->visited == false)
			{
				recPreReq(vertexList[i]);
			}
			else
			{

			}
		}

		while (!bag.empty())
		{
			cout << bag.front() << endl;
			bag.pop();
		}
	}

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

	//add bi-directional edge
	void addEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
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