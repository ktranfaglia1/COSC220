/* Kyle Tranfaglia
 * COSC220 - Lab04 - OYO - Ex.2
 * 02/27/2023
 * IntegerList Object Declaration - Derived from class source code and updated
*/
#ifndef INTEGERLIST_H
#define INTEGERLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

class IntegerList {
  private:
    int *list;                 // Pointer to the array.
    int numElements;           // Number of elements.
    bool isValid(int) const;   // Validates subscripts.

  public:
    IntegerList();             // Default Constructor
    IntegerList(int);          // Constructor
    ~IntegerList();            // Destructor
    void setElement(int, int); // Sets an element to a value
    int getElement(int) const; // Returns an element
    void displayList() const;  // Display list

    IntegerList(const IntegerList &obj); // Copy Constructor
	  const IntegerList operator=(const IntegerList &right); // Operator Overload =

    // Added Functions for Safe Array
    const IntegerList operator+(const IntegerList &right); // Operator overload +
    int &operator[](const int &); // Safe Array accessor operator overload []
    void resize(int); // resizes dynamic array

};

#endif
