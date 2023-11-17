/* Kyle Tranfaglia
 * COSC220 - Lab05 - OYO - Ex.1
 * 03/06/2023
 * PersonData Object Implementation
*/
#include "PersonData.h"
// Constructor
PersonData::PersonData() {
}
// Function to print all member variables of object in a nice list
void PersonData::printRecord() {
    cout << lastName << ", " << firstName << endl;
    cout << address << endl << city << ", " << state << " " << zip << endl;
    cout << phone << endl;
}
// Function to get all the member variables in a single string seperated by a forward slash
string PersonData::getRecord() {
    return firstName + " " + lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;
}