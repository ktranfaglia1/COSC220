/* Kyle Tranfaglia
 * COSC220 - Lab08 - Ex.1
 * 04/04/2023
 * Static Stack Object and template Declaration and Implementation
*/
#ifndef StaticSTACK_H
#define StaticSTACK_H

#include <iostream>

using namespace std;

// Templated Static Stack Class
template<class T>
class StaticStack {
private:
	T *stack;
	int size;
	int top;

public:
	//Constructor
	StaticStack(int sz = 10);

	// Copy constructor
	StaticStack(const StaticStack&);

	// Destructor
	~StaticStack();

	// Stack operations
	void push(T);
	void pop(T&);
	bool isFull();
	bool isEmpty();
	void PrintStack(bool status = false);
	int getSize();
	int getCapacity();
	int topPos();
	T topVal();
};
// Constructor
template<class T>
StaticStack<T>::StaticStack(int sz) {
	stack = new T[sz];
	size = sz;
	top = -1;
}
// Copy Constructor
template<class T>
StaticStack<T>::StaticStack(const StaticStack &obj) {
	// Checks size of assignment object, if empty sets pointer to nullptr for pointer control, otherwise creates array of identical size in heap
	if (obj.top == -1)
		stack = nullptr;
	else
		stack = new T[obj.size];

	size = obj.size; // Copy size
	top = obj.top; // Copy top

	// Copy each index of stack items in order
	for (int i = 0; i < size; i++)
		stack[i] = obj.stack[i];
	
}
// Destructor
template<class T>
StaticStack<T>::~StaticStack() {
	delete[] stack;
}
// Function to push an item to the top of the stack (back of the array)
template<class T>
void StaticStack<T>::push(T item) {
	// Pushes item to back of array and increments the top index tracker if the array is not full, otherwise only a message is displayed
	if (isFull())
		cout << "The stack is full" << endl;
	else 
		stack[++top] = item;
}
// Function to remove an item from the top of the stack (back of the array) and updates reference parameter with item removed (top)
template<class T>
void StaticStack<T>::pop(T &item) {
	// Removes item from back of array and decrements the top index tracker if the array is not empty, otherwise only a message is displayed
	if (isEmpty())
		cout << "The stack is empty" << endl;
	else 
		item = stack[top--];
}
// Function to return true if the array is full, or otherwise, returns false
template<class T>
bool StaticStack<T>::isFull() {
	return (top == size - 1);
}
// Function to return true if the array is empty, or otherwise, returns false
template<class T>
bool StaticStack<T>::isEmpty() {
	return (top == -1);
}
// Function to print the entire stack in order from the bottom to top of the stack 
template<class T>
void StaticStack<T>::PrintStack(bool status) {
	// Checks what format to print stack
	if (status) {
		// Loop to print out each element starting from bottom to top of stack each on a new line
		for (int i = 0; i <= top; i++)
			cout << stack[i] << endl;
	}
	else {
		// Loop to print out each element starting from bottom to top of stack with a space between
		for (int i = 0; i <= top; i++)
			cout << stack[i] << " ";
		cout << endl;
	}
}
// Function to return the size of the stack
template<class T>
int StaticStack<T>::getSize() {
	return top + 1;
}
// Function to return the size of the stack
template<class T>
int StaticStack<T>::getCapacity() {
	return size;
}
// Function to return the position of the top
template<class T>
int StaticStack<T>::topPos() {
	return top;
}
// Function to return the value at the top of the stack
template<class T>
T StaticStack<T>::topVal() {
	return stack[top];
}

#endif