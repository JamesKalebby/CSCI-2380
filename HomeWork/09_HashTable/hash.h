//Implement a "chaining" hash table.Use your linked list class from homework 8.  You may use the "hello world" of hash functions, or a more advanced hash function of your choice.
#include "studentList.h"
#include <ctime>

class hashTable
{
private:
	//an array of linked lists (use your linked list class from homework 8)
	studentList * table;

	//size of table
	unsigned int tableSize;

	//number of students in data stucture
	unsigned int numStudents;

	//randomized hash key
	const int hash = time(NULL);

	int key;

public:
	//create a table of some hard coded size of your choice
	hashTable() {
		table = new studentList[10];
		tableSize = 10;
		numStudents = 0;
		key = 0;
	}

	//create a table of a given size
	hashTable(unsigned int size) {
		table = new studentList[size];
		tableSize = size;
		numStudents = 0;
	}

	//assumes all id's are 6 digits long and adds the digits together
	int addID(unsigned id)
	{
		int array[6];
		int total = 0;

		for (int i = 5; i >= 0; i--) {
			array[i] = id % 10;
			id /= 10;
		}
		for (int i = 0; i < 6; i++)
		{
			total = total + array[i];
		}
		return total;
	}

	//generate a key
	int makeKey(unsigned int id)
	{
		int idSum = addID(id);
		key = (idSum * hash) % tableSize;
		return key;
	}

	//insert s into hash table.  Store by hashing the student's id number.
	//Run time must be: O(1)
	void insert(student s) 
	{
		key = makeKey(s.id);
		table[key].insert(s);
		numStudents++;
	}

	//remove student with given id from table
	//Run time:  Average case O(1 + numStudents/tableSize)
	void remove(unsigned int id) {
		key = makeKey(id);
		table[key].remove(id);
		numStudents--;
	}

	//Change the gpa of the student with given id number to newGPA
	//Run time:  Average case O(1 + numStudents/tableSize)
	void updateGPA(unsigned int idnumber, double newGPA) {
		key = makeKey(idnumber);
		table[key].updateGPA(idnumber, newGPA);
	}

	//lookup up and return copy of student with given id.
	//Run time: Average case O(1 + numStudents/tableSize)
	student getStudent(unsigned int id) {
		key = makeKey(id);
		return table[key].retrieveStudent(id);
	}

	//Change the size of your table!  newSize may be bigger or smaller that the current size.
	//Run time? O(n) has to get each item in the list and insert it into the new list
	void resize(unsigned int newSize)
	{
		hashTable temp(newSize);

		for (unsigned int i = 0; i < tableSize; i++)
		{
			studentList tempList = table[i];

			while (!tempList.empty())
			{
				temp.insert(tempList.pop());

			}
		}

		delete[] table;
		table = temp.table;
		tableSize = newSize;
		numStudents = temp.numStudents;
	}

	//Resize your table to an "optimal" choice based on the
	//current number of entries.  If you make it too large, you waste space.
	//If you make it too small, your searches are slow.  Pick a value
	//that is perfect.  Include in comments the reasoning for your
	//resizing choice.
	void optimalResize() {
		unsigned int size = log(numStudents) / log(2);
		resize(size);
	}
	//my reasoning for this resize is as follows: So long as my hash is properly spreading out the data,
	//it should take on average log(n) steps to retreive data from the new table

	void printTable()
	{
		for (unsigned int i = 0; i < tableSize; i++)
		{
			cout << "list " << i << ": " << endl;
			table[i].printList();
		}
	}
};
