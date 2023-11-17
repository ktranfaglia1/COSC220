/* Kyle Tranfaglia
 * COSC220 - Lab03 - OYO - Ex.2
 * 02/20/2023
 * This Program tests the fucntionality of the NumArray class by using its member functions
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "NumArray.hpp"

using namespace std;

int main() {
    srand(time(0)); // Sets seed generator - time to zero to allow random number generation
    // Variables 
    const int SIZE = 10;
    float ranFloat = 0;
    NumArray list(SIZE);

    cout << "\nElements stored using class Variable" << endl;
    cout << fixed << setprecision(6);
    // Loop to fill the class array with 10 random floating points between 1 and 10
    for (int i = 0; i < SIZE; i++) {
        ranFloat = rand () * (static_cast<float>(10 - 1) / RAND_MAX) + 1;
        list.storeElement(ranFloat, i);
        cout << "Element " << i + 1 << " Stored: " << ranFloat << endl;
    }
    cout << endl << "Elements retrieved from class" << endl;
    // Loop to display each element of class array to ensure it was stored and could be retreived
    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << i + 1 << ": " << list.getElement(i) << endl;
    }
    // Calls member functions of class to do some data calculations
    cout << "\nData Calculations" << endl;
    cout << "Highest value in list: " << list.getHighest() << endl;
    cout << "Lowest value in list: " << list.getLowest() << endl;
    cout << "Average value in list: " << list.getAverage() << endl;

    cout << "\nUser inputs Inplemented in Class" << endl; // Begin user input section
    int sz = 0;
    float element = 0;
    // Gets class array size from user
    cout << "Input a size for the array of floats: ";
    cin >> sz;
    NumArray user(sz);

    cout << "\nStore elements in the class array" << endl;
    // Loop to fill the class array with floating point values given by the user
    for (int i = 0; i < sz; i++) {
        cout << "enter a value for element " << i + 1 << ": ";
        cin >> element;
        user.storeElement(element, i);
    }
    cout << endl << "Elements retrieved from class" << endl;
    // Loop to display each element of class array to ensure it was stored and could be retreived
    for (int i = 0; i < sz; i++) {
        cout << "Element " << i + 1 << ": " << user.getElement(i) << endl;
    }
    // Calls member functions of class to do some data calculations
    cout << "\nData Calculations" << endl;
    cout << "Highest value in list: " << user.getHighest() << endl;
    cout << "Lowest value in list: " << user.getLowest() << endl;
    cout << "Average value in list: " << user.getAverage() << endl;

    return 0;
}