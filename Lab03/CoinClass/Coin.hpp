/* Kyle Tranfaglia
 * COSC220 - Lab03 - Ex.2
 * 02/14/2023
 * Coin Object Declaration
*/
#ifndef COIN_HPP
#define COIN_HPP

#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Coin {
private:
    string sideUp;
public:
    Coin(); // Default Constructor
    void toss();
    string getSideUp();
};

#endif
