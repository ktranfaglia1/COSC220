/* Kyle Tranfaglia
 * COSC220 - Lab03 - OYO - Ex.1
 * 02/20/2023
 * This Program tests the fucntionality of the Circle class by using its member functions to generate an array of 1000 random 
 * circles and report every pair of circles that collide
*/
#include <iostream>
#include "Circle.hpp"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); // Sets seed generator - time to zero to allow random number generation
    // Variables 
    const int SIZE = 1000;
    int collideCount = 0;
    double ranDouble = 0.0, ranX = 0.0, ranY = 0.0;
    Circle array[SIZE];
    // Loop to create random values for radius, x, and y for each circle in the array and set those values in the circle class
    for (int i = 0; i < SIZE; i++) {
        ranDouble = rand () * (static_cast<double>(2 - 1) / RAND_MAX) + 1; // Generates random double between 1 and 2
        ranX = rand () * (static_cast<double>(20 + 20) / RAND_MAX) - 20; // Generates random double between -20 and 20
        ranY = rand () * (static_cast<double>(20 + 20) / RAND_MAX) - 20; // Generates random double between -20 and 20
        array[i].setRadius(ranDouble);
        array[i].setCenter(ranX, ranY);
    }
    // Loop to compare each circle to all other circles and determine which pairs collide
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            // Sends in outer loop index and all inner loop indexes to see if pair collides, excluding self comparisons (i!=k)
            if (array[i].collide(array[k]) && i!=k) {
                collideCount++; // counts pairs that collide
                cout << "Circle " << i + 1 << " and " << k + 1 << " collide" << endl; // Displays the pair that collides
            }
        }
    }
    cout << collideCount << " Circles in the array collided" << endl; // Displays total pair count

    return 0;
}