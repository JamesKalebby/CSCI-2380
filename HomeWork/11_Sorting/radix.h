#include<iostream>
using namespace std;

//Source: Multiple YouTube videos including: https://www.youtube.com/watch?v=nu4gDuFabIM
//get the number of digits
int getMax(unsigned int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > mx)
		{
			mx = arr[i];
		}
	}
		return mx;
}

// count sort to be used by radix sort
void countSort(unsigned int arr[], int n, int exp)
{
	unsigned int * output = new unsigned int[n];
	int i;
	int count[10];

	for (int i = 0; i < 10; i++)
	{
		count[i] = 0;
	}

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}


	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++) 
	{
		count[i] += count[i - 1];
	}

	// send sorted numbers to output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that array contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
}

//radix uses count sort on each place value
void radixSort(unsigned int arr[], int n)
{
	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp);
	}

}