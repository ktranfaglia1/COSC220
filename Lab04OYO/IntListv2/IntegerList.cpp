/* Kyle Tranfaglia
 * COSC220 - Lab04 - OYO - Ex.2
 * 02/27/2023
 * IntegerList Object Implementation - Derived from class source code and updated
*/
#include "IntegerList.h"
// Default constructor
IntegerList::IntegerList() {
    cout << "In the default constructor" << endl;
    list = nullptr;
    numElements = 0;
    cout << "Leaving the default constructor" << endl;
}
// Constructor taking in size
IntegerList::IntegerList(int size) {
    cout << "In the constructor" << endl;
    list = new int[size];
    numElements = size;
    // Sets each element to 0
    for (int ndx = 0; ndx < size; ndx++)
        list[ndx] = 0;

    cout << "Leaving the constructor" << endl;
}
// Destructor
IntegerList::~IntegerList() {
    cout << "In the destructor" << endl;
    delete [] list;
    cout << "Leaving the destructor" << endl;
}
// Copy constructor
IntegerList::IntegerList(const IntegerList &obj) {
    cout << "In the copy constructor" << endl;
    numElements = obj.numElements;
    list = new int[numElements];
    // Copy all left obj elements to right obj
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
    cout << "Leaving the copy constructor" << endl;
}
// Operator overload = to set left obj equal to right obj
const IntegerList IntegerList::operator=(const IntegerList &right) {
    delete [] list;
    numElements = right.numElements;
    list = new int[numElements];
    // Copy all left obj elements to right obj
    for (int i = 0; i < numElements; i++)
        list[i] = right.list[i];

    return *this;
}
// Function for input validation that returns true if valid
bool IntegerList::isValid(int element) const {
    bool status;
    // Input validation to test validity based on bounds of array
    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;

    return status;
}
// Function to set the an element of the array given element and value
void IntegerList::setElement(int element, int value) {   
    // Sets element to given value if element is valid
    if (isValid(element))
        list[element] = value;
}
// Function to get the value of an element from the array
int IntegerList::getElement(int position) const {
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
void IntegerList::displayList() const {
    // Displays each element in order with a space
    for (int i = 0; i < numElements; i++)
        cout << list[i] << " ";

    cout << endl;
}
// Function to concatentate left and right obj list and return that list
const IntegerList IntegerList::operator+(const IntegerList &right) {
    cout << "In the + operator overload function" << endl;

    IntegerList concatList(numElements + right.numElements); // Creates obj with size of sum of left and right obj
    // Concatenates arrays using two loops, one to copy left obj elements and the other for the right
    for (int i = 0; i < numElements; i++)
        concatList[i] = list[i];

    for (int i = 0; i < right.numElements; i++)
        concatList[numElements + i] = right.list[i];

    cout << "Leaving the + operator overload function" << endl;
    return concatList;
}
// Operator Overload [] with int refernece return to allow accessment of array element and assignment
int & IntegerList::operator[] (const int &position) {
    cout << "In the [] operator overload function with an incoming index of " << position << endl;
    // Bound checks position and if out of bounds it retunrs the closest valid bound, otherwise it returns the value of element as refernece
    if (position < 0) {
        return list[0];
    }
    else if (position >= numElements) {
        return list[numElements - 1];
    }
    else
        return list[position];
}
// Function to resize the dynamically created array by creating a new array, transfering elements, and changing pointer
void IntegerList::resize(int size) {

    int *newArray = new int[size]; // Dynamically craetes new array
    // Transfers old array data to new array and if shorter, the remaining elements of old array are lost, and if larger, the unfilled elements get defaulted to 0
    for (int i = 0; i < size; i++) {
        if (i < numElements)
            newArray[i] = list[i];
        else 
            newArray[i] = 0;
    }
    numElements = size; // Sets new size to obj member variable
    delete [] list; // Deletes the old list pointer
    list = newArray; // Places pointer at memory location of first element of the new dynamic array
}