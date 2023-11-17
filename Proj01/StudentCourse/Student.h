/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.2
 * 03/13/2023
 * Student Object Declaration
*/
#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

class Student {
    private:
        int id;
        string name;
        Course *array;
        int courseAmount;
        int courseCapacity;
    public:
        Student(); // Default Constructor
        ~Student(); // Default Destructor
        Student(int, string); // Constructor
        Student(const Student&); // Copy Constructor
        // Mutators
        void setID(int num) {id = num;}
        void setName(string nm) {name = nm;}
        // Assessors
        int getID() {return id;}
        string getName() {return name;}
        // Course Functions 
        void addCourse(Course);
        void deleteCourse(Course);
        // Overloads
        const Student operator = (const Student &);
        // Friend
        friend ostream& operator << (ostream &, const Student &);
};

#endif