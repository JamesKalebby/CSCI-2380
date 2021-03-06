// hw11_2380.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "selectionSort.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include "radix.h"

using namespace std;

int main()
{
	ifstream numFile;
	numFile.open("numbers.txt");
	int size = 10000000;
	unsigned int * numArr = new unsigned int[size];

	for (int i = 0; i < size; i++)
	{
		numFile >> numArr[i];
	}
	numFile.close();


	clock_t start = clock();
	//selectionSort(numArr, size);
	//mergeSort(numArr, size);
	//heapSort(numArr, 0, size);
	//quickSort(numArr, 0, size);
	radixSort(numArr, size);

	clock_t end = clock();

	cout << end - start;
	
	ofstream ssFile;
	ssFile.open("Sorted.txt");

	for (int i = 0; i < size; i++)
	{
	ssFile << numArr[i] << endl;
	}
	
	ssFile.close();
	

	return 0;
}

