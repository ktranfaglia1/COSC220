/* Kyle Tranfaglia
 * COSC220 - Lab06 - OYO - Ex.1
 * 03/27/2023
 * ListCollection Object and template Declaration and Implementation
*/
#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

template<typename T>
class ListCollection {
    private:
        T *list; // Pointer to the array.
        int numElements; // Number of elements.
        int numCapacity; // Maximum number of elements.
        bool isValid(int) const; // Validates subscripts.
        void resize(int); // Resizes list, moved to private.
    public:
        ListCollection(int sz = 10); // Constructor
        ~ListCollection(); // Destructor
        void setElement(int, T); // Sets an element to a value
        T getElement(int) const; // Returns an element
        void displayList(bool nl = false) const; // Display list

        ListCollection(const ListCollection &obj); // Copy Constructor
        const ListCollection operator=(const ListCollection &right); // Copy Assignment

        // Updated functions
        const ListCollection operator+(const ListCollection &right); // Concatenation

        // New functions
        int size();
        int capacity();
        void pushBack(T);
        T popBack();
        void pushFront(T);
        T popFront();
};

//**************************************************
// Templated ListCollection Object implementation  *
//**************************************************

// Constructor taking in size with default as 10
template<typename T>
ListCollection<T>::ListCollection(int sz) {
    list = new T[sz];
    numCapacity = sz;
    numElements = 0;
    // Sets each element to 0
    for (int ndx = 0; ndx < sz; ndx++)
        list[ndx] = 0;
}
// Destructor
template<typename T>
ListCollection<T>::~ListCollection() {
    delete [] list;
}
// Copy constructor
template<typename T>
ListCollection<T>::ListCollection(const ListCollection &obj) {
    numCapacity = obj.numCapacity;
    numElements = obj.numElements;
    list = new int[numCapacity];
    // Copy all left obj elements to right obj
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}
// Operator overload = to set left obj equal to right obj
template<typename T>
const ListCollection<T> ListCollection<T>::operator=(const ListCollection &right) {
    delete [] list;
    numCapacity = right.numCapacity;
    numElements = right.numElements;
    list = new int[numCapacity];
    // Copy all left obj elements to right obj
    for (int i = 0; i < numElements; i++)
        list[i] = right.list[i];

    return *this;
}
// Function for input validation that returns true if valid
template<typename T>
bool ListCollection<T>::isValid(int element) const {
    bool status;
    // Input validation to test validity based on bounds of array
    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;

    return status;
}
// Function to set the an element of the array given element and value
template<typename T>
void ListCollection<T>::setElement(int element, T value) {   
    // Sets element to given value if element is valid
    if (isValid(element))
        list[element] = value;
}
// Function to get the value of an element from the array
template<typename T>
T ListCollection<T>::getElement(int position) const {
    // Gets element but if bound too low or high, it returns the closest valid element
    if (position < 0) {
        return list[0];
    }
    else if (position >= numElements) {
        return list[numElements - 1];
    }
    else
        return list[position];
}
// Function to display the array
template<typename T>
void ListCollection<T>::displayList(bool nl) const {
    // Displays each element in order with a space or newline depedending on boolean
    if (nl) {
        for (int i = 0; i < numElements; i++)
            std::cout << list[i] << std::endl;
        std::cout << std::endl;
    }
    else {
        for (int i = 0; i < numElements; i++)
            std::cout << list[i] << " ";
    }
}
// Function to concatentate left and right obj list and return that list
template<typename T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection &right) {

    ListCollection concatList(numElements + right.numElements); // Creates obj with size of sum of left and right obj
    concatList.numElements = concatList.numCapacity;
    // Concatenates arrays using two loops, one to copy left obj elements and the other for the right
    for (int i = 0; i < numElements; i++)
        *(concatList.list + i) = *(list + i);

    for (int i = 0; i < right.numElements; i++)
        *(concatList.list + numElements + i) = *(right.list + i);

    return concatList;
}
// Function to resize the dynamically created array by creating a new array, transfering elements, and changing pointer
template<typename T>
void ListCollection<T>::resize(int size) {

    T *newArray = new T[size]; // Dynamically creates new array
    // Transfers old array data to new array and if shorter, the remaining elements of old array are lost, and if larger, the unfilled elements get defaulted to 0
    for (int i = 0; i < size; i++) {
        if (i < numElements)
            newArray[i] = list[i];
        else 
            newArray[i] = 0;
    }
    numCapacity = size; // Sets new size to obj member variable
    delete [] list; // Deletes the old list pointer
    list = newArray; // Places pointer at memory location of first element of the new dynamic array
}
// Function to return number of elements in object list
template<typename T>
int ListCollection<T>::size() {
    return numElements;
}
// Function to return capacity of object list
template<typename T>
int ListCollection<T>::capacity() {
    return numCapacity;
}
// Function to add the incoming parameter value to the last index of the array
template<typename T>
void ListCollection<T>::pushBack(T element) {
    // Statement to call the resize function if there is no capacity to store another element
	if (numCapacity == numElements) {
		resize(numCapacity*2);
	}
	*(list + numElements++) = element;
}
// Function to remove an index from the back of an array and return the value removed
template<typename T>
T ListCollection<T>::popBack() {
	return *(list + numElements--);
}
// Function to add the incoming parameter value to the first index of the array
template<typename T>
void ListCollection<T>::pushFront(T element) {
    // Statement to call the resize function if there is no capacity to store another element
	if (numCapacity == numElements) {
		resize(numCapacity*2);
	}
	// Loop to move all of the indexes of the array to the incremented element, meaning index 0 of the array is replaced by index 1...
	for (int i = numElements; i > 0; i--) {
		*(list + i) = *(list + i - 1);
	}
    numElements++;
	*list = element; // Sets first index as paramter value
}
// Function to remove an index from the front of an array and return the value removed
template<typename T>
T ListCollection<T>::popFront() {
    int removed = *(list);
    numElements--;
	// Loop that sets the index as the following index, meaning index at 0 is replaced by index at 1...
	for (int i = 0; i < numElements; i++) {
		*(list + i) = *(list + i + 1);
	}
	return removed;
}

#endif