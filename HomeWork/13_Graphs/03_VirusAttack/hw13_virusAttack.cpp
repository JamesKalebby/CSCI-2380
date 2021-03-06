#include "stdafx.h"
#include "dGraph.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	directedGraph compGraph;
	ifstream compyList;
	compyList.open("computers.txt");

	int numComputers;

	compyList >> numComputers;

	for (int i = 0; i < numComputers; i++)
	{
		compGraph.addVertex(i);
	}

	int temp;
	int counter = 0;
	while (compyList >> temp)
	{
		counter++;
	}

	compyList.close();
	compyList.open("computers.txt");

	compyList >> temp;

	int num1;
	int num2;
	for (int i = 0; i < (counter - 1) / 2; i++)
	{
		compyList >> num1;
		compyList >> num2;
		cout << num1 << ", " << num2 << endl;

		compGraph.addEdge(num1, num2);
	}

	compyList >> num1;

	compGraph.infected(num1);


	return 0;
}


