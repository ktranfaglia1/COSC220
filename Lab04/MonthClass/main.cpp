/* Kyle Tranfaglia
 * COSC220 - Lab04 - Ex.2
 * 02/21/2023
 * This program showcases the fucntionality of the Month Class with initialization, manipulation, and user input
*/
#include <iostream>
#include "Month.h"

using namespace std;

int main() {
    // Variables
    Month m1, m2("August"), m3(12), m4;

    cout << "Defaulting m1, initializing m2 to August, and initializing m3 to month 12..." << endl;
    // Displays the values held by the created objects
    cout << "\nDisplaying the month information from initialization" << endl;
    cout << "m1: " << m1 << endl;
    cout << "m2: " << m2 << endl; 
    cout << "m3: " << m3 << endl;
    // Changes the values of the objects and displays to user via set and get member functions
    cout << "\nChanging m1 to June and m2 to month 3..." << endl;
    m1.setName("June");
    m2.setNumber(3);
    cout << "m1 now holds " << m1.getName() << endl;
    cout << "m2 now holds " << m2.getNumber() << endl;
    cout << "\nNew Months" << endl;
    cout << "m1: " << m1 << endl;
    cout << "m2: " << m2 << endl; 
    cout << "m3: " << m3 << endl;
    // Prompts user to create a month object and uses prefix and postfix overloads to change the obj value
    cout << "\nCreate a Month Object" << endl;
    cin >> m4;
    cout << "m4 now holds " << m4.getNumber() << " " << m4.getName() << endl;
    cout << "Applying postfix ++" << " ...Value upon postfix: " << m4++ << endl;
    cout << "m4 now contains " << m4 << endl;
    cout << "Applying prefix ++" << " ...Value upon prefix: " << ++m4 << endl;
    cout << "m4 now contains: " << m4 << endl;
    cout << "Applying postfix --" << " ...Value upon postfix: " << m4-- << endl;
    cout << "m4 now contains " << m4 << endl;
    cout << "Applying prefix --" << " ...Value upon prefix: " << --m4 << endl;
    cout << "m4 now contains " << m4 << endl;

    return 0;
}