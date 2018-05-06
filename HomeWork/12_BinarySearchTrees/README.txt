#include <iostream>
#include "binarySearchTree.h"
using namespace std;

int main()
{
	binarySearchTree tree;

	tree.insert(15);
	tree.insert(24);
	tree.insert(53);
	tree.insert(-3);
	tree.insert(23);
	tree.insert(77);
	tree.insert(100);
	tree.insert(17);
	tree.insert(33);
	tree.insert(5);
	tree.insert(-10);
	tree.insert(2);

	tree.displayInorder();
	tree.displayPreorder();
	tree.displayPostorder();

	//part 1:  warmup with some basic methods
	cout << "number of items: " << tree.numItems() << endl;
	cout << "number of leaves: " << tree.numLeaves() << endl;
	cout << "height: " << tree.getHeight() << endl;
	cout << "full nodes: << tree.fullNodes() << endl;

	//part 2: implement removal of smallest or largest items
	cout << tree.extractMin() << endl; //displays -10
	cout << tree.extractMin() << endl; //displays -3
	cout << tree.extractMax() << endl; //displays 100
	cout << tree.extractMax() << endl; //displays 77

	tree.display(); //verify above 4 values have been removed

	//part 3: implement a method that finds and removes a given value.
	tree.remove(33);
	tree.remove(15);
	tree.remove(5);

	tree.insert(43);

	tree.displayInorder(); //verify above 3 have been removed and insert still works.


	//part 4: Implement a level order traversal.  State the worst-case big-oh run time of your method.
	//A "level order" visits the items in order of level, ie, root first, then roots children, then root's grandchildren, etc.
	tree.levelOrderDisplay();


	//part 5: Write a constructor that takes as input an array of all the items to be inserted and builds the tree, but in a perfectly balanced way.
	double items[] = {15,24,53,-3,23,77,100,17,33,5,-10,2};

	binarySearchTree perfectTree(items, 12);

	perfectTree.displayInorder();
	
	cout << "number of items: " << perfectTree.numItems() << endl;
	cout << "number of leaves: " << perfectTree.numLeaves() << endl;
	cout << "height: " << perfectTree.getHeight() << endl;
	cout << "full nodes: << perfectTree.fullNodes() << endl;

	return 0;
}