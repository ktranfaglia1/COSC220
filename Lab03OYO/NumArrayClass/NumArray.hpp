/* Kyle Tranfaglia
 * COSC220 - Lab03 - OYO - Ex.2
 * 02/20/2023
 * NumArray Object Declaration
*/
#ifndef NUMARRAY_HPP
#define NUMARRAY_HPP

#include <iostream>

using namespace std;

class NumArray{
private: 
    // Defaulted member variables
    float *list = nullptr;
    int size = 0;
public: 
    NumArray(int); // Constructor
    ~NumArray(); // Destructor
    // Mutator
    void storeElement(float, int);
    // Accessor and functions
    float getElement(int);
    float getHighest();
    float getLowest();
    float getAverage();
};

#endif