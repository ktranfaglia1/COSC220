/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.2
 * 03/13/2023
 * Course Object Declaration
*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course {
    private:
        int code;
        string name;
        float testsScore[3];
    public:
        Course(); // Default Constructor
        Course(int c, string nm, float sc[]); // Constructor
        // Mutators
        void setCode(int c) {code = c;}
        void setName(string nm) {name = nm;}
        void setScores(float sc[]) {for (int i = 0; i < 3; i++) testsScore[i] = sc[0];}
        // Assessors
        int getCode() {return code;}
        string getName() {return name;}
        const float* getScores() {return testsScore;}
        // Friend
        friend ostream& operator << (ostream &, const Course &);
};

#endif