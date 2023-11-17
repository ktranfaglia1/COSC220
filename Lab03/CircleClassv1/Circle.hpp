/* Kyle Tranfaglia
 * COSC220 - Lab03 - Ex.1
 * 02/14/2023
 * Circle Object Declaration
*/
#ifndef Circle_HPP
#define Circle_HPP

#include <iostream>

using namespace std;

class Circle{
private: 
    // Member variables
    double radius;
    const double PI = 3.141592653589793;
public: 
    Circle(); // Default Constructor
    Circle(double); // Constructor
    // Mutator
    void setRadius(double);
    // Accessor and functions
    double getRadius();
    double getDiameter();
    double getArea();
    double getCircumference();
};

#endif