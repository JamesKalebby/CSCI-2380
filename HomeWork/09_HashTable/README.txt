
Implement a "chaining" hash table.  Use your linked list class from homework 8.  You may use the "hello world" of hash functions, or a more advanced hash function of your choice.


class hashTable
{
private:
	//an array of linked lists (use your linked list class from homework 8)
	studentList * table;

	//size of table
	unsigned int tableSize;

	//number of students in data stucture
	unsigned int numStudents;

public:
	//create a table of some hard coded size of your choice
	hashTable();

	//create a table of a given size
	hashTable(unsigned int size);

	//insert s into hash table.  Store by hashing the student's id number.
	//Run time must be: O(1)
	void insert(student s);

	//remove student with given id from table
	//Run time:  Average case O(1 + numStudents/tableSize)
	void remove(unsigned int id);

	//Change the gpa of the student with given id number to newGPA
	//Run time:  Average case O(1 + numStudents/tableSize)
	void updateGPA(unsigned int idnumber, double newGPA);

	//lookup up and return copy of student with given id.
	//Run time: Average case O(1 + numStudents/tableSize)
	student getStudent(unsigned int id);

	//Change the size of your table!  newSize may be bigger or smaller that the current size.
	//Run time?
	void resize(unsigned int newSize);

	//Resize your table to an "optimal" choice based on the
	//current number of entries.  If you make it too large, you waste space.
	//If you make it too small, your searches are slow.  Pick a value
	//that is perfect.  Include in comments the reasoning for your
	//resizing choice.
	void optimalResize();
};