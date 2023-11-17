/* Kyle Tranfaglia
 * COSC220 - Lab03 - OYO - Ex.1
 * 02/20/2023
 * Circle Object Implementation
*/
#include "Circle.hpp"
// Default constructor that sets all values to zero
Circle::Circle() {
   x = y = radius = 0.0;
}
// Constructor that requires radius, x, and y values as doubles and bound checks the radius before setting
Circle::Circle(double r, double p1, double p2) {
    x = p1;
    y = p2;
    // Radius check. Must be positive, otherwise it is defaulted to zero
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
// Function to set the x and y values with parameter values
void Circle::setCenter(double p1, double p2) {
    x = p1;
    y = p2;
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
// Function to return the x value of the center
double Circle::getCenterX() {
    return x;
}
// Function to return the y value of the center
double Circle::getCenterY() {
    return y;
}
// Function to return if the circles collide, meaning the distance between centers is <= the sum of the radii
 bool Circle::collide(Circle obj) {
    bool status = false; // Defaulted false
    double radSum = radius + obj.getRadius(); // sums the radii
    double distance = sqrt((pow((x - obj.getCenterX()), 2.0)) + (pow((y - obj.getCenterY()), 2.0))); // Distnace formula to calculate distance
    // Circles collide if comparison is true so status is set to true
    if (distance <= radSum) {
        status = true;
    }
    return status;
 }