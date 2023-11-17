/* Kyle Tranfaglia
 * COSC220 - Lab03 - Ex.1
 * 02/20/2023
 * This Program tests the fucntionality of the NumArray class by using its member functions
*/
#include <iostream>
#include "Circle.hpp"

using namespace std;

int main() {
    // Variables 
    Circle circ1;
    // sets the circle radius to 10.5 and prints the radius from the accessor function for testing
    cout << "Defaulted Circle created \nRadius: " << circ1.getRadius() << endl;
    cout << "Setting the radius to 10.5... " << endl;
    circ1.setRadius(10.5);
    cout << "New Radius: " << circ1.getRadius();
    // Uses the same circle with a 10.5 radius and calls the member functions to do calculations and displays the results
    cout << "\nCircle Calculations" << endl;
    cout << "Diameter: " << circ1.getDiameter() << endl;
    cout << "Area: " << circ1.getArea() << endl;
    cout << "Circumference: " << circ1.getCircumference() << endl;
    // Prompts the user to create a circle object
    cout << "\nCreate a Circle" << endl;
    cout << "Enter a radius: ";
    int radius = 0;
    cin >> radius;
    cout << "Creating the Circle..." << endl;
    Circle circ2(radius);
    // Uses the user made circle and calls the member functions to do calculations and displays the results
    cout << "\nCircle Calculations" << endl;
    cout << "Radius: " << circ2.getRadius() << endl;
    cout << "Diameter: " << circ2.getDiameter() << endl;
    cout << "Area: " << circ2.getArea() << endl;
    cout << "Circumference: " << circ2.getCircumference() << endl;

    return 0;
}