/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.1
 * 03/13/2023
 * Program to illustrates the dynamic binding of the class structures and allows the user to select the class to add data to it
*/
#include "PreferredCustomer.h"

// Prototypes
void DisplayMenu();
void SetPersonData(PersonData *);
void SetCustomerData(CustomerData *);
void SetPreferredCustomer(PreferredCustomer *);

int main() {
    // Variables
    PersonData *objStorage[10];
    int databaseSize = 0, choice = 0;

    // Loop to continue to run program and redisplay the menu as long as the user does not select 6
    while (choice != 6) {
        // Displays menu and gets the user input
        DisplayMenu();
        cout << "\nChoice: ";
        cin >> choice;
        cout << endl;
        // User choice matches to statement and either dynamically creates a pointer to one of 3 objects
        // in class hierarchy and adds it to array or prints the database of objects in a long or condensed form
        if (choice == 1) {
            PersonData *pd = new PersonData();
            SetPersonData(pd);
            *(objStorage + databaseSize) = pd;
            databaseSize++;
        }
        else if (choice == 2) {
            CustomerData *cd = new CustomerData();
            SetCustomerData(cd);
            *(objStorage + databaseSize) = cd;
            databaseSize++;
        }
        else if (choice == 3) {
            PreferredCustomer *pc = new PreferredCustomer();
            SetPreferredCustomer(pc);
            *(objStorage + databaseSize) = pc;
            databaseSize++;
        }
        else if (choice == 4) {
            for (int i = 0; i < databaseSize; i++) {
                objStorage[i]->printRecord();
                cout << endl;
            }
        }
        else if (choice == 5) {
            for (int i = 0; i < databaseSize; i++) {
                cout << objStorage[i]->getRecord() << endl;
            }
        }
    }
    // Uses a loop to delete all the indexes of the database as they are all dynamically allocated array pointers
    for (int i = 0; i < databaseSize; i++) {
        delete objStorage[i];
    }

    return 0;
}
// Fucntion to display a menu
void DisplayMenu() {
    cout << "\nWhat would you like to do" << endl;
    cout << "1. Add Personal Data Object" << endl;
    cout << "2. Add Customer Data Object" << endl;
    cout << "3. Add Preferred Customer Data Object" << endl;
    cout << "4. View Database Long Form" << endl;
    cout << "5. View Database Short Form" << endl;
    cout << "6. Quit" << endl;
}
// Function to accept a pointer to PersonData object and ask the user for the needed input to fill the object
// and uses the set functions for the object to assign the user input
void SetPersonData(PersonData *obj) {
    string dummy = "";

    cout << "Input First Name: ";
    cin >> dummy;
    obj->setFirstName(dummy);

    cout << "Input Last Name: ";
    cin >> dummy;
    obj->setLastName(dummy);

    cout << "Input Street Address: ";
    cin.ignore();
    getline(cin, dummy);
    obj->setStreet(dummy);

    cout << "Input City: ";
    cin >> dummy;
    obj->setCity(dummy);

    cout << "Input State: ";
    cin >> dummy;
    obj->setState(dummy);

    cout << "Input Zip Code: ";
    cin >> dummy;
    obj->setZip(dummy);

    cout << "Input Phone Number: ";
    cin >> dummy;
    obj->setPhone(dummy);
}
// Function to accept a pointer to Customer object, call function to fill base object and ask the
// user for the needed input to fill the object and uses the set functions for the object to assign the user input
void SetCustomerData(CustomerData *obj) {
    int number = 0;
    char mail = ' ';

    SetPersonData(obj);

    cout << "Input Customer Number: ";
    cin >> number;
    obj->setCustomerNumber(number);

    cout << "Do they wish to be on the mailing list? (Y/N): ";
    cin >> mail;
    // Sends boolean value to object depending on user input as string
    if (mail == 'y' || mail == 'Y')
        obj->setMailingList(true);
    else 
        obj->setMailingList(false);

}
// Function to accept a pointer to PreferredCustomer object, call function to fill derived object and ask the
// user for the needed input to fill the object and uses the set functions for the object to assign the user input
void SetPreferredCustomer(PreferredCustomer *obj) {
    double money = 0;

    SetCustomerData(obj);

    cout << "Input Purchases Amount: ";
    cin >> money;
    obj->setPurchaseAmount(money);
}