// hw13_mazeSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dGraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "charMazer.h"
#include <ctime>

using namespace std;

int main()
{
	ifstream textFile;
	textFile.open("maze.txt");
	string fileLine;
	charMazer mazeBuilder;
	char** charMaze;

	//get hight and width of maze
	rollCall rowCol = mazeBuilder.getDimensions(textFile, fileLine);
	textFile.close();

	//initialize 2d array of chars
	textFile.open("maze.txt");
	charMaze = mazeBuilder.initializer(textFile, rowCol);
	textFile.close();

	//make graph from array
	directedGraph mazeGraph;


	//two for-loops to add all vertexes and set walls
	rollCall ab;
	for(int i = 0; i < rowCol.rows; i++)
	{
		for (int j = 0; j < rowCol.cols; j++)
		{
			ab.rows = i;
			ab.cols = j;
			if (charMaze[i][j] != '#')
			{
				mazeGraph.addVertex(charMaze[i][j], ab);
			}
			
		}
	}

	//setup edges
	mazeGraph.edgeBuilder(charMaze, rowCol);

	//Solve the maze
	charMaze = mazeGraph.bfs(charMaze);

	for (int i = 0; i < rowCol.rows; i++)
	{
		for (int j = 0; j < rowCol.cols; j++)
		{
			cout << charMaze[i][j];
		}
		cout << endl;
	}

	//print and save solution

    return 0;
}

