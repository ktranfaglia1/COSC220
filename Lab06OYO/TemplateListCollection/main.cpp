/* Kyle Tranfaglia
 * COSC220 - Lab06 - OYO - Ex.1
 * 03/27/2023
 * This program is an altered test file provided by Dr. Tu to test the
 * functionality of the ListCollection template class
*/
#include <iostream>
#include "ListCollection.h"

using namespace std;

int main() {
    ListCollection<int> l1;

    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.pushFront(25);
    l1.pushFront(56);
    l1.pushFront(-7);
    l1.pushFront(10);
    l1.pushFront(33);

    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    cout << endl;

    l1.pushBack(55);
    l1.pushBack(-4);
    l1.pushBack(22);
    l1.pushBack(123);
    l1.pushBack(-47);
    l1.pushBack(12);

    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.pushBack(1234);
    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    cout << endl;

    cout << l1.popFront() << endl;
    cout << l1.popFront() << endl;
    cout << l1.popBack() << endl;
    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    cout << endl;


    cout << l1.getElement(2) << endl;
    l1.displayList();
    cout << l1.size() << "  " << l1.capacity() << endl;

    l1.setElement(2, 40);
    l1.displayList();

    return 0;
}