
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char ** setCanvas(int row, int col)
{
	char ** tempCanvas = new char * [row];

	for (int i = 0; i < row; i++)
	{
		tempCanvas[i] = new char[col];
	}

	return tempCanvas;
}

void fill(char ** canvas, int row, int col, int i, int j, char x)
{
	if (canvas[i][j] != ' ')
	{

	}
	else
	{
		if (i <= row && j <= col && i >= 0 && j >= 0)
		{
			//fill spot
			canvas[i][j] = x;
			//recursively fill img
			fill(canvas, row, col, i + 1, j, x);
			fill(canvas, row, col, i - 1, j, x);
			fill(canvas, row, col, i, j + 1, x);
			fill(canvas, row, col, i, j - 1, x);
		}


	}
}

void display(char ** board, int row, int col)
{
	system("cls");
	cout << "Current Artwork: " << endl << endl;

	//loop through array, display contents
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << board[i][j];
		}
	}

	cout << endl << endl;
}