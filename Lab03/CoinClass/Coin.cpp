/* Kyle Tranfaglia
 * COSC220 - Lab03 - Ex.2
 * 02/14/2023
 * Coin Object Implementation
*/
#include "Coin.hpp"
// Default Constructor
Coin::Coin() {
    srand(time(0));
    // Generates random number between 1 and two and then sets tails if 1 and heds if 2
    if ((rand() % 2 + 1) == 1) {
        sideUp = "tails";
    }
    else {
        sideUp = "heads";
    }
} 
// Function to toss the coin, meaning it randomizes the face up value
void Coin::toss() {
    // generates random number between 1 and two and then sets tails if 1 and heds if 2
    if ((rand() % 2 + 1) == 1) {
        sideUp = "tails";
    }
    else {
        sideUp = "heads";
    }
}
// Function to return the side up of the coin
string Coin::getSideUp() {
    return sideUp;
}