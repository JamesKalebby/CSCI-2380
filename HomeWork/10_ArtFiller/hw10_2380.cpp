// hw10_2380.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "canvas.h"

using namespace std;



int main()
{
	char userInput = ' ';
	int col;
	int row;
	int userRow;
	int userCol;
	char fillSymbol;
	char ** board;
	string fileLine;
	string saveFile;
	ifstream inputFile;
	ofstream outFile;
	string fileToMod;

	row = 0;
	col = 0;
	board = setCanvas(row, col);


	while (userInput != 'E')
	{
		cout << "Select from the options: (L)oad art, (F)ill, (S)ave art, (E)xit" << endl;
		cout << "Choice? ";
		cin >> userInput;
		userInput = toupper(userInput);


		if (userInput == 'L')
		{
			cout << endl << "File to read? ";
			cin >> fileToMod;
			inputFile.open(fileToMod);

			row = 0;
			col = 0;

			//find the length and width of the image
			while (getline(inputFile, fileLine))
			{
				if (fileLine.length() > col)
				{
					col = fileLine.length();
				}
				row++;
			}

			inputFile.close();
			inputFile.open(fileToMod);
		
			//avoid memory leaks
			delete[] board;
			//set the legnth and width of the 2d array
			board = setCanvas(row, col);

			//fill the 2d array with the image
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					inputFile >> noskipws >> board[i][j];
			display(board, row, col);
			inputFile.close();
		}
		else if (userInput == 'F')
		{
			cout << "Cell to begin Fill : ";
			cout << "Cell Row : ";
			cin >> userRow;
			cout << "Cell Column : ";
			cin >> userCol;
			cout << "Symbol : ";
			cin >> fillSymbol;

			//fill image
			fill(board, row, col, userRow, userCol, fillSymbol);
			display(board, row, col);
		}
		else if (userInput == 'S')
		{
			cout << "File to write: ";
			cin >> saveFile;
			cout << endl;

			outFile.open(saveFile);
			
			//write 2d array to txt file
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					outFile << board[i][j];
			outFile.close();
		}
		else if (userInput == 'E')
		{
			//exit program return 0;
		}
		else
		{
			system("cls");
			cout << "Please type a valid input " << endl << endl;
		}

	}
	

    return 0;
}

