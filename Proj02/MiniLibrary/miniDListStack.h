/* Kyle Tranfaglia
 * COSC220 - project2
 * 04/24/2023
 * Templated Doubly Linked List Stack Declaration and Implementation
*/
#ifndef MINIDLISTSTACK_H
#define MINIDLISTSTACK_H

#include <iostream> // For cout
#include "miniDList.h"
#include "RuntimeException.h"

using namespace std;

template <class DataType>
class miniDListStack {
private:
    miniDList<DataType> list;
public:
    miniDListStack();  // Constructor for ListStack
    miniDListStack(const miniDListStack<DataType> &); 	// Copy contstructor
    ~miniDListStack();  // Destructor

    int size() const;   // get the number of elements in the stack
    bool isEmpty() const;	// Check if the stack is empty
    const DataType& top() const ; // throw(StackEmpty);      //get the top emement without popping it
    void push(const DataType&);	// Pushes an object onto the stack
    void pop(); // throw(StackEmpty);	// Pop an object off the stack 
    void printStack() const;	// Prints the stack from the top, down

    miniDListStack<DataType>& operator=(const miniDListStack<DataType>&);  // Assignment operator
};

// implementations go below...

// Constructor ... nothing to do but default create object
template <class DataType>
miniDListStack<DataType>::miniDListStack() {
}
// Destructor ...  nothing is dynamically allocated by this class
template <class DataType>
miniDListStack<DataType>::~miniDListStack() {
}
// Copy constructor
template <class DataType>
miniDListStack<DataType>::miniDListStack(const miniDListStack<DataType> &obj) {
    list = obj.list; // Uses copy constructor of miniDList
}
// Overloaded assignment operator
template <class DataType>
miniDListStack<DataType>& miniDListStack<DataType>::operator=(const miniDListStack<DataType> &obj) {
    list = obj.list; // Overloaded assignment operator
    return *this;
}
// Function to return the size of the stack
template <class DataType>
int miniDListStack<DataType>::size() const {
    return list.size(); // Returns call to size function from miniDList
}
// Function to return a bool denoting if the stack is empty
template <class DataType>
bool miniDListStack<DataType>::isEmpty() const {
    return list.isEmpty(); // Returns call to isEmpty function from miniDList
}
// Function to return the front value of the queue
template <class DataType>
const DataType& miniDListStack<DataType>::top() const {
    return list.front(); // Returns call to front fucntion from miniDList
}
// Function to add an item to the stack ... front
template <class DataType>
void miniDListStack<DataType>::push(const DataType &item) {
    list.addFront(item); // Uses addFront function in miniDList
}
// Function to remove an item from the Stack ... front (FIFO)
template <class DataType>
void miniDListStack<DataType>::pop() {
    list.removeFront(); // Uses removeFront function in miniDList
}
// Function to display the stack from top to bottom
template <class DataType>
void miniDListStack<DataType>::printStack() const {
    list.display(); // Calls display function for miniDList
}

#endif