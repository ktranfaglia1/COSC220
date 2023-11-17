/* Kyle Tranfaglia
 * COSC220 - Lab04 - OYO - Ex.1
 * 02/27/2023
 * This program is a test file provided by Dr. Tu to test the functionality of the updated IntergerList class
*/
#include <iostream>
#include "IntegerList.h"

using namespace std;
// Function to populate obect list with reference
void PopulateList(IntegerList &L, int size) {
    for (int i = 0; i < size; i++)
        L[i] = i;
}
// Function to populate obect list without reference
void PopulateList2(IntegerList L, int size) {
    for (int i = 0; i < size; i++)
        L[i] = i;
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
    IntegerList l4= l3;
    l4.displayList();

    l4.resize(5);
    l4.displayList();

    return 0;
}