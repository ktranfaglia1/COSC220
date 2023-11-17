/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.2
 * 03/13/2023
 * Course Object Implementtation
*/
#include "Course.h"

// Default Constructor
Course::Course() {
    code = 120; 
    name = "CS1";
    // Sets all score indexes to 0
    for (int i = 0; i < 3; i++) 
        testsScore[i] = 0.0;
}
// Constructor
Course::Course(int c, string nm, float sc[]) {
    code = c; 
    name = nm;
    // Sets each score index using argument
    for (int i = 0; i < 3; i++) 
        testsScore[i] = sc[0];
}
// Operator overload friend fucntion for << that provides a nice printed list of the student object while utilizing the << overload from the course class
ostream& operator << (ostream &strm, const Course &obj) {
    strm << endl << "code: " << obj.code << endl;
    strm << "Name: " << obj.name << endl;
    strm << "Grades : ";
    // Captures an output of each testscore in ostream variable 
    for (int i = 0; i < 3; i++) 
        strm << obj.testsScore[i] << "  ";
    strm << endl << endl;
    return strm;
}


