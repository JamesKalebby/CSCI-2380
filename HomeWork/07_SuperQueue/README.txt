#include <iostream>
#include <string>
#include <superQueue>
using namespace std;

///////////////////////////////////////////////////////
// Implement a "superQueue" using a doubly linked list.
// 
// Create a class superQueue with methods that work
// as specified by the test program below.  Your superQueue
// must be a doubly linked list with a head and tail pointer. 
///////////////////////////////////////////////////////

int main()
{
	//It's a stack!!!
	superQueue<string> pancakes;

	pancakes.push("mustard");
	pancakes.push("captaincrunchy");
	pancakes.push("pokemon");
	pancakes.push("beef");
	pancakes.push("pita");
	pancakes.push("smurf");
	pancakes.push("mightcore");
	pancakes.push("egg");
	pancakes.push("rotten");
	pancakes.push("tomato");
	pancakes.push("pizza");
	pancakes.push("carrot");
	pancakes.push("cheese");
	pancakes.push("cinamon");
	pancakes.push("chocochip");
	pancakes.push("blueberry");
	pancakes.push("strawberry");
	pancakes.push("original");

	cout << pancakes.pop() << endl; //original
	cout << pancakes.pop() << endl; //strawberry

	pancakes.push("banananana");
	cout << pancakes.pop() << endl; //bananananana
	cout << pancakes.pop() << endl; //blueberry


	//Review overloading operators:
	cout << pancakes[5] << endl;   //smurf
	cout << pancakes[2] << endl;   //pokemon


	while (!pancakes.empty())
	{
		cout << "eating: " << pancakes.pop() << endl;
	}

	//It's a queue!!!!
	superQueue<int> numberQueue;
	for (int i = 0; i<50; i++)
		numberQueue.enqueue(i);
	for (int i = 0; i<20; i++)
		cout << "Dequeing: " << numberQueue.dequeue() << endl;

	for (int i = 50; i<60; i++)
		numberQueue.enqueue(i);

	while (!numberQueue.empty())
		cout << "Dequeing: " << numberQueue.dequeue() << endl;


	//It's even a priorityQueue!!!!
	superQueue<double> pq;

	pq.insert(57);
	pq.insert(32);
	pq.insert(105);
	pq.insert(17);

	cout << pq.extractMin() << endl; //17
	cout << pq.extractMin() << endl; //32
	cout << endl;

	pq.insert(68);
	pq.insert(5);
	pq.insert(43);

	cout << pq.extractMin() << endl; //5
	cout << pq.extractMin() << endl; //43
	cout << pq.extractMin() << endl; //57
	cout << endl;

	pq.insert(120);
	pq.insert(500);
	pq.insert(3);
	pq.insert(73);
	pq.insert(29);

	//3 29 68 73 105 120 500
	while (!pq.empty())
	{
		cout << pq.extractMin() << endl;
	}
	cout << endl;

	return 0;
}