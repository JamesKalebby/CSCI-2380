#pragma once
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class playersList
{
public:
	string name;
	char piece;
};

class connect4
{
private:
	char * * gBoard;
	int w;
	int l;
	playersList * pL;
	int listSize;
	int currentP;
	char winningChar;

public:

	int getLS()
	{
		return listSize;
	}

	int getCurrentP()
	{
		return currentP;
	}

	void resetP()
	{
		currentP = 0;
	}

	char getCurrentXO()
	{
		return pL[currentP].piece;
	}

	string setName()
	{
		cout << "what is your name?" << endl;
		string name;
		cin >> name;
		return name;
	}

	char setPiece()
	{
		cout << endl << "what piece do you want?" << endl;
		char piece;
		cin >> piece;
		return piece;
	}

	void bogoSwap(playersList * items, char * xo, int numItems)
	{
		srand(time(NULL));
		rand();
		if (numItems == 2)
		{
			xo = new char[numItems];
			xo[0] = 'X';
			xo[1] = 'O';
		}
		else
		{
			xo = new char[numItems];
			
			for (int i = 0; i < numItems; i++)
			{
				char temp;
				cout << "what would you like your piece to be" << endl;
				cin >> temp;
				xo[i] = temp;
			}

		}

		int swapCount = rand() % 10;

		for (int i = 0; i < swapCount; i++)
		{
			swap(xo[rand() % numItems], xo[rand() % numItems]);
		}

		for (int i = 0; i < numItems; i++)
		{
			items[i].piece = xo[i];
		}
	}

	void pieceAssign(playersList * pL, int numPlayers)
	{
		char * nPA = new char[numPlayers];
		bogoSwap(pL, nPA, numPlayers);
		
		//tell user what character they are
		for (int i = 0; i < listSize; i++)
		{
			cout << pL[i].name << ", you are " << pL[i].piece << "'s" << endl;
		}
		system("pause");
	}

	void initializeBoard()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < l; j++)
			{
				gBoard[i][j] = '-';
			}
		}
	}

	connect4()
	{
		pL = new playersList[2];
		listSize = 2;
		currentP = 0;

		pL[0].name = setName();
		pL[1].name = "AI";

		pieceAssign(pL, listSize);

		w = 6;
		l = 7;

		gBoard = new char*[w];

		for (int i = 0; i < w; i++)
		{
			gBoard[i] = new char[l];
		}

		initializeBoard();
	}

	connect4(int numRows, int numCol, int numPlayers)
	{
		pL = new playersList[numPlayers];
		listSize = numPlayers;
		currentP = 0;

		for (int i = 0; i < listSize; i++)
		{
			cout << "Player " << i + 1 << ", ";
			pL[i].name = setName();
			pL[i].piece = setPiece();	
		}

		w = numRows;
		l = numCol;

		gBoard = new char*[w];

		for (int i = 0; i < w; i++)
		{
			gBoard[i] = new char[l];
		}

		initializeBoard();
	}

	void drawBoard()
	{
		cout << "   ";
		for (int i = 0; i < l; i++)
		{
			cout << i << " ";
		}

		cout << endl;

		int colNums = 0;
		for (int i = 0; i < w; i++)
		{
			cout << colNums << "| ";
			for (int j = 0; j < l; j++)
			{
				cout << gBoard[i][j] << " ";
			}
			cout << endl;
			colNums++;
		}

	}

	bool makeMove(char piece, int c)
	{
		if (c < 0 || c > w)
		{
			return false;
		}
		else
		{
			for (int i = w-1; i >= 0; i--)
			{
				if (gBoard[i][c] == '-')
				{
					gBoard[i][c] = piece;
					return true;
				}
			}
			return false;
		}
	}


	int getAIMove()
	{
		return (rand() % 7);
	}

	string getName()
	{
		return pL[currentP].name;
	}

	char getPiece()
	{
		return pL[currentP].piece;
	}

	void currentPlusPlus()
	{
		currentP++;
	}

	void currentMinusMinus()
	{
		currentP--;
		if (currentP < 0)
		{
			currentP = listSize;
		}
	}

	bool gameOver()
	{
		//check vert
		for (int i = 0; i < w - 3; i++)
		{
			for (int j = 0; j < l; j++)
			{
				for (int k = 0; k < listSize; k++)
				{
					if (gBoard[i][j] == pL[k].piece && gBoard[i + 1][j] == pL[k].piece && gBoard[i + 2][j] == pL[k].piece && gBoard[i + 3][j] == pL[k].piece)
					{
						winningChar = pL[k].piece;
						return true;
					}
					else
					{
					}
				}
			}
		}

		//check horizontal
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < (l - 3); j++)
			{
				for (int k = 0; k < listSize; k++)
				{
					if (gBoard[i][j] == pL[k].piece && gBoard[i][j + 1] == pL[k].piece && gBoard[i][j + 2] == pL[k].piece && gBoard[i][j + 3] == pL[k].piece)
					{
						winningChar = pL[k].piece;
						return true;
					}
				}
			}
		}

		//check diagonals
		
		//diagonal down
		for (int i = 0; i < w - 3; i++)
		{
			for (int j = i; j < (l - 3); j++)
			{
				for (int k = 0; k < listSize; k++)
				{
					if (gBoard[i][j] == pL[k].piece && gBoard[i + 1][j + 1] == pL[k].piece && gBoard[i + 2][j + 2] == pL[k].piece && gBoard[i + 3][j + 3] == pL[k].piece)
					{
						winningChar = pL[k].piece;
						return true;
					}
				}
			}
		}

		//diagonal up
		for (int i = w - 1; i > 2; i--)
		{
			for (int j = 0; j < (l - 3); j++)
			{
				for (int k = 0; k < listSize; k++)
				{
					if (gBoard[i][j] == pL[k].piece && gBoard[i - 1][j + 1] == pL[k].piece && gBoard[i - 2][j + 2] == pL[k].piece && gBoard[i - 3][j + 3] == pL[k].piece)
					{
						winningChar = pL[k].piece;
						return true;
					}
				}
			}
		}


		return false;
	}

	char winner()
	{
		return winningChar;
	}

	void cls()
	{
		system("cls"); //hiding this down here in shame
	}

};