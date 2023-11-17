/* Kyle Tranfaglia
 * COSC220 - project1 - Ex.1
 * 03/13/2023
 * PersonData Object Implementation
*/
#include "CustomerData.h"

// Constructor
CustomerData::CustomerData() {
}
// Function to print all member variables of PersonData object and then the CustomerData object member variables in a nice list
void CustomerData::printRecord() {
    PersonData::printRecord();
    cout << "Customer Number: " << customerNumber << endl;
    cout << "On the mailing list: ";
    // Asseses boolean variable to assign a yes or no rather than true or false
    if (mailingList)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
// Function to get all the member variables of base and derived class object in a single string seperated by a forward slash
string CustomerData::getRecord() {
    string record = PersonData::getRecord() + " / C#: " + to_string(customerNumber) + " / ML: ";
    // Asseses boolean variable to assign a yes or no rather than true or false
    if (mailingList)
        record += "Yes";
    else
        record += "No";

    return record;
}