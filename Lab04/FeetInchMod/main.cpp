/* Kyle Tranfaglia
 * COSC220 - Lab04 - Ex.1
 * 02/21/2023
 * This program showcases the fucntionality of modified operator overload code from class source code
*/
#include <iostream>
#include "FeetInches.h"

using namespace std;

int main() {
   double d1, d2;  // To hold double input
   int i1, i2;     // To hold int input

   // Define a FeetInches object.
   FeetInches distance1, distance2;

   // Get a distance from the user.
   cout << "Enter a distance in feet and inches:\n";
   cin >> distance1;
   cout << "Enter another distance in feet and inches:\n";
   cin >> distance2;

   // Convert the distance object to a double.
   d1 = distance1;
   d2 = distance2;

   // Convert the distance object to an int.
   i1 = distance1;
   i2 = distance2;

   // Display the values.
   cout << "The value " << distance1;
   cout << " is equivalent to " << d1 << " feet\n";
   cout << "or " << i1 << " feet, rounded down.\n";

   cout << "The value " << distance2;
   cout << " is equivalent to " << d2 << " feet\n";
   cout << "or " << i2 << " feet, rounded down.\n";
   // Uses operator overloads to determine relations of distances and if statments to display the relation given boolean return
   // <= operator comparison
   cout << "The value " << distance1 << " is";
   if (distance1 <= distance2)
      cout << " less than or equal to ";
   else
      cout << " not less than or equal to ";

   cout << distance2 << endl;
   // >= operator comparison
   cout << "The value " << distance1 << " is";
   if (distance1 >= distance2)
      cout << " greater than or equal to ";
   else
      cout << " not greater than or equal to ";

   cout << distance2 << endl;
   // != operator comparison
   cout << "The value " << distance1 << " is";
   if (distance1 != distance2)
      cout << " not equal to ";
   else
      cout << " equal to ";

   cout << distance2 << endl;

   return 0;
}