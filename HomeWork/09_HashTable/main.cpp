#include "stdafx.h"
#include <iostream>
#include <string>
#include "hash.h"
#include "studentList.h"
#include "student.h"

using namespace std;

int main()
{
	student joey("Joey", 211901, 4.0);
	student cat("Cat", 182003, 4.0);
	student rick("Rick", 549721, 4.0);
	student domingo("Domingo", 654321, 4.0);


	hashTable studentTable;

	studentTable.insert(joey);
	studentTable.insert(cat);
	studentTable.insert(rick);
	studentTable.insert(domingo);

	studentTable.updateGPA(182003, 3.9);

	cout << studentTable.getStudent(182003).gpa << endl;

	studentTable.remove(211901);

	studentTable.resize(3);
	
	/*
	for (int i = 0; i < 64; i++)
	{
		student * newS = new student;
		studentTable.insert(*newS);
	}
	*/

	studentTable.optimalResize();

	cout << studentTable.getStudent(549721).name << endl;

	studentTable.printTable();

	studentTable.insert(joey);
	
	student tim("Tim", 657821, 3.0);
	student janie("Janie", 956564, 3.0);

	studentTable.insert(tim);
	studentTable.insert(janie);

	studentTable.optimalResize();

	cout << endl;

	studentTable.printTable();

	return 0;
}