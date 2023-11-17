/* Kyle Tranfaglia
 * COSC220 - Lab04 - Ex.2
 * 02/21/2023
 * Month Object Declaration
*/
#ifndef Month_H
#define Month_H

#include <iostream>
#include <string>

using namespace std;

class Month {
private:
    string name;
    int monthNumber;
    const string ARRAY[12] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};
public:
    // Constructors
    Month(); // Default constructor
    Month(string); // Constructor
    Month(int); // Constructor

    // Assessors
    string getName();
    int getNumber();

    // Mutators
    void setName(string);
    void setNumber(int);

    // Operator Overloads
    Month operator ++(); // Prefix ++
	Month operator ++(int); // Postfix ++
    Month operator --(); // Prefix --
	Month operator --(int); // Postfix --

    // Friends
	friend ostream &operator <<(ostream &, const Month &);
	friend istream &operator >>(istream &, Month &);
};

#endif