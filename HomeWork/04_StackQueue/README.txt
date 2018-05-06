//////////////////////////////////////////////////////
// Topics: circular arrays, templated classes, dynamic arrays
//
// Implement a stackQueue using a
// circular array implementation as discussed in class.
// Your data structure must increase its array size dynamically
// if the array runs out of room.
//
// Abstractly, your stackQueue represents a list of items
// with a front and back from which items may be added
// or removed.  If you choose to add and remove from just
// one end, you effectively have a stack.  If you choose
// to add to the back and remove from the front, (or vice versa)
// you effectively have a queue, thus the name "stackQueue".
//
//
///////////////////////////////////////////////////////

template <class T>
class stackQueue
{
private:
    //declare your array variable and
    //any additional variables you need
    //to solve the problem

public:
    stackQueue()
    {}

    //Insert x to the "back" of the list of items.
    void addBack(T x)
    {}

    //Add x to the "front" of the list of items.
    void addFront(T x)
    {}

    //Remove and return the item currently at the "back" of the list
    T removeBack()
    {}

    //Remove and return the item currently at the "front" of the list
    T removeFront()
    {}

    //Is the stackQueue empty?
    bool empty()
    {}
};