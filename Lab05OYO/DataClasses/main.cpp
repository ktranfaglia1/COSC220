/* Kyle Tranfaglia
 * COSC220 - Lab05 - OYO - Ex.1
 * 03/06/2023
 * This program is a test file provided by Dr. Tu to test the functionality of the customer and person data classes
*/
#include <iostream>

#include "PersonData.h"
#include "CustomerData.h"

using namespace std;

int main() {
    PersonData P1;
    P1.setName("Junyi", "Tu");
    P1.setAddress("1101 Camden Ave.", "Salisbury", "MD", "21801");
    P1.setPhone("410-677-0027");

    P1.printRecord();
    cout << endl;
    cout << P1.getRecord() << endl;
    cout << endl;

    PersonData *P2 = new PersonData();
    P2->setName("John", "Doe");
    P2->setAddress("Nowhere Ave.", "Podunk", "NB", "66666");
    P2->setPhone("123-456-7890");

    P2->printRecord();
    cout << endl;
    cout << P2->getRecord() << endl;
    cout << endl;

    CustomerData *P3 = new CustomerData();
    P3->setName("Jane", "Doe");
    P3->setAddress("Nowhere Ct.", "Podunk", "NB", "66666");
    P3->setPhone("987-798-1111");
    P3->setCustomerNumber(12345);
    P3->setMailingList(false);

    P3->printRecord();
    cout << endl;
    cout << P3->getRecord() << endl;
    cout << endl;

    PersonData *costumers[5];
    costumers[0] = P2;
    costumers[1] = P3;

    for (int i = 0; i < 2; i++) {
    costumers[i]->printRecord();
    cout << endl;
    }

    delete P2;
    delete P3;
    P2 = nullptr;
    P3 = nullptr;

    return 0;
}