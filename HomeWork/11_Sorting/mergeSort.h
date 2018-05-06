#pragma once
//FROM CLASS NOTES***
void merge(unsigned int arry[], int s1, int e1, int s2, int e2)
// merge 2 sorted listes, starting at s and ending in e respectively, into
// a single sorted list.
{
	unsigned int * newArray;
	newArray = new unsigned int[e2 - s1 + 1];    // dynamically allocate a new array

	int index1 = s1;
	int index2 = s2;
	int newIndex = 0;
	while (index1 <= e1 && index2 <= e2)
	{
		if (arry[index1] <= arry[index2])
		{
			newArray[newIndex] = arry[index1];
			index1++;
		}
		else
		{
			newArray[newIndex] = arry[index2];
			index2++;
		}
		newIndex++;
	}

	if (index1 <= e1)
	{
		for (int i = index1; i <= e1; i++)
		{
			newArray[newIndex] = arry[i];
			newIndex++;
		}
	}

	else
	{
		for (int i = index2; i <= e2; i++)
		{
			newArray[newIndex] = arry[i];
			newIndex++;
		}
	}

	// copy newArray values to input array
	for (int i = s1; i <= e2; i++)
	{
		arry[i] = newArray[i - s1];
	}

	delete[] newArray;
}

void mSort(unsigned int arry[], int start, int end)
//sort array from index start to index end
{
	int len = end - start + 1;
	if (len > 1)
	{
		mSort(arry, start, start + len / 2 - 1);		//sort left half
		mSort(arry, start + len / 2, end);				//sort right half
		merge(arry, start, start + len / 2 - 1, start + len / 2, end);
	}
}

void mergeSort(unsigned int * arr, int size)
{
	mSort(arr, 0, size);
}