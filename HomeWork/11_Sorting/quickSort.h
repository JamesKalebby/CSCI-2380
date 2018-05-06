#pragma once
#include <algorithm>
#include <iostream>

using namespace std;
//AN UPDATED VERSION OF MY QUICK SORT FROM 1370
int partition(unsigned int items[], int start, int end)
{
	int pIndex, j, k;
	unsigned int p;
	p = items[end];
	pIndex = end;
	j = start - 1;
	k = start;

	while (k <= end)
	{
		if (items[k] < p)
		{
			j++;
			swap(items[j], items[k]);
			k++;
		}
		else
		{
			k++;
		}
	}
	j++;
	swap(items[j], items[pIndex]);

	return j;
}

void quickSort(unsigned int * items, int start, int end)
{
	if (end <= start)
	{

	}
	else
	{
		int p = partition(items, start, end);
		quickSort(items, start, p - 1);
		quickSort(items, p + 1, end);
	}
}