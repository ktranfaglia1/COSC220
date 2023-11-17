/* Kyle Tranfaglia
 * COSC220 - project1 - Ex.1
 * 03/13/2023
 * CustomerData Object Declaration
*/
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData {
    protected:
        int customerNumber = 0;
        bool mailingList = false;
    public:
        CustomerData(); // Constructor
        // Mutator functions
        void setCustomerNumber(int n) {customerNumber = n;}
        void setMailingList(bool status) {mailingList = status;}
        // Accessor functions
        int getCustomerNumber() {return customerNumber;}
        bool getMailingList() {return mailingList;}
        // Functions
        virtual void printRecord();
        virtual string getRecord();
};

#endif