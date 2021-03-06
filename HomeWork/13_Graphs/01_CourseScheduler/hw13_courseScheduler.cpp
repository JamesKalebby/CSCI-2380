// hw13_courseScheduler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "dGraph.h"

using namespace std;


int main()
{
	ifstream courseList("courses.txt");
	string line;
	string word;
	string neighbor;

	directedGraph courseGraph;
	
	//build the directed graph
	while (getline(courseList, line))
	{		
		stringstream ss(line);

		//add first vertex
		ss >> word;
		if(courseGraph.findVertex(word) == NULL)
			courseGraph.addVertex(word);

			while (ss >> neighbor)
			{
				if (courseGraph.findVertex(neighbor) == NULL)
				{
					courseGraph.addVertex(neighbor);
					courseGraph.addDirectedEdge(word, neighbor);
				}
				else
					courseGraph.addDirectedEdge(word, neighbor);
			}
	}

	courseList.close();

	//courseGraph.testDisplay();

	courseGraph.preReqDisplay();

    return 0;
}

