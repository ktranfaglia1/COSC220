/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.1
 * 03/13/2023
 * PreferredCustomer Object Implementation
*/
#include "PreferredCustomer.h"

// Default Constructor
PreferredCustomer::PreferredCustomer() {
    purchasesAmount = 0;
    discountLevel = 0;
}
// Function to set the purchase amount and assign the corresponding discount
void PreferredCustomer::setPurchaseAmount(double p) {
    // Input Validation check
    if (p < 0) {
        cout << "Invalid input...Setting amount to 0" << endl;
        purchasesAmount = 0;
    }
    else {
        purchasesAmount = p;
        // Assigns discount depending on amount and checks greatest discount decending
        if (purchasesAmount >= 2000)
            discountLevel = 0.10;
        else if (purchasesAmount >= 1500)
            discountLevel = 0.07;
        else if (purchasesAmount >= 1000)
            discountLevel = 0.06;
        else if (purchasesAmount >= 500)
            discountLevel = 0.05;
        else 
            discountLevel = 0;
    }
}
// Function to print the record of the individual using a scoped print of base class first and then adding a print of derived class memeber variables
void PreferredCustomer::printRecord() {
    CustomerData::printRecord();
    cout << "Purchases Amount: $" << purchasesAmount << endl;
    cout << "Discount Level: " << discountLevel*100 << "%";
}
// Fucntion to get the record of the individual using a scoped get record of base class first and then adding a the derived class memeber variables to the string
string PreferredCustomer::getRecord() {
    return CustomerData::getRecord() + " / Account: $" + to_string(purchasesAmount) + " / Discount: " + to_string(discountLevel*100) + "%";
}