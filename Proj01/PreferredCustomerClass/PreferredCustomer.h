/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.1
 * 03/13/2023
 * PreferredCustomer Object Declaration
*/
#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

#include "CustomerData.h"

class PreferredCustomer : public CustomerData {
    private:
        double purchasesAmount;
        double discountLevel; 
    public:
        PreferredCustomer(); // Constructor
        // Mutator functions
        void setPurchaseAmount(double p);
        // Accessor functions
        double getPurchaseAmount() {return customerNumber;};
        double getDiscountLevel() {return mailingList;};
        // Functions
        void printRecord();
        string getRecord();
};

#endif