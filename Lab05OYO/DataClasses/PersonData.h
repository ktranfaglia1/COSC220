/* Kyle Tranfaglia
 * COSC220 - Lab05 - OYO - Ex.1
 * 03/06/2023
 * PersonData Object Declaration
*/
#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>
#include <string>

using namespace std;

class PersonData {
    protected:
        string lastName = "";
        string firstName = "";
        string address = "";
        string city = "";
        string state = "";
        string zip = ""; // Zip code as string rather than int as zip codes sometimes include "-" 
        string phone = ""; // Input may contain "-" as seperator so string is used opposed to int
    public:
        PersonData(); //Constructor
        // Mutator functions
        void setName(string first, string last) {firstName = first, lastName = last;};
        void setAddress(string ad, string ct, string st, string zp)  {address = ad, city = ct, state = st, zip = zp;};
        void setPhone(string ph) {phone = ph;};
        // Accessor fucntions
        string getFullName() {return firstName + " " + lastName;};
        string getLastName() {return lastName;};
        string getFirstName() {return firstName;};
        string getFullAddress() {return address + ". " + city + ", " + state + " " + zip;};
        string getAddress() {return address;};
        string getCity() {return city;};
        string getState() {return state;};
        string getZip() {return zip;};
        string getPhone() {return phone;};
        // Functions
        virtual void printRecord(); // Virtual used as polymorphism is required to overide fucntion and allow base-derived object assignment to result in a derived print
        virtual string getRecord(); // Virtual function for same reason ^
};

#endif