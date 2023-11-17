/* Kyle Tranfaglia
 * COSC220 - Lab04 - OYO - Ex.2
 * 02/27/2023
 * This program is a test file provided by Dr. Tu to test the functionality of the updated IntergerList class with the addition of couts to track function calling
*/
#include <iostream>
#include "IntegerList.h"

using namespace std;
// Function to populate object list with reference
void PopulateList(IntegerList &L, int size) {
    cout << "In PopulateList" << endl;

    for (int i = 0; i < size; i++)
        L[i] = i;

    cout << "Out PopulateList" << endl;
}
// Function to populate object list without reference
void PopulateList2(IntegerList L, int size) {
    cout << "In PopulateList2" << endl;

    for (int i = 0; i < size; i++)
        L[i] = i;

    cout << "Out PopulateList2" << endl;
}
int main() {
    // Creates Objects with a size
    IntegerList l1(7);
    IntegerList l2(17);
    // Loop to populate list
    for (int i = 0; i < 7; i++)
        l1[i] = i * i;

    PopulateList2(l1, 7);
    PopulateList(l2, 17);

    l1.displayList();
    l2.displayList();
    // Creates object with default constructor
    IntegerList l3;
    l3 = l1 + l2;
    l3.displayList();

    l3[4] = 100;
    // Bound errors
    l3[400] = 100;
    l3[-4] = 100;

    l3.displayList();

    l3.resize(30);
    l3.displayList();   
    // Creates another object and assigns it to the previously created object
    IntegerList l4 = l3;
    l4.displayList();

    l4.resize(5);
    l4.displayList();

    return 0;
}
/* 
    (a) What is the big difference between the calls to PopulateList and PopulateList2?
    Why are these calls different, what is causing it and what is the difference in the
    results?

        The big differnece between calls to PopulateList and PopulateList2 is that PopulateList 
        is a pass by reference while PopulateList2 is a pass by value for the integerList object.
        This means that each time the PopulateList2 function is called, the copy constructor must first
        be called to create a copy of the object as a pass by value requires a copy of the argument to be
        made. The copy constructor is called instead of other constructors as the object already exists and
        a copy of it is needed using the another existing object. Additionally, PopulateList2 then requires the deconstructor
        to be called once the function is exited, as the function cannot clear the memory used by the dynamically created
        array that was constructed by the copy constructor. The deconstructor then deletes/releases the alloted memory for
        that copy of an object and prevents a memory leak. The PopulateList function does not require the copy constructor
        nor the deconstructor as it is a pass by reference, meaning that same object is referenced by passing its memeory location, 
        allowing the function to access and mutate the memory at that location, so another object does not need created/destroyed.

    (b) List all of the output that is created from the two lines.
    IntegerList l3;
    l3 = l1 + l2;
    You may ignore all the calls to the [] operator. For all the other lines of output, state where they come from and why.

    Ordered List of outputs
    1) default constructor
    2) + operator overload function enter
    3) constructor
    4 + operator overload function exit
    4) 24 calls to the [] operator overload function
    5) Copy constructor
    6) destructor
    7) destructor again

    Explanation of Outputs

    First, the defualt constructor was called as the line IntegerList l3; provides a declaration for an object without any parameter arguments, so
    the default constructor must be called to create the object and assign the default values to the memeber variables of this object. Next, the 
    + operator overload function is called as the l3 = assingment involves an addition of objects l1 + l2, which calls the operator overload
    function to perform the operation, as this is not defined otherwise. The constructior is then called as a new object is created in the 
    + operator overload function with the size (sum of left and right object sizes) as an argument. This new object is the concatList obj
    which is used to hold the concatentation of the added objects. The 24 [] operator overload function calls are a result of the data from 
    the right and left objects being added requiring the i element of the ConcatList to the left or right list. The + operator overload function is then exited.
    The copy constructor is called  as the return of the + operator overload function call was an IntegerList object, so now the assignment l3 = l1 + l2 is
    really l3 = concatList as that is what was returned by the fucntion call. Since an object is now being assigned to another object, the copy constructor is called
    as this constructor is responcible for using existing objects to fill other objects, meaning the object is copied during the assignment and stored in the left
    side object with new allocated memory. A deconstructor is called as the copy constructor creates another instance of the l3 object although it was already created.
    This is because the object had to be resized in order for the copy to work which required new memory to be dynamically allocated, therefore the previous memory
    allocated to l3 was released by the destructor. Finally, another destructor is called as the object ConcatList created in the implementation of the + operator
    overload function was only created to be a temporary object and served its purpose to be returned and copied, and so the memory allocated was freed. 

    (c) Which constructor is called on the line, IntegerList l4 = l3;

        On the line IntegerList l4 = l3;, the copy constructor is called. It is called as the assignment operator with two objects 
        signifies that a copying of objects is neccessary. Only the copy constructor is called on this line. A cosntructor is not first called
        as a copy cosntructor is capable of creating an object that was not already an existing object. In fact, since this is the first time
        that the l4 object is being created and assigned value, a destructor is not needed like the copy constructor sometimes requires. This is because
        the l4 object was never previously allotted memory so it does not need released. 
*/