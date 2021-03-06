// HW8_2380.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "studentList.h"
#include "student.h"
#include "node.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//creating a list of students
	studentList cs2380;

	student joey("joey", 420, 4.0);
	student cat("cat", 25, 3.99);

	cs2380.insert(joey);
	cs2380.insert(cat);

	cout << cs2380.retrieveStudent(420).name << " id: " << cs2380.retrieveStudent(420).id << " gpa: " << cs2380.retrieveStudent(420).gpa << endl;
	cout << cs2380.retrieveStudent(25).name << " id " << cs2380.retrieveStudent(25).id << " gpa: " << cs2380.retrieveStudent(25).gpa << endl << endl;

	cs2380.updateGPA(25, 1.4); //muahahahaha

	cout << cs2380.retrieveStudent(25).name << "'s new gpa: " << cs2380.retrieveStudent(25).gpa << endl;

	//creating new list to test merge list
	studentList cs1370;

	student rick("rick", 100, 4.0);
	student domingo("domingo", 999, 5.0);

	cs1370.insert(rick);
	cs1370.insert(domingo);

	cout << endl << endl;

	cout << "printing cs2380 list: " << endl;
	cs2380.printList();
	cout << endl << endl;

	cout << "printing cs1380 list: " << endl;
	cs1370.printList();
	cout << endl << endl;

	cs2380.mergeList(cs1370);
	cout << "printing cs2380 list after merge: " << endl;
	cs2380.printList();

	cout << endl << "attempting to print cs1380 list //should not have any nodes in it due to merge" << endl << endl;
	cs1370.printList();
	cout << "end of attempt" << endl;

	cout << endl << endl;

	studentList honorRoll = cs2380.honorRoll(3.5);

	cout << "printing honor roll list: " << endl;
	honorRoll.printList();

	cout << endl << "unsorted list: " << endl;

	cs2380.printList();
	
	cs2380.sort("name");
	cout << endl << "name sorted list: " << endl;
	cs2380.printList();
	cout << endl << "printing backwards" << endl;
	cs2380.printBackwards();
	cout << "done printing backwards: " << endl;

	
	cs2380.sort("id");
	cout << endl << "id sorted list:" << endl;
	cs2380.printList();

	cs2380.sort("gpa");
	cout << endl << "gpa sorted list" << endl;
	cs2380.printList();
	

	studentList bigList;
	student newStudent;
	
	for (int i = 0; i < 100000; i++)
	{
		bigList.insert(newStudent);
	}
	clock_t startTime, endTime;

	startTime = clock();
	bigList.sort("name");
	endTime = clock();

	cout << "It took roughly " << (endTime - startTime) / 1000 << " seconds, or " << endTime - startTime << " milliseconds, to sort 100,000 items" << endl;
	//bigList.printList();
	

    return 0;
}