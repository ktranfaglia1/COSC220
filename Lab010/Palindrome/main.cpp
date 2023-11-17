/* Kyle Tranfaglia
 * COSC220 - Lab10 - InLab - Ex.2
 * 04/24/2023
 * A recursive program to determine if a string is a palindrome
*/
#include <iostream>
#include <string>

using namespace std;

// Prototype for palindrome recursion function
bool isPal(const string& str, int startIndex, int endIndex);

// Prototype for function to convert a string to lowercase
string toLowercase(string str);


int main() {
	// Variable to hold string from user
	string str = "";
	
	// Gets a string from the user
	cout << "Enter a string with no spaces : ";
	cin >> str;

	str = toLowercase(str); // Converts the string to lowercase by calling a function that returns a lowercase version
	
	// Calls boolean recursive function with string and the beginning and ending index, then displays if it is a palindrome
	if (isPal(str, 0, str.length() - 1)) {
		cout << str << " is a palindrome" << endl;
	}
	else {
		cout << str << " is not a palindrome" << endl;
	}
	
	return 0;	
}
// Recursive function to return a boolean of palindrome status, that is true if palindrome and false otherwise
bool isPal(const string& str, int startIndex, int endIndex) {
	// Base case to return false if coresponding indexes (start and end) do not equal each other
	if (str[startIndex] != str[endIndex]) {
		return false;
	}
	// Recursive call if start index is less than end index, meaning not all indexes have been compared or one index remains in the middle
	else if (startIndex < endIndex) {
		return isPal(str, startIndex + 1, endIndex - 1); // Calls itself with same string and incremented start and decremented end
	}
	// Return true if string is 1 element or all corresponding indexes were compared or only
	// middle index remains such that the false determining base case was never triggered
	return true; 
}
// Function to convert a string to lowercase by copying the string sent as an arguement and returning a lowercase version
string toLowercase(string str) {
	// Iterative loop to run for length of string and use STL string function tolower to convert each character with an assignment at each index
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]); // Sets string at index to tolower result of string at index
	
	return str; // Returns the lowercase string
}