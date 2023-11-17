/* Kyle Tranfaglia
 * COSC220 - project2
 * 04/24/2023
 * Templated Doubly Linked List Declaration and Implementation
*/
#ifndef MINIDLIST_H
#define MINIDLIST_H

#include <iostream>  // For cout

using namespace std;

template <class DataType> 
class miniDList{
private:
    struct DNode{	// doubly linked list node
        DataType data;	//  data stored in node   
        DNode* next; //  next node in list   
        DNode* prev; //  previous node  in list
    };

    DNode* header; // list sentinels
    DNode* trailer;	
public:
    miniDList() { // constructor
    header = new DNode;
    trailer  = new DNode; // have them point to each other
    header->next = trailer;
    trailer->prev = header;
    }	
    miniDList(const miniDList<DataType> &l); // Copy constructor
    ~miniDList(); // Destructor
    const DataType& front() const; // get front element
    const DataType& back() const; // get back element
    void removeFront(); // Remove the front 
    void removeBack(); // Remove the back 
    void addFront(const DataType& e); // Add to the front 
    void addBack(const DataType& e); // Add to the back
    int size() const; // Returns the number of elements in list
    bool contains(const DataType& e); // Tests for membership
    void display() const; // Prints the elements of list
    miniDList<DataType>& operator=(const miniDList<DataType>& l); // Overloaded assignment

protected: // local utilities
    void add(DNode *v, const DataType& e); // insert new node before v
    void remove(DNode *v); // remove node v
};

// Destructor
template <class DataType> 
miniDList<DataType>::~miniDList() {
    DNode *nodeptr = header; // To traverse the list starting at header node
    DNode *nextNode = nullptr; // To point to the next node
    
    // While nodeptr is not at the end of the list...
    while (nodeptr) {
        nextNode = nodeptr->next; // Save a pointer to the next node.
		delete nodeptr; // Delete the current node.
		nodeptr = nextNode; // Position nodePtr at the next node.
    }
}
// Copy Constructor
template <class DataType> 
miniDList<DataType>::miniDList(const miniDList<DataType> &l) {
    // Constructor actions ... create header and tailer and point them at each other
    header = new DNode;
    trailer  = new DNode; 
    header->next = trailer;
    trailer->prev = header;

    DNode *nodePtr = l.header->next; // Traversing varaiable to go through the list, pointer set to list header of object
    // Loops as long as nodePtr points to something that is not the trailer of the copy object ... entire list except header and tailer
    while (nodePtr != l.trailer) {
        addBack(nodePtr->data); // Adds node to back of Doubly linked list with value from the obj doubly linked list at corresponding element
        nodePtr = nodePtr->next;  // Moves tranversing pointer to next node 
    }
}
// Overloaded assignment operator 
template <class DataType>
miniDList<DataType>& miniDList<DataType>::operator=(const miniDList<DataType>& l) {
    // Checks for self equality and returns itself to prevent a deletion and reconstruction of self
    if (this == &l) {
        return *this;
    }
    // Code from destructor is used to delete the previous linked list before copying the incoming object list with pushback
    DNode *nodePtr = header->next; // To traverse the list
	DNode *nextNode = nullptr; // To point to the next node

	// While nodePtr is not pointer to tailer ... deletes all but header and tailer
	while (nodePtr != trailer) {
		nextNode = nodePtr->next; // Save a pointer to the next node.
		delete nodePtr; // Delete the current node.
		nodePtr = nextNode; // Position nodePtr at the next node.
	}
    // Re-assign header and tailer to point to each other
    header->next = trailer;
    trailer->prev = header;

    nodePtr = l.header->next; // Traversing varaiable to go through the list, pointer set to list header of object
    // Loops as long as nodePtr points to something that is not the trailer of the copy object ... entire list except header and tailer
    while (nodePtr != l.trailer) {
        addBack(nodePtr->data); // Adds node to back of doubly linked list with value from the obj linked list at corresponding element
        nodePtr = nodePtr->next;  // Moves tranversing pointer to next node 
    }
    return *this;
}
// Function to return the value of the front element of the doubly linked list
template <class DataType> 
const DataType& miniDList<DataType>::front() const {
    // Displays list is empty if there is no front value
    if (size() == 0)
        cout << "List is empty" << endl;

    return header->next->data;
}
// Function to return the value of the back element of the doubly linked list
template <class DataType> 
const DataType& miniDList<DataType>::back() const {
    // Displays list is empty if there is no back value
    if (size() == 0)
        cout << "List is empty" << endl;
    
    return trailer->next->data;
}
// Function to remove the first node in the doubly linked list ... first after header
template <class DataType>
void miniDList<DataType>::removeFront() {
    // Checks if there is elments to remove, if not, prints list is empty, otherwise removes front node
    if (size() == 0)
        cout << "List is empty" << endl;
    else {
        // // Creates pointer and sets it to node to remove, then adjust the prev and next pointers to point to the following node or previous node as necessary, then deletes the node
        // DNode *nodeptr = header->next;
        // header->next = nodeptr->next;
        // nodeptr->next->prev = header;
        // delete nodeptr;
        remove(header->next); // Calls remove utility function sending first node
    }
}
// Function to remove the last node in the doubly linked list ... first before tailer
template <class DataType>
void miniDList<DataType>::removeBack() {
    // Checks if there is elments to remove, if not, prints list is empty, otherwise removes back node
    if (size() == 0)
        cout << "List is empty" << endl;
    else {
        // // Creates pointer and sets it to node to remove, then adjust the prev and next pointers to point to the following node or previous node as necessary, then deletes the node
        // DNode *nodeptr = trailer->prev;
        // trailer->prev = nodeptr->prev;
        // nodeptr->prev->next = trailer;
        // delete nodeptr;
        remove(trailer->prev); // Calls remove utility function sending last node
    }
}
// Function to add a node of incoming value to the front of the doubly linked list 
template <class DataType>
void miniDList<DataType>::addFront(const DataType &e) {
    // // Creates new node with value from paramter
    // DNode *newNode = new DNode;
    // newNode->data = e;

    // // Adjusts the connection pointers with repect to header and the new node
    // newNode->prev = header;
    // newNode->next = header->next;
    // header->next->prev = newNode;
    // header->next = newNode;
    add(header->next, e); // Calls add utility function sending first node and a value for the new node to hold
}
// Function to add a node of incoming value to the back of the doubly linked list 
template <class DataType>
void miniDList<DataType>::addBack(const DataType &e) {
    // // Creates new node with value from paramter
    // DNode *newNode = new DNode;
    // newNode->data = e;

    // // Adjusts the connection pointers with repect to tailer and the new node
    // newNode->prev = trailer->prev;
    // newNode->next = trailer;
    // trailer->prev->next = newNode;
    // trailer->prev = newNode;
    add(trailer, e); // Calls add utility function sending the trailer node and a value for the new node to hold
}
// Function to count and return the number of nodes in the doubly linked list
template <class DataType>
int miniDList<DataType>::size() const {
    int count = 0;
    DNode *nodePtr = header->next; // Traversing varaiable to go through the list, pointer set to list header of object
    // Loops as long as nodePtr points to something that is not the trailer of the copy object ... entire list except header and tailer
    while (nodePtr != trailer) {
        count++; // Increments element count for each iteration
        nodePtr = nodePtr->next;  // Moves tranversing pointer to next node 
    }
    return count;
}
// Function to return if the incoming value is contained by a node in the doubly linked list
template <class DataType>
bool miniDList<DataType>::contains(const DataType &e) {
    bool status = false; // Defaults bool return to false
    DNode *nodeptr = header->next; // creates traversing pointer

    // Loops as long as nodePtr points to something that is not the trailer of the copy object ... entire list except header and tailer
    while (nodeptr != trailer) {
        // Checks if node value and parameter value are equal, if so, return status set to true
        if (nodeptr->data == e)
            status = true;
        nodeptr = nodeptr->next; // Moves pointer to next node
    }
    return status;
}
// Function to display the doubly linked list chronologically from header to tailer
template <class DataType>
void miniDList<DataType>::display() const {
    DNode *nodePtr = header->next; // Traversing varaiable to go through the list, pointer set to list header of object
    // Loops as long as nodePtr points to something that is not the trailer of the copy object ... entire list except header and tailer
    while (nodePtr != trailer) {
        cout << nodePtr->data << " "; // Prints value of node with a space at end
        nodePtr = nodePtr->next;  // Moves tranversing pointer to next node 
    }
    cout << endl;
}
template <class DataType>
void miniDList<DataType>::add(DNode *v, const DataType& e) {
    // Creates new node with value from paramter
    DNode *newNode = new DNode;
    newNode->data = e;

    // Re-arranges pointers to adjust to the new pointer being added such that the nodes before and after newNode point to newNode and newNode points to them
    newNode->next = v;
    newNode->prev = v->prev;
    v->prev->next = newNode;
    v->prev = newNode;

}
template <class DataType>
void miniDList<DataType>::remove(DNode *v) {
    // Adjusts pointers before and after node to be deleted to point to each other rather than the node to be deleted, then deletes the selected node
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

#endif