/* Kyle Tranfaglia
 * COSC220 - Lab10 - OYO - Ex.2
 * 05/01/2023
 * A program to test an iterative and recursive binary search using an array of 10000 elements
*/
#include <iostream>

using namespace std;

// Prototypes for binary search functions
int BinarySearch(const int A[], int size, int value);
int RecrusiveBinarySearch(const int A[], int first, int last, int value);

int main() {
    // Variales
    const int SIZE = 10000; 
    int array[SIZE];

    // Loop to fill array with value i in the ith index
    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }
    // Binary Search calls 
    cout << BinarySearch(array, SIZE, 9999) << endl;
    cout << RecrusiveBinarySearch(array, 0, SIZE - 1, 9999) << endl;

    cout << BinarySearch(array, SIZE, 5000) << endl;
    cout << RecrusiveBinarySearch(array, 0, SIZE - 1, 5000) << endl;

    // Loop to fill array with value i times 5 in the ith index
    for (int i = 0; i < SIZE; i++) {
        array[i] = i*5;
    }
    // Binary Search calls
    cout << BinarySearch(array, SIZE, 0) << endl;
    cout << RecrusiveBinarySearch(array, 0, SIZE - 1, 0) << endl;

    cout << BinarySearch(array, SIZE, 5000) << endl;
    cout << RecrusiveBinarySearch(array, 0, SIZE - 1, 5000) << endl;

    cout << BinarySearch(array, SIZE, 232) << endl;
    cout << RecrusiveBinarySearch(array, 0, SIZE - 1, 232) << endl;

    return 0;
}
// Iterative binary search to return integer element that contains the value or -1 if not found
int BinarySearch(const int A[], int size, int value) {
    // Initialized index position variables
    int first = 0;
    int last = size - 1;
    int middle = 0;

    // Searches while first index is not greater than last
    while (first <= last) {
        middle = (first + last)/2; // Sets middle index
        if (value == A[middle]) // If search value is found return index
            return middle;
        else if (A[middle] > value) // If search value is less than value at middle index set last to before middle
            last = middle - 1;
        else
            first = middle + 1; // If search value is more than value at middle index set first to after middle
    }
    return -1; // Default return if search does not find a match
}
// Recursive binary search to return integer element that contains the value or -1 if not found
int RecrusiveBinarySearch(const int A[], int first, int last, int value) {
    int middle; // Vraiable for middle index

    // Base case to return -1 if search does not find a match, as in, first is greater than last index
    if (first > last)
        return -1;
    middle = (first + last)/2; // Sets middle index
    if (value == A[middle])  // If search value is found return index
        return middle;
    else if (A[middle] > value) // If search value is less than value at middle index, recursivley call function with last index as the first before the middle index as rest of array valus are too large
        return RecrusiveBinarySearch(A, first, middle -1, value);
    else  // If search value is more than value at middle index, recursivley call function with first index as the first after the middle index as rest of array values are too small
        return RecrusiveBinarySearch(A, middle + 1, last, value);
}