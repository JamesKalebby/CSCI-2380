#pragma once
#include <algorithm>
#include <iostream>

using namespace std;

void selectionSort(unsigned int * arr, int size)
{
	int minIndex;
	unsigned int minValue;
	for (int i = 0; i < size; i++)
	{
		minValue = arr[i];
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < minValue)
			{
				minValue = arr[j];
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}
}