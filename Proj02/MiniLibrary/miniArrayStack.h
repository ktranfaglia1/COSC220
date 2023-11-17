/* Kyle Tranfaglia
 * COSC220 - project2
 * 04/24/2023
 * Templated Array Stack Declaration and Implementation
*/
#ifndef MINIARRAYSTACK_H
#define MINIARRAYSTACK_H

#include <iostream> // For cout
#include "RuntimeException.h"

using namespace std;

template <class DataType>
class miniArrayStack{
private:
    enum {DEF_CAPACITY = 100}; 	// Default stack capacity
    DataType* arr;	// The array of items
    int	capacity;	// The capacity of the current array
    int	top;	// The location of the top element
    int stackSize;  // number of elements in stack
public:
    miniArrayStack (int cap = DEF_CAPACITY);	// Constructor for ArrStack
    miniArrayStack(const miniArrayStack<DataType> &); 	// Copy contstructor
    ~miniArrayStack();	// Destructor

    int size() const;	// get the number of elements in the stack
    bool isEmpty() const;	// Check if the stack is empty
    const DataType& getTop() const; //throw(StackEmpty);       // get the top emement without popping it
    void push(const DataType&); //throw(StackFull);	// Pushes an object onto the stack
    void pop(); //throw(StackEmpty);	// Pop an object off the stack 
    void printStack() const; // Prints the stack from the top, down

    miniArrayStack<DataType>& operator=(const miniArrayStack<DataType>&);  // Assignment operator
};

// implementations go below...
// Constructor defaulted with a capacity of 100 if none provided
template <class DataType>
miniArrayStack<DataType>::miniArrayStack(int cap) {
    arr = new DataType[cap];
    capacity = cap;
	stackSize = 0;
	top = -1;
}
// Destructor
template <class DataType>
miniArrayStack<DataType>::~miniArrayStack() {
    delete [] arr;
}
// Copy Constructor
template <class DataType>
miniArrayStack<DataType>::miniArrayStack(const miniArrayStack<DataType> &obj) {
	arr = new DataType[obj.capacity]; // Dynamically allocated memory of object capacity for array pointer

    // Copies member variables
    capacity = obj.capacity;
	stackSize = obj.stackSize;
	top = obj.top;

	// Copy each index of stack items in order
	for (int i = 0; i < stackSize; i++)
		arr[i] = obj.arr[i];
}
// Overloaded assignment operator
template <class DataType>
miniArrayStack<DataType>& miniArrayStack<DataType>::operator=(const miniArrayStack<DataType>& obj) {
    delete [] arr;
	arr = new DataType[obj.capacity]; // Dynamically allocated memory of object capacity for array pointer

    // Copies member variables
    capacity = obj.capacity;
	stackSize = obj.stackSize;
	top = obj.top;

	// Copy each index of stack items in order
	for (int i = 0; i < stackSize; i++)
		arr[i] = obj.arr[i];

    return *this;
}
// Function to return size of the stack
template <class DataType>
int miniArrayStack<DataType>::size() const {
    return stackSize;
}
// Function to return a bool denoting if the stack is empty
template <class DataType>
bool miniArrayStack<DataType>::isEmpty() const {
    return (top == -1);
}
// Function to return the top value of the stack array
template <class DataType>
const DataType& miniArrayStack<DataType>::getTop() const {
    // If stack is empty, throw exception
    if (isEmpty())
        throw StackEmpty("Stack is Empty");

    return arr[top]; // returns value at index of top
}
// Function to push a value to the top of the stack
template <class DataType>
void miniArrayStack<DataType>::push(const DataType &item) {
    // If stack is full, throw exception
	if (top == capacity - 1)
        throw StackFull("Stack is Full");
	else {
	    arr[++top] = item; // Incremenets top and sets array at top to item parameter
        stackSize++;
    }
}
// Function to remove a value from the top of the stack
template <class DataType>
void miniArrayStack<DataType>::pop() {
    // If stack is empty, throw exception
    if (isEmpty())
        throw StackEmpty("Stack is Empty");
    else {
        top--; // Removes item by restricting array access, top decrements
        stackSize--;
    }
}
// Function to display the stack from top to bottom ... back to front ... with a space after each element
template <class DataType>
void miniArrayStack<DataType>::printStack() const {
    // Loop to print out each element starting from top to bottom of stack with a space between
    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

#endif