#include <iostream>
#include <string>
using namespace std;

/*
Implement the "studentList" data structure with a doubly linked list implementation.

You must implement all methods and they must work as described in the comments.  You must also achieve the stated run times, and know the big-Oh run times for each of your methods.
*/


class student
{
public:
	string name;
	unsigned int id;
	double gpa;

	student()
	{
		name = "ghost";
		id = 0;
		gpa = 0;
	}
	student(string _name, unsigned int _id, double _gpa)
	{
		id = _id;
		gpa = _gpa;
		name = _name;
	}
};

class studentList
{
private:
	//Implement a doubly linked list of students

	class node
	{
	public:
		student data;
		node * next;
		node * prev;

		node(student x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node * head;
	node * tail;

public:
	studentList();

	//add a student to the list.
	//Must run in O(1) time.
	void insert(student s);

	//find the student with the given id number and return it
	//What is the worst case run time of this?
	//What is the average case run time of this?
	student retrieveStudent(unsigned int idnumber);

	//Change the gpa of the student with given id number to newGPA
	//What is the run time?
	void updateGPA(unsigned int idnumber, double newGPA);

	//Add all students from otherlist to this list.
	//otherlist should be empty after this operation.
	//Must run in O(1) time.
	void mergeList(studentList &otherlist);

	//create a list of students whose gpa is at least minGPA.
	//Return this list.  The original list should
	//not be modified (do not remove the students from the original list).
	//Run time?
	studentList honorRoll(double minGPA);

	//sort the list by the given field ("name", "id", or "gpa").
	//Run time?
	void sort(string field);

	//Print out each student in the list.  This is mainly for testing purposes.
	void printList();
};