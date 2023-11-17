/* Kyle Tranfaglia
 * COSC220 - Lab03 - Ex.1
 * 02/14/2023
 * Circle Object Implementation
*/
#include "Circle.hpp"
// Default constructor to set radius to zero
Circle::Circle() {
    radius = 0.0;
}
// Constructor that requires radius as a double and bound checks the radius before setting
Circle::Circle(double r) {
    if (r < 0) {
        cout << "Invlaid radius! (r >= 0) setting radius to 0" << endl;
        radius = 0;
    }
    else {
        radius = r;
    }
}
// Function to set the radius with parameter value
void Circle::setRadius(double r) {
    radius = r;
}
// Function to return the radius
double Circle::getRadius() {
    return radius;
}
// Function to calculate and return the diameter
double Circle::getDiameter() {
    return radius*2;
}
// Function to calculate and return the area
double Circle::getArea() {
    return PI*radius*radius;
}
// Function to calculate and return the circumference
double Circle::getCircumference() {
    return 2*PI*radius;
}