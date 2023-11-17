/* Kyle Tranfaglia
 * COSC220 - Lab04 - Ex.2
 * 02/21/2023
 * Month Object Implementation
*/
#include "Month.h"
// Default Constructor
Month::Month() {
    monthNumber = 1;
    name = "January";
}
// Constructor that accepts name as parameter
Month::Month(string nm) {
    for (int i = 0; i < 12; i++) {
        if (ARRAY[i] == nm)
            monthNumber = i + 1;
    }
    name = nm;
}
// Constructor that accepts month number as parameter
Month::Month(int num) {
    if (num < 1 || num > 12) {
        cout << "Invalid number for month (1-12)... Setting value to 1" << endl;
        monthNumber = 1;
        name = ARRAY[num - 1];
    }
    else {
        monthNumber = num;
        name = ARRAY[num - 1];
    }
}
// Assesor function that returns the name member variable
string Month::getName() {
    return name;
}
// Assesor function that returns the month number member variable
int Month::getNumber() {
    return monthNumber;
}
// Mutator function that sets the name member variable to parameter argument
void Month::setName(string nm) {
    name = nm;
    for (int i = 0; i < 12; i++) {
        if (ARRAY[i] == nm)
            monthNumber = i + 1;
    }
}
// Mutator function that sets the month number member variable to parameter argument
void Month::setNumber(int num) {
    monthNumber = num;
    name = ARRAY[num - 1];
}
// Prefix ++ operator overload function that increments the month name and number and returns object
Month Month::operator ++() {
    if (monthNumber == 12)
        monthNumber = 1;
    else
        ++monthNumber;
    
    name = ARRAY[monthNumber - 1];

    return *this;
}
// Postfix ++ operator overload function that increments the month name and number and returns temp object
Month Month::operator ++(int) {
    Month temp(monthNumber);

    if (monthNumber == 12)
        monthNumber = 1;
    else
        monthNumber++;
    
    name = ARRAY[monthNumber - 1];

    return temp;
}
// Prefix -- operator overload function that decrements the month name and number and returns object
Month Month::operator --() {
    if (monthNumber == 1)
        monthNumber = 12;
    else
        --monthNumber;
    
    name = ARRAY[monthNumber - 1];

    return *this;
}
// Postfix -- operator overload function that decrements the month name and number and returns temp object
Month Month::operator --(int) {
    Month temp(monthNumber);

    if (monthNumber == 1)
        monthNumber = 12;
    else
        monthNumber--;
    
    name = ARRAY[monthNumber - 1];

    return temp;
}
// << Operator overload for cout that returns a ostream of month number and name output
ostream &operator <<(ostream &strm, const Month &obj) {
	strm << obj.monthNumber << "  " << obj.name;
	return strm;
}
// >> Operator overload for cin that returns a istream of month number and name output with input checker for month number
istream &operator >>(istream &strm, Month &obj) {
	// Prompt the user for the month number.
	cout << "Enter a number signifying a month (1-12): ";
	strm >> obj.monthNumber;

    // Input validation for month number
    while (obj.monthNumber < 1 || obj.monthNumber > 12) {
        cout << "Invalid input!" << endl;
        cout << "Enter a number signifying a month (1-12): ";
	    strm >> obj.monthNumber;
    }
    // Prompt the user for the month number.
	cout << "Enter the name of the month: ";
	strm >> obj.name;

	return strm;
}