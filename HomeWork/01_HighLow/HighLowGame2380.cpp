// HighLowGame2380.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

//new class to hold first and last name and the score earned
class player {
public:
	string fName;
	string lName;
	int score;
};

//selection sort
void scoreSort(player * p1)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = i + 1; j < 11; j++)
		{
			if (p1[j].score < p1[i].score)
			{
				swap(p1[i], p1[j]);
			}
		}
	}
}


int main()
{
	srand(time(0));
	//get current highscores from textfile and print them to the screen
	//open text file
	ifstream inputFile;
	inputFile.open("highScores.txt");

	//create an array of players that is big enough for all current highscores plus one
	player * p1 = new player[11];

	//put current highscores in array
	for (int i = 0; i < 10; i++)
	{
		inputFile >> p1[i].fName;
		inputFile >> p1[i].lName;
		inputFile >> p1[i].score;
	}
	inputFile.close();

	//display current high scores
	cout << "------------------------------------" << endl;
	cout << "----------  HIGH SCORES ------------" << endl;
	cout << "------------------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << p1[i].fName << " " << p1[i].lName << " " << p1[i].score << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl << endl;

	cout << "Think you've got what it takes to make the top ten?  Let's find out!" << endl;

	//steal identity of vict...uh get name for game!
	cout << "what's your first name?" << endl;
	cin >> p1[10].fName;
	cout << "what's your last name?" << endl;
	cin >> p1[10].lName;
	cout << "alright lets do this!" << endl;

	//prompt user with instructions and generate a random number
	cout << endl << "I'm thinking of a number between 1 and 100!" << endl;
	int answer = rand() % 100;

	//nothing to see here
	//cout << endl << answer;
	//just keep moving along

	//create a variable to keep track of user guesses
	int guessCounter = 0;
	int guess = 101; //set to be out of the range of possible answers

	//user guesses and the counter keeps track;
	while (guess != answer)
	{
		guessCounter++;
		cin >> guess;

		if (guess > answer)
		{
			cout << "Too High" << endl;
		}
		else if (guess < answer)
		{
			cout << "Too Low" << endl;
		}
	}

	p1[10].score = guessCounter;
	cout << "------------------------------------" << endl;
	//bunch of if-statements to insult user appropriatley
	if (guessCounter == 1)
	{
		cout << "No -- Freaking -- Way! Only one guess!?!?" << endl << "is " << p1[10].fName << " your hacker alias?" << endl;
	}
	else if (guessCounter > 1 && guessCounter <= 4)
	{
		cout << "Wow! Impressive! it only took you " << guessCounter << " tries!" << endl;
	}
	else if (guessCounter == 5 || guessCounter == 6)
	{
		cout << "It only took you " << guessCounter << " guesses! That's a pretty good score!" << endl;
	}
	else if (guessCounter == 7 || guessCounter == 8)
	{
		cout << guessCounter << ", Not too bad, but I think you can do better.." << endl;
	}
	else if (guessCounter == 9 || guessCounter == 10)
	{
		cout << guessCounter << " tries! You can do better than that!" << endl;
	}
	else if (guessCounter > 10)
	{
		cout << guessCounter << " guesses? What a terrible score!" << endl << endl;
	}

	//quickly sort and display highscores
	scoreSort(p1);

	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl;
	cout << "----------  HIGH SCORES ------------" << endl;
	cout << "------------------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << p1[i].fName << " " << p1[i].lName << " " << p1[i].score << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl;

	//save new high scores list
	ofstream output;
	output.open("highScores.txt");
	for (int i = 0; i < 10; i++)
	{
		output << p1[i].fName << " " << p1[i].lName << " " << p1[i].score << endl;
	}
	


    return 0;
}

