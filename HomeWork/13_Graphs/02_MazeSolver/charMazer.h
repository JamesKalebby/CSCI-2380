#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class rollCall {
public:
	int rows;
	int cols;

	rollCall()
	{
		rows = 0;
		cols = 0;
	}

	bool operator==(rollCall &compare)
	{
		if (this->rows == compare.rows && this->cols == compare.cols)
			return true;
		else
			return false;
	}
};

class charMazer{
private:
	int rows;
	int cols;

public:
	charMazer()
	{
		rows = 0;
		cols = 0;
	}

	rollCall getDimensions(ifstream &textFile, string &fileLine)
	{
		//string fileLine;

		while (getline(textFile, fileLine))
		{
			if (fileLine.length() > cols)
			{
				cols = fileLine.length();
			}
			rows++;
		}
		rollCall xy;
		xy.rows = rows;
		xy.cols = cols;

		return xy;
	}

	char** initializer(ifstream &textFile, rollCall rowCol)
	{
		//make space
		char** charMaze = new char *[rowCol.rows];
		for (int i = 0; i < rowCol.rows; i++)
		{
			charMaze[i] = new char[rowCol.cols];
		}

		//fill space
		string line;

		for (int i = 0; i < rowCol.rows; i++)
		{
			getline(textFile, line);
			stringstream ss(line);
			for (int j = 0; j < rowCol.cols; j++)
			{
				charMaze[i][j] = ss.get();
			}
		}

		return charMaze;
	}

};