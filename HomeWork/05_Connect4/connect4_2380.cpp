// connect4_2380.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include"connect4.h"

using namespace std;


int main()
{
	//welcome user
	cout << "welcome to connect 4!" << endl;
	//make game pointer
	connect4 * newGame;
	newGame = NULL;
	
	cout << "would you like to play a standard or custom game? (s/c):" << endl;
	char sc;
	scFlag:
	cin >> sc;
	if (sc != 's' && sc != 'c')
	{
		cout << "please type s or n to select game type:" << endl;
		goto scFlag;
	}
	else
	{
		newGame->cls();
	}

	if (sc == 's')
	{
		newGame = new connect4();
	}
	else if (sc == 'c')
	{
		int rows, columns, players;

		cout << "How many rows would you like?" << endl;
		cin >> rows;

		cout << "How many columns would you like?" << endl;
		cin >> columns;

		cout << "How many players are there?" << endl;
		cin >> players;

		newGame->cls();
		newGame = new connect4(rows, columns, players);
	}

	int players = newGame->getLS();
	int move;

	while (!newGame->gameOver())
	{
		if (newGame->getCurrentP() == players)
		{
			newGame->resetP();
		}

		while (newGame->getCurrentP() < players)
		{
			newGame->cls();
			newGame->drawBoard();

			if (newGame->getName() == "AI")
			{
				cout << "AI's turn:" << endl;
				AIRetry:
				if (newGame->makeMove(newGame->getCurrentXO(), newGame->getAIMove()))
				{
					newGame->currentPlusPlus();
					if (newGame->gameOver())
					{
						goto gO;
					}
				}
				else
				{
					goto AIRetry;
				}
			}
			else
			{
				cout << newGame->getName() << "'s turn: ";
				retry:
				cin >> move;

				if (newGame->makeMove(newGame->getPiece(), move))
				{
					newGame->currentPlusPlus();

					if (newGame->gameOver())
					{
						goto gO;
					}
				}
				else
				{
					cout << "try another spot: " << endl;
					goto retry;
				}
			}
			
		}
	}
gO:
	newGame->cls();
	newGame->drawBoard();
	cout << newGame->winner() << " wins" << endl;


    return 0;
}

