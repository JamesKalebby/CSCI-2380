#pragma once
#include "student.h"
#include "node.h"
#include <string>
#include "nameSort.h"
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
	studentList()
	{
		head = NULL;
		tail = NULL;
	}

	//add a student to the list.
	//Must run in O(1) time.
	void insert(student s)
	{
		if (head == NULL)
		{
			head = new node(s);
			tail = head;
		}
		else
		{
			tail->next = new node(s);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	//find the student with the given id number and return it
	//What is the worst case run time of this? 
	//Worst case is O(n) because it might have to go all the way to the end of the list

	//What is the average case run time of this?
	//O(n) as well
	student retrieveStudent(unsigned int idnumber)
	{
		node * current = head;
		while (current != NULL)
		{
			if (current->data.id == idnumber)
			{
				return current->data;
			}
			current = current->next;
		}
	}

	//Change the gpa of the student with given id number to newGPA
	//What is the run time? O(n) again.
	void updateGPA(unsigned int idnumber, double newGPA)
	{
		node * current = head;
		while (current != NULL)
		{
			if (current->data.id == idnumber)
			{
				current->data.gpa = newGPA;
			}
			current = current->next;
		}
	}

	//Add all students from otherlist to this list.
	//otherlist should be empty after this operation.
	//Must run in O(1) time.
	/*
	//realized this was inefficient and I could just point to the head of the next list
	void remove(studentList &otherlist)
	{
		node * p = otherlist.head;
		otherlist.head = otherlist.head->next;
		if (head == NULL)
			tail = NULL;
		delete p;
	}
	void mergeList(studentList &otherlist)
	{
		node * current = otherlist.head;
		while (current != NULL)
		{
			insert(current->data);
			remove(otherlist);
			current = otherlist.head;
		}
	}
	*/

	void mergeList(studentList &otherlist)
	{
		tail->next = otherlist.head;
		otherlist.head->prev = tail;
		tail = otherlist.tail;
		otherlist.head = NULL;
		otherlist.tail = NULL;
	}

	//create a list of students whose gpa is at least minGPA.
	//Return this list.  The original list should
	//not be modified (do not remove the students from the original list).
	//Run time? O(n)
	studentList honorRoll(double minGPA)
	{
		node * current = head;
		studentList hRoll;
		while (current != NULL)
		{
			if (current->data.gpa >= minGPA)
			{
				hRoll.insert(current->data);
			}
			current = current->next;
		}
		return hRoll;
	}

	//sort the list by the given field ("name", "id", or "gpa").
	//Run time? O(n log n)
	void sort(string x)
	{
		if (x == "name")
		{
			nameSort(&head);
		}
		
		else if (x == "id")
		{
			idSort(&head);
		}
		else if (x == "gpa")
		{
			gpaSort(&head);
		}
	}

	void prevFix()
	{
		node * current = head->next;
		node * lag = head;
		while (current != NULL)
		{
			current->prev = lag;
			current = current->next;
			lag = lag->next;
		}
		tail = lag;
		head->prev = NULL;
	}
	
	node * nameMerge(node * first, node * second)
	{
		node * t1;
		node * t2;
		node * temp;

		// Return if first list is empty.
		if (first == NULL)
			return second;

		// Return if second list is empty.
		if (second == NULL)
			return first;

		t1 = first;

		// A loop to traverse the second list, to merge the nodes to first in sorted way.
		while (second != NULL)
		{
			// Taking head node of second list as t2.
			t2 = second;

			// Shifting second list head to the next.
			second = second->next;
			t2->next = NULL;

			// If the data value is lesser than the head of first list add that node at the beginning.
			if (first->data.name > t2->data.name)
			{
				t2->next = first;
				first = t2;
				t1 = first;
				continue;
			}

			// Traverse the first list.
		flag:
			if (t1->next == NULL)
			{
				t1->next = t2;
				t1 = t1->next;
			}
			// Traverse first list until t2->data more than node's data.
			else if (t1->next->data.name <= t2->data.name)
			{
				t1 = t1->next;
				goto flag;
			}
			else
			{
				// Insert the node as t2->data is lesser than the next node.
				temp = t1->next;
				t1->next = t2;
				t2->next = temp;
			}
		}

		// Return the head of new sorted list.
		return first;
	}

	void nameSort(node ** headRef)
	{
		node * first;
		node * second;
		node * temp;
		first = *headRef;
		temp = *headRef;

		// Return if list have less than two nodes.
		if (first == NULL || first->next == NULL)
		{
			return;
		}
		else
		{
			// Break the list into two halves as first and second as head of list.
			while (first->next != NULL)
			{
				first = first->next;
				if (first->next != NULL)
				{
					temp = temp->next;
					first = first->next;
				}
			}
			second = temp->next;
			temp->next = NULL;
			first = *headRef;
		}

		// Implementing divide and conquer approach.
		nameSort(&first);
		nameSort(&second);

		// Merge the two part of the list into a sorted one.      
		*headRef = nameMerge(first, second);
		//fix the prev pointers
		prevFix();
	}

	node * idMerge(node * first, node * second)
	{
		node * t1;
		node * t2;
		node * temp;

		// Return if first list is empty.
		if (first == NULL)
			return second;

		// Return if second list is empty.
		if (second == NULL)
			return first;

		t1 = first;

		// A loop to traverse the second list, to merge the nodes to first in sorted way.
		while (second != NULL)
		{
			// Taking head node of second list as t2.
			t2 = second;

			// Shifting second list head to the next.
			second = second->next;
			t2->next = NULL;

			// If the data value is lesser than the head of first list add that node at the beginning.
			if (first->data.id > t2->data.id)
			{
				t2->next = first;
				first = t2;
				t1 = first;
				continue;
			}

			// Traverse the first list.
		flag:
			if (t1->next == NULL)
			{
				t1->next = t2;
				t1 = t1->next;
			}
			// Traverse first list until t2->data more than node's data.
			else if (t1->next->data.id <= t2->data.id)
			{
				t1 = t1->next;
				goto flag;
			}
			else
			{
				// Insert the node as t2->data is lesser than the next node.
				temp = t1->next;
				t1->next = t2;
				t2->next = temp;
			}
		}

		// Return the head of new sorted list.
		return first;
	}

	void idSort(node ** headRef)
	{
		node * first;
		node * second;
		node * temp;
		first = *headRef;
		temp = *headRef;

		// Return if list have less than two nodes.
		if (first == NULL || first->next == NULL)
		{
			return;
		}
		else
		{
			// Break the list into two halves as first and second as head of list.
			while (first->next != NULL)
			{
				first = first->next;
				if (first->next != NULL)
				{
					temp = temp->next;
					first = first->next;
				}
			}
			second = temp->next;
			temp->next = NULL;
			first = *headRef;
		}

		// Implementing divide and conquer approach.
		idSort(&first);
		idSort(&second);

		// Merge the two part of the list into a sorted one.      
		*headRef = idMerge(first, second);
		//Fix the prev pointers
		prevFix();
	}

	node * gpaMerge(node * first, node * second)
	{
		node * t1;
		node * t2;
		node * temp;

		// Return if first list is empty.
		if (first == NULL)
			return second;

		// Return if second list is empty.
		if (second == NULL)
			return first;

		t1 = first;

		// A loop to traverse the second list, to merge the nodes to first in sorted way.
		while (second != NULL)
		{
			// Taking head node of second list as t2.
			t2 = second;

			// Shifting second list head to the next.
			second = second->next;
			t2->next = NULL;

			// If the data value is lesser than the head of first list add that node at the beginning.
			if (first->data.gpa < t2->data.gpa)
			{
				t2->next = first;
				first = t2;
				t1 = first;
				continue;
			}

			// Traverse the first list.
		flag:
			if (t1->next == NULL)
			{
				t1->next = t2;
				t1 = t1->next;
			}
			// Traverse first list until t2->data more than node's data.
			else if (t1->next->data.gpa >= t2->data.gpa)
			{
				t1 = t1->next;
				goto flag;
			}
			else
			{
				// Insert the node as t2->data is lesser than the next node.
				temp = t1->next;
				t1->next = t2;
				t2->next = temp;
			}
		}

		// Return the head of new sorted list.
		return first;
	}

	void gpaSort(node ** headRef)
	{
		node * first;
		node * second;
		node * temp;
		first = *headRef;
		temp = *headRef;

		// Return if list have less than two nodes.
		if (first == NULL || first->next == NULL)
		{
			return;
		}
		else
		{
			// Break the list into two halves as first and second as head of list.
			while (first->next != NULL)
			{
				first = first->next;
				if (first->next != NULL)
				{
					temp = temp->next;
					first = first->next;
				}
			}
			second = temp->next;
			temp->next = NULL;
			first = *headRef;
		}

		// Implementing divide and conquer approach.
		gpaSort(&first);
		gpaSort(&second);

		// Merge the two part of the list into a sorted one.      
		*headRef = gpaMerge(first, second);
		//Fix the prev pointers
		prevFix();
	}
	/*
	void sort(string field)
	{
		if (field == "name")
		{
			node * current = head;
			while (current != NULL)
			{
				node * j = current->next;
				string small = current->data.name;
				node * smallRef = current;
				while (j != NULL)
				{
					if (j->data.name < small)
					{
						small = j->data.name;
						smallRef = j;
					}
					j = j->next;
				}
				swap(current->data, smallRef->data);
				current = current->next;
			}
		}
		else
		{
			if (field == "id")
			{
				node * current = head;
				while (current != NULL)
				{
					node * j = current->next;
					unsigned int small = current->data.id;
					node * smallRef = current;
					while (j != NULL)
					{
						if (j->data.id < small)
						{
							small = j->data.id;
							smallRef = j;
						}
						j = j->next;
					}
					swap(current->data, smallRef->data);
					current = current->next;
				}
			}
			else
			{
				if (field == "gpa")
				{
					node * current = head;
					while (current != NULL)
					{
						node * j = current->next;
						double small = current->data.gpa;
						node * smallRef = current;
						while (j != NULL)
						{
							if (j->data.gpa > small)
							{
								small = j->data.gpa;
								smallRef = j;
							}
							j = j->next;
						}
						swap(current->data, smallRef->data);
						current = current->next;
					}
				}
			}
		}
	}
	*/

	//Print out each student in the list.  This is mainly for testing purposes.
	void printList()
	{
		node * current = head;
		while (current != NULL)
		{
			cout << current->data.name << endl;
			current = current->next;
		}
	}

	void printBackwards()
	{
		node * current = tail;
		while (current != NULL)
		{
			cout << current->data.name << endl;
			current = current->prev;
		}
	}

	string getTail()
	{
		return tail->data.name;
	}
};