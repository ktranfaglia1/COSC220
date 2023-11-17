/* Kyle Tranfaglia
 * COSC220 - Lab06 - InLab - Ex.1
 * 03/14/2023
 * ListCollection Object Declaration
*/
#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

class ListCollection {
    private:
        int *list; // Pointer to the array.
        int numElements; // Number of elements.
        int numCapacity; // Maximum number of elements.
        bool isValid(int) const; // Validates subscripts.
        void resize(int); // Resizes list, moved to private.
    public:
        ListCollection(int sz = 10); // Constructor
        ~ListCollection(); // Destructor
        void setElement(int, int); // Sets an element to a value
        int getElement(int) const; // Returns an element
        void displayList(bool nl = false) const; // Display list

        ListCollection(const ListCollection &obj); // Copy Constructor
        const ListCollection operator=(const ListCollection &right); // Copy Assignment

        // Updated functions
        const ListCollection operator+(const ListCollection &right); // Concatenation

        // New functions
        int size();
        int capacity();
        void pushBack(int);
        int popBack();
        void pushFront(int);
        int popFront();
};

#endif