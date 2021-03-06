// hw13_wordPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "dGraph.h"

using namespace std;


int main()
{
	cout << "Choose two words of the same length: " << endl;

	string startWord;
	string endWord;

	cin >> startWord >> endWord;
	cout << endl << endl;

	//open dictionary
	ifstream dictionary;
	dictionary.open("largedictionary.txt");
	string word;
	int wordLength;
	wordLength = startWord.length();

	//build a graph of words equivalent in length
	directedGraph wordGraph;
	while (dictionary >> word)
	{
		if (word.length() == wordLength)
		{
			wordGraph.addVertex(word);
		}
	}
	dictionary.close();

	//get edges set up
	wordGraph.edgeBuilder();

	cout << "The following is a valid path from " << startWord << " to " << endWord << endl;
	//find word path
	wordGraph.wordPath(endWord, startWord);

    return 0;
}

