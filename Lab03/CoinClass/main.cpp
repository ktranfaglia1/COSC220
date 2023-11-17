/* Kyle Tranfaglia
 * COSC220 - Lab03 - Ex.2
 * 02/14/2023
 * This Program tests the fucntionality of the coin class by using its member functions to flip a coin
*/
#include <iostream>
#include "Coin.hpp"

using namespace std;

int main() {
    // Variables
    const int FLIPS = 20;
    int headCount = 0, tailCount = 0;
    Coin c;
    // Displays starting side up
    cout << "The coin is starting with " << c.getSideUp() << " side up" << endl;
    cout << "Flipping the coin 20 times" << endl;
    // Loop to call coin toss 20 times and display the side up while keeping count of heads and tails
    for (int i = 0; i < FLIPS; i++) {
        c.toss();
        cout << c.getSideUp() << endl;
        // Increments either head or tail count depending on results of coin flip results from getSideUp
        if (c.getSideUp() == "heads") {
            headCount++;
        }
        else {
            tailCount++;
        }
    }
    cout << "Head Count: " << headCount << "\nTail Count: " << tailCount << endl; // Displays the two counts

    return 0;
}