#pragma once
#include <iostream>
#include <ctime>

class lList {
private:
	class node {
	public:
		unsigned int data;
		node * next;
		node(unsigned int x) {
			data = x;
			next = NULL;
		}
	};
	node * head;
public:
	lList() {
		head = NULL;
	}
	node * getHead() {
		return head;
	}

	void push(unsigned int x) {
		if (head == NULL)
		{
			head = new node(x);
		}
		else
		{
			node * current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = new node(x);
		}
	}

	unsigned int pop() {
		if (head == NULL)
			return NULL;
		else {
			unsigned int x = head->data;
			node * dN = head;
			head = head->next;
			delete dN;
			return x;
		}
	}
};

class hashTable {
private:
	lList * table;
	unsigned int tableSize;
	unsigned int numData;
	const int hash = time(NULL);
	int key;
public:
	hashTable() {
		table = new lList[10];
		tableSize = 10;
		numData = 0;
		key = 0;
	}

	hashTable(unsigned int size) {
		table = new lList[size];
		tableSize = size;
		numData = 0;
	}

	int makeKey(unsigned int x, int m, int n) {
		key = (x % m) / n;
		return key;
	}

	void insert(unsigned int x, int m, int n) {
		makeKey(x, m, n);
		table[key].push(x);
	}
	
	unsigned int pop(){
		int i = 0;
		flag:
		if (table[i].getHead() == NULL) 
		{
			i++;
			goto flag;
		}
			else
				return table[i].pop();
		}
};