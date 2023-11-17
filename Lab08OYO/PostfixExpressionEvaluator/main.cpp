/* Kyle Tranfaglia
 * COSC220 - Lab08 - OYO - Ex.1
 * 04/10/2023
 * Postfix Expression Evaluator that uses the ListCollectoion and DynamicStack class to tokenize input and evaluate the expression
*/
#include <iostream>
#include <sstream>
#include "ListCollection.h"
#include "DynamicStack.h"

using namespace std;

int main() {
    // Variables
    string input = "", token = "";
    char character = ' ';
    double number = 0, popValue1 = 0, popValue2 = 0;

    // Object Variable
    ListCollection<string> tokens;
    DynamicStack<double> stack;

    cout << "Enter a postfix expression with spaces seperating each operand and operator: ";
    getline(cin, input);

    stringstream inputstream(input);

    // Function to tokenize the input with respect to ' '
    while (getline(inputstream, token, ' '))
        tokens.pushBack(token);
    // Loop to index through all tokens in list, assign each index to a token string and evaluate if it is an operand or operator
    for (int i = 0; i < tokens.size(); i++) {
        token = tokens.getElement(i);
        // Continues if the token is not an empty string
        if (token != "") {
            character = token[0]; // Extracts first character of string
            // Idetify if it is a number (between ASCII values of 0 and 9) using first character ... if it is a multidigit number, it will convert the entire 
            // string to a decimal but to use ASCII values for comparison, it must be a single digit. Otherwise, it checks if the character is an accepted operator
            if (character >= '0' && character <= '9') {
                number = stod(token); // Converts a string to decimal using C++ string class
                stack.push(number); // Pushes the value to the top of the stack
            }
            else if (token == "+") {
                stack.pop(popValue1); // Removes value from top of stack and captures the removed item by reference parameter
                stack.pop(popValue2); // Removes value from top of stack and captures the removed item by reference parameter
                stack.push(popValue2 + popValue1); // Pushes the value of the operation to the top of the stack
            } 
            else if (token == "-") {
                stack.pop(popValue1); // Removes value from top of stack and captures the removed item by reference parameter
                stack.pop(popValue2); // Removes value from top of stack and captures the removed item by reference parameter
                stack.push(popValue2 - popValue1); // Pushes the value of the operation to the top of the stack
            } 
            else if (token == "*") {
                stack.pop(popValue1); // Removes value from top of stack and captures the removed item by reference parameter
                stack.pop(popValue2); // Removes value from top of stack and captures the removed item by reference parameter
                stack.push(popValue2 * popValue1); // Pushes the value of the operation to the top of the stack
            } 
            else if (token == "/") {
                stack.pop(popValue1); // Removes value from top of stack and captures the removed item by reference parameter
                stack.pop(popValue2); // Removes value from top of stack and captures the removed item by reference parameter
                stack.push(popValue2 / popValue1); // Pushes the value of the operation to the top of the stack
            }
        }
    }
    stack.pop(number); // Removes final number in stack ... the value of the completed operation
    cout << "Value = " << number << endl;

    return 0;
}
