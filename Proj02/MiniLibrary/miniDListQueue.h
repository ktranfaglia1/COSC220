/* Kyle Tranfaglia
 * COSC220 - project2
 * 04/24/2023
 * Templated Doubly Linked List Queue Declaration and Implementation
*/
#ifndef MINIDLISTQUEUE_H
#define MINIDLISTQUEUE_H

#include <iostream>     // For cout
#include "miniDList.h"
#include "RuntimeException.h"

using namespace std;

template <class DataType>
class miniDListQueue {
private:
    miniDList<DataType> list;
public:
    miniDListQueue ();	// Constructor 
    miniDListQueue(const miniDListQueue<DataType> &); // Copy Constructor
    ~miniDListQueue();	// Destructor

    int size() const;	// get the number of elements in the queue
    bool isEmpty() const;	// Check if the queue is empty
    void enqueue(const DataType& e); // Enqueue element at rear
    void dequeue(); //throw(QueueEmpty);	// dequeue element at front 
    const DataType& front() const; //throw(QueueEmpty); //return the front element but not remove
    void printQueue() const; // Prints the queue from the front to the rear

    miniDListQueue<DataType>& operator=(const miniDListQueue<DataType>&); // Assignment operator
};

// implementations go below...

// Constructor ... nothing to do but default create object
template <class DataType>
miniDListQueue<DataType>:: miniDListQueue() {
}
// Destructor ...  nothing is dynamically allocated by this class
template <class DataType>
miniDListQueue<DataType>::~miniDListQueue() {
}
// Copy constructor
template <class DataType>
miniDListQueue<DataType>::miniDListQueue(const miniDListQueue<DataType> &obj) {
    list = obj.list; // Uses copy constructor of miniDList
}
// Overloaded assignment operator
template <class DataType>
miniDListQueue<DataType>& miniDListQueue<DataType>::operator=(const miniDListQueue<DataType> &obj) {
    list = obj.list; // Uses Overloaded assignment operator of miniDList
    return *this;
}
// Function to return the size of the queue
template <class DataType>
int miniDListQueue<DataType>::size() const {
    return list.size(); // Returns call to size function from miniDList
}
// Function to return a bool denoting if the queue is empty
template <class DataType>
bool miniDListQueue<DataType>::isEmpty() const {
    return list.isEmpty(); // Returns call to isEmpty function from miniDList
}
// Function to return the front value of the queue
template <class DataType>
const DataType& miniDListQueue<DataType>::front() const {
    return list.front(); // Returns call to front fucntion from miniDList
}
// Function to add an item to the queue ... back
template <class DataType>
void miniDListQueue<DataType>::enqueue(const DataType &item) {
    list.addBack(item); // Uses addBack function in miniDList
}
// Function to remove an item from the queue ... front (FILO)
template <class DataType>
void miniDListQueue<DataType>::dequeue() {
    list.removeFront(); // Uses removeFront function in miniDList
}
// Function to display the queue from front to rear
template <class DataType>
void miniDListQueue<DataType>::printQueue() const {
    list.display(); // Calls display function for miniDList
}

#endif