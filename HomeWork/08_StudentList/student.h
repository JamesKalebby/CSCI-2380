#pragma once
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