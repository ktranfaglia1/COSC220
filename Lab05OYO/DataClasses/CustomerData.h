/* Kyle Tranfaglia
 * COSC220 - Lab05 - OYO - Ex.1
 * 03/06/2023
 * CustomerData Object Declaration
*/
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

using namespace std;

class CustomerData : public PersonData {
    private:
        int customerNumber = 0;
        bool mailingList = false;
    public:
        CustomerData(); // Constructor
        // Mutator functions
        void setCustomerNumber(int n) {customerNumber = n;};
        void setMailingList(bool status) {mailingList = status;};
        // Accessor functions
        int getCustomerNumber() {return customerNumber;};
        bool getMailingList() {return mailingList;};
        // Functions
        void printRecord();
        string getRecord();
};

#endif