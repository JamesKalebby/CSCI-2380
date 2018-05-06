// HW32380.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include "BST.h"

using namespace std;




int rollDie(int numDice, int numThrows, int diceSize)
{
	//int roll = rand() % (numDice * (diceSize - 1)) + numDice;
	int roll = rand() % ((numDice * diceSize) - (numDice - 1)) + numDice;
	return roll;
}

int main()
{
	srand(time(NULL));
	bst rollSheet;
	int diceSize = 6;

	//get number of dice
	cout << "How many dice would you like to throw: " << endl;
	int numDice;
	cin >> numDice;

	//number of throws:
	cout << "How many times would you like to throw them: " << endl;
	int numThrows;
	cin >> numThrows;

	for (int i = 0; i < numThrows; i++)
	{
		rollSheet.insert(rollDie(numDice, numThrows, diceSize));
	}
	
	rollSheet.percentage(numThrows);

	rollSheet.display();



    return 0;
}

