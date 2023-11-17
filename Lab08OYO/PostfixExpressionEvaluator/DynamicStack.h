/* Kyle Tranfaglia
 * COSC220 - Lab08 - OYO - Ex.1
 * 04/10/2023
 * Dynamic Stack Object and template Declaration and Implementation
*/
#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include <iostream>

using namespace std;

// Templated Dynamic Stack Class
template<class T>
class DynamicStack {
private:
    // Linked List node member object created with a constructor and all members set to public
    class ListNode {
    public:
        T value;
        ListNode *next;

        // Constructor for linked list node
        ListNode(T nodeValue) {
            value = nodeValue;
            next = nullptr;
        }
    };
	ListNode *top; // Pointer to the top stack (the head)
	int size; // Variable to track size of stack
public:
	// Constructor
	DynamicStack();

	// Destructor
	~DynamicStack();

	// Stack Mutators and other functions
	void push(T);
	void pop(T&);
	bool isEmpty();
	void clear();
	int getSize();
	T getTop();
	void PrintStack(bool status = false);
};
// Constructor
template<class T>
DynamicStack<T>::DynamicStack() {
	top = nullptr;
	size = 0;
}
// Destructor
template<class T>
DynamicStack<T>::~DynamicStack() {
	ListNode *nodePtr = top; // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// While nodePtr is not at the end of the list...
	while (nodePtr) {
		nextNode = nodePtr->next; // Sets node as the following node
		delete nodePtr;
		nodePtr = nextNode; // sets node as current top node (node below top before top was deleted)
	}
}
// Function to push the parameter value sent in to the top of the stack
template<class T>
void DynamicStack<T>::push(T item) {
    ListNode *newNode = new ListNode(item); // Allocates memory for a new node of value with construtor for the linked list and points to it
    
	// Checks if the node is empty, if so, it sets the top to newNode, otherwise, NewNode is linked to top and then set as new top
	if (isEmpty())
		top = newNode;
	else {
		newNode->next = top; // New node is linked to top node 
		top = newNode; // New top is set to new node
	}
	size++;
}
// Function to remove an item from the top of the stack and updates reference parameter with item removed (top)
template<class T>
void DynamicStack<T>::pop(T &item) {
	// Checks if the node is empty, if so, it prints that to console, otherwise, item being deleted is stored and a temporary ptr is used to delete the top node
	if (isEmpty())
		cout << "The stack is empty.\n";
	else {
        item = top->value; // Value of top node, to be deleted, is captured by reference variable
        ListNode *nodePtr = top; // Temporary pointer to keep track of top node to be deleted
	    top = nodePtr->next; // Top node is set to the following node
		delete nodePtr;
		size--;
	}
}
// Function to return true if the array is empty (there is not a top...it points to nullptr), or otherwise, returns false
template<class T>
bool DynamicStack<T>::isEmpty() {
	return (!top);
}
// Function to clear the contents of the list by deleting all nodes similar to deconstructor, but the object is not deleted
template<class T>
void DynamicStack<T>::clear() {
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	nodePtr = top; // Sets positional pointer varaiable to top of list

	// While nodePtr is not at the end of the list...
	while (nodePtr) {
		nextNode = nodePtr->next; // Save a pointer to the next node.
		delete nodePtr; // Delete the current node.
		nodePtr = nextNode; // Position nodePtr at the next node.
	}
	size = 0;
    top= nullptr; // Sets the head to nullptr as there is currently no first ele
}
// Function to return the size of the stack
template<class T>
int DynamicStack<T>::getSize() {
	return size;
}
// Function to return the value at the top of the stack
template<class T>
T DynamicStack<T>::getTop() {
	return top->value;
}
// Function to return the value at the top of the stack
template<class T>
void DynamicStack<T>::PrintStack(bool status) {
	ListNode *nodePtr = top; // Traverssing pointer set to head
	// Checks what format to print stack
	if (status) {
		// Loop to traverse list until nodePtr = nullptr and prints each element from top to bottom each on a new line
		while (nodePtr) {
			cout << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}
	}
	else {
		// Loop to traverse list until nodePtr = nullptr and prints each element from top to bottom with a space between
		while (nodePtr) {
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

#endif