/* Kyle Tranfaglia
 * COSC220 - project2
 * 04/24/2023
 * Templated Array Queue Declaration and Implementation
*/
#ifndef MINIARRAYQUEUE_H
#define MINIARRAYQUEUE_H

#include <iostream>     // For cout
#include "RuntimeException.h"

using namespace std;

// use modular arithmetic "%" to save array space, like in-class code example
template <class DataType>
class miniArrayQueue {
private:
    enum {DEF_CAPACITY = 100}; 	// default queue capacity
    DataType* arr;		// The array of items
    int	capacity;	// The capacity of the current array
    int	front;	// The location of the front element
    int	rear;	// The location of the rear element
    int queueSize;  // number of elements in queue
public:
    miniArrayQueue (int cap = DEF_CAPACITY );	// Constructor 
    miniArrayQueue(const miniArrayQueue<DataType> &); // Copy Constructor
    ~miniArrayQueue();	//   Destructor

    int size() const;	// get the number of elements in the queue
    bool isEmpty() const; // Check if the queue is empty
    void enqueue(const DataType& e); //throw(QueueFull), Enqueue element at rear
    void dequeue(); //throw(QueueEmpty), dequeue element at front 
    const DataType& getFront() const;//throw(QueueEmpty), return the front element but not remove
    void printQueue() const;    // Prints the queue from the front to the rear

    miniArrayQueue<DataType>& operator=(const miniArrayQueue<DataType>&); // Assignment operator
};


//implementations go below...
// Constructor defaulted with a capacity of 100 if none provided
template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(int cap) {
    arr = new DataType[cap];
    capacity = cap;
	queueSize = 0;
	front = 0;
    rear = -1;
}
// Destructor
template <class DataType>
miniArrayQueue<DataType>::~miniArrayQueue() {
    delete [] arr;
}
// Copy Constructor
template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(const miniArrayQueue<DataType> &obj) {
	arr = new DataType[obj.capacity]; // Dynamically allocated memory of object capacity for array pointer

    // Copies all member functions
    capacity = obj.capacity;
	queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;

	// Copy each index of queue items in order
	for (int i = 0; i < queueSize; i++)
		arr[i] = obj.arr[i];
}
// Overloaded assignment operator
template <class DataType>
miniArrayQueue<DataType>& miniArrayQueue<DataType>::operator=(const miniArrayQueue<DataType>& obj) {
    delete [] arr; // frees the memeory of the current array
    arr = new DataType[obj.capacity]; // Dynamically allocated memory of object capacity for array pointer

    // Copies all member functions
    capacity = obj.capacity;
	queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;

	// Copy each index of queue items in order
	for (int i = 0; i < queueSize; i++)
		arr[i] = obj.arr[i];

    return *this;
}
// Function to return the size of the queue
template <class DataType>
int miniArrayQueue<DataType>::size() const {
    return queueSize;
}
// Function to return a bool denoting if the queue is empty
template <class DataType>
bool miniArrayQueue<DataType>::isEmpty() const {
    return (queueSize == 0);
}
// Function to get the front value of the queue
template <class DataType>
const DataType& miniArrayQueue<DataType>::getFront() const {
    // If queue is empty, throw exception
    if (isEmpty())
        throw QueueEmpty("Queue is Empty");

    return arr[front]; // returns value at index of front
}
// Function to add an item to the queue ... back of array
template <class DataType>
void miniArrayQueue<DataType>::enqueue(const DataType &item) {
    // If array is full, throw an exception
	if (queueSize == capacity)
        throw QueueFull("Queue is Full");
	else {
	    rear = (rear + 1) % capacity; // Increments the rear and enables a circular array with modular arithmetic 

        arr[rear] = item; // Sets array at rear index to item parameter
        queueSize++; 
    }
}
// Function to remove an item from the queue ... front of array
template <class DataType>
void miniArrayQueue<DataType>::dequeue() {
    // If array is empty, throw an exception
    if (isEmpty())
        throw QueueEmpty("Queue is Empty");
    else {
	    front = (front + 1) % capacity; // Increments the front and enables a circular array with modular arithmetic 
        queueSize--;
    }
}
// Function to display the queue from front to rear
template <class DataType>
void miniArrayQueue<DataType>::printQueue() const {
    // Loop to print out each element starting from front to rear of queu with a space between
    for (int i = front; i <= rear; i = (i + 1) % capacity)
        cout << arr[i] << " ";
    cout << endl;
}

#endif