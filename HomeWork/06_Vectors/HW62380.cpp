#include "stdafx.h"
#include <iostream>
#include <string>
//#include <vector>		//replace this with your own class when ready
#include "myVector.h"	//include this instead of the stl vector class when ready
using namespace std;


//Part 1:  Run the test code using the stl vector class.  Make sure you understand the output
//		   and how the vector class works.
//Part 2:  Create your own vector class (in the file "myVector.h").  To test your vector class,
//		   Swap the #include statements above so that the test code uses your vector class instead of the stl vector class.
//         
//		   YOU MAY NOT CHANGE ANY PART OF THE TEST CODE other than swapping the included files.
//         Your vector class must yield the exact same results from the test code as the stl vector class,
//         with the following exceptions: The "capacity" method may return different values (ie, you may choose any resizing method you want,
//		   but you should consider what is the smartest approach with respect to efficiency).  Additionally, for the 0-parameter constructor and
//		   the 1-parameter, you do not need to initialize the values of the vector items (but you must for the 2-parameter constructor).
//         Beyond these items, your code must behave the same as for the stl vector.



int main()
{
	vector<int> myvecA;
	vector<int> myvecB(10);
	vector<int> myvecC(5, -9);
	vector<string> myvecD(6, "Are we there yet?");

	//The size method should return how many items, abstractly,
	//the vector currently holds. 
	cout << "Vector A size: " << myvecA.size() << endl;
	cout << "Vector B size: " << myvecB.size() << endl;
	cout << "Vector C size: " << myvecC.size() << endl;
	cout << "Vector D size: " << myvecD.size() << endl;

	//Capacity should report how large the array holding the items is.
	//This size will be at least that of 'size()', but could be larger.
	cout << "Vector A capacity: " << myvecA.capacity() << endl;
	cout << "Vector B capacity: " << myvecB.capacity() << endl;
	cout << "Vector C capacity: " << myvecC.capacity() << endl;
	cout << "Vector D capacity: " << myvecD.capacity() << endl;

	//You can access the items in the array
	//with the '[]' operator.

	cout << endl;
	cout << "Vector B: " << endl;
	myvecB[3] = 43;
	myvecB[7] = 17;
	for (int i = 0; i<myvecB.size(); i++)
		cout << myvecB[i] << endl;

	cout << endl;
	cout << "Vector C: " << endl;
	myvecC[2] = 50;
	for (int i = 0; i<myvecC.size(); i++)
		cout << myvecC[i] << endl;

	cout << endl;
	cout << "Vector D: " << endl;
	myvecD[5] = "Shut up kids.";
	for (int i = 0; i<myvecD.size(); i++)
		cout << myvecD[i] << endl;


	//An important ability of vectors is the ability to push items to the back
	//of the vector, which may require increasing the capacity behind the scenes.
	for (int i = 0; i<16; i++)
		myvecA.push_back(2380 + i);
	cout << endl;
	cout << "Vector A's size and capacity:" << endl;
	cout << "Vector A size: " << myvecA.size() << endl;
	cout << "Vector A capacity: " << myvecA.capacity() << endl;


	//vector's also have full stack functionality.  Consider the "pop_back" method:
	for (int i = 0; i<10; i++)
	{
		cout << "About to pop: " << myvecA.back() << endl;
		myvecA.pop_back();
	}

	cout << endl;
	cout << "Vector A's size and capacity:" << endl;
	cout << "Vector A size: " << myvecA.size() << endl;
	cout << "Vector A capacity: " << myvecA.capacity() << endl;

	//Here is some addtional demo of the [] operator and how it works,
	//as well as the "push_back" method.
	
	cout << endl;
	for (int i = 0; i<5; i++)
		myvecB[i] = i * 10;

	myvecB.push_back(9990);
	myvecB.push_back(9991);
	myvecB.push_back(9992);
	myvecB.push_back(9993);
	myvecB.push_back(9994);

	for (int i = 0; i<myvecB.size(); i++)
		cout << myvecB[i] << endl;


	//Now we will see, for a large example, how the vector adjusts its capacity:
	cout << endl;
	int max = 100;
	for (int i = 0; i<max; i++)
	{
		int x = i * 10000;
		myvecB.push_back(x);
		cout << "Pushing: " << x << ", size: " << myvecB.size() << ", capacity: " << myvecB.capacity() << endl;
	}
	

	return 0;
}