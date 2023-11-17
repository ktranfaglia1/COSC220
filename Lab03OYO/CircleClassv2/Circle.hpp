/* Kyle Tranfaglia
 * COSC220 - Lab03 - OYO - Ex.1
 * 02/20/2023
 * Circle Object Declaration
*/
#ifndef Circle_HPP
#define Circle_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Circle{
private: 
    // Member variables
    double x;
    double y;
    double radius;
    const double PI = 3.141592653589793;
public: 
    Circle(); // Default Constructor
    Circle(double, double, double); // Constructor
    // Mutator
    void setRadius(double);
    void setCenter(double, double);
    // Accessor and functions
    double getRadius();
    double getDiameter();
    double getArea();
    double getCircumference();
    double getCenterX();
    double getCenterY();
    bool collide(Circle);
};

#endif