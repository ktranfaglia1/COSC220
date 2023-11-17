/* Kyle Tranfaglia
 * COSC220 - Lab03 - OYO - Ex.2
 * 02/20/2023
 * NumArray Object Implementation
*/
#include "NumArray.hpp"
// Constructor 
NumArray::NumArray(int s) {
    size = s;
    list = new float[size];
}
// Destructor
NumArray::~NumArray() {
    delete[] list;
}
// Function to set the incoming paramter element to value at array memory location of position
void NumArray::storeElement(float element, int position) {
    // Bound Checker. If position is out of possible range 0 to size, the user is informed this is a bound error
	if (position < 0 || position >= size) {
		cout << "List bounds error, nothing was stored" << endl;
	}
	else {
		*(list + position) = element;
	}
}
float NumArray::getElement(int position) {
    // Bound Checker. If position is not in range 0 to size, the user is informed this is a bound error and returns -1
	if (position < 0 || position >= size) {
		cout << "List bounds error, returning -1" << endl;
		return -1;
	}
	return *(list + position);
}
// Function to get the float value of the highest element in the array
float NumArray::getHighest() {
    float highest = *list; // Defaults highest value to first array index
    // Loop to go through each index of array and compare to highest value, if higher, it replaces it
    for (int i = 0; i < size; i++) {
        if (*(list + i) > highest) {
            highest = *(list + i);
        }
    }
    return highest;
}
// Function to get the float value of the lowest element in the array
float NumArray::getLowest() {
    float lowest = *list; // Defaults highest value to first array index
    // Loop to go through each index of array and compare to lowest value, if lower, it replaces it
    for (int i = 0; i < size; i++) {
        if (*(list + i) < lowest) {
            lowest = *(list + i);
        }
    }
    return lowest;
}
// Function to get the average value of all the elements in the array 
float NumArray::getAverage() {
    double sum = 0;
    // Loop to keep a running total of all the array elements
    for (int i = 0; i < size; i++) {
        sum += *(list + i);
    }
    return sum/size;
}