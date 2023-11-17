/* Kyle Tranfaglia
 * COSC220 - Lab06 - OYO - Ex.2
 * 03/27/2023
 * This program is provided by Dr. Tu to create an ListCollecton Object of FeetInches and tests the functionality of the templated class
*/
#include <iostream>
#include "ListCollection.h"
#include "FeetInches.h"

using namespace std;

void setFeetInches(FeetInches &f, int feet, int inches)
{
    f.setFeet(feet);
    f.setInches(inches);
}

int main()
{
    ListCollection<FeetInches> l1;
    FeetInches f(5, 2);

    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.pushFront(f);
    setFeetInches(f, 3, 3);
    l1.pushFront(f);
    setFeetInches(f, 7, 9);
    l1.pushFront(f);
    setFeetInches(f, 2, 17);
    l1.pushFront(f);
    setFeetInches(f, 1, 4);
    l1.pushFront(f);

    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    cout << endl;

    setFeetInches(f, 55, 2);
    l1.pushBack(f);
    setFeetInches(f, 123, 7);
    l1.pushBack(f);
    setFeetInches(f, 90, 9);
    l1.pushBack(f);
    setFeetInches(f, 5, 1);
    l1.pushBack(f);
    setFeetInches(f, 7, 7);
    l1.pushBack(f);
    setFeetInches(f, 4, 2);
    l1.pushBack(f);
    
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    
    setFeetInches(f, 1234, 10);
    l1.pushBack(1234);
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    cout << endl;
    
    cout << l1.popFront() << endl;
    cout << l1.popFront() << endl;
    cout << l1.popBack() << endl;
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
   
    
    cout << l1.getElement(2) << endl;
    l1.displayList(true);
    cout << l1.size() << "  " << l1.capacity() << endl;
    
    setFeetInches(f, 17, 2);
    l1.setElement(2, f);
    l1.displayList(true);
    
    
    return 0;
}
