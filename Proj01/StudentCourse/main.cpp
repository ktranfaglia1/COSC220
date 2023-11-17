/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.2
 * 03/13/2023
 * Program to illustrates the functionality of the student class which uses implementation of the course class
*/
#include "Student.h"

int main() {
    // Dummy Variables to store user input
    string sName = "";
    int sID = 0;
    // Creates object
    Student s1;
    
    // Gets user input for student class
    cout << "Enter the Student name: " << endl;
    getline(cin, sName);

    cout << "Enter the seven digit Student ID: " << endl;
    cin >> sID;
    
    // Sets name and id using user input and prints what was entered using call to class get functions
    s1.setName(sName);
    s1.setID(sID);
    cout << endl << s1.getName() << "  " << s1.getID() << endl << endl;

    // Creates arrays of floats to represent grades for student courses
    float grade1[3] = {90, 100, 88};
    float grade2[3] = {92, 99, 98};
    float grade3[3] = {95, 78, 82};
    float grade4[3] = {54, 65, 70};

    // Creates Course objects to be added to student objects and uses user input to set the lunch object
    Course math(123, "Math", grade1);
    Course history(321, "History", grade2);
    Course english(444, "English", grade3);
    Course science(555, "Science", grade4);
    Course lunch; 

    cout << "Enter the Course name: " << endl;
    cin.ignore();
    getline(cin, sName);

    cout << "Enter the Course code: " << endl;
    cin >> sID;
    cout << endl;

    lunch.setCode(sID);
    lunch.setName(sName);
    lunch.setScores(grade2);

    // Testing of add course, delete course, and assignment (copy constructor and overload) and prints the results using << overload
    s1.addCourse(math);
    s1.addCourse(history);

    Student s2 = s1;
    Student s3;

    s3 = s2;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    s2.addCourse(english);

    cout << s2 << endl;

    s3.addCourse(science);
    s3.addCourse(lunch);

    cout << s3 << endl;

    s1.addCourse(english);
    s1.addCourse(science);

    cout << s1 << endl;

    s1.deleteCourse(math);
    s1.deleteCourse(english);

    cout << s1 << endl;

    s2.deleteCourse(english);
    s2.deleteCourse(math);

    cout << s2 << endl;

    s3 = s1;

    cout << s3 << endl;

    return 0;
}