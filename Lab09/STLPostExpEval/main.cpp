/* Kyle Tranfaglia
 * COSC220 - Lab09 - InLab - Ex.1
 * 04/18/2023
 * Postfix Expression Evaluator that uses the STL Queue to tokenize parsed input and uses STL Stack to evaluate the expression
*/
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    // Variables
    string input = "", token = "";
    char character = ' ';
    double number = 0, popValue1 = 0, popValue2 = 0;

    // Object Variable
    queue<string> tokens;
    stack<double> stk;

    cout << "Enter a postfix expression with spaces seperating each operand and operator: ";
    getline(cin, input);

    stringstream inputstream(input);

    // Function to tokenize the input with respect to ' '
    while (getline(inputstream, token, ' '))
        tokens.push(token); // Enqueues the parsed token
    
    int sz = tokens.size(); // Captures size to have a constant for the for loop terminating comaprison, otherwise, size would chnage after each dequeue
    // Loop to index through all tokens in list, assign each index to a token string and evaluate if it is an operand or operator
    for (int i = 0; i < sz; i++) {
        token = tokens.front(); // Gets front item in queue 
        tokens.pop(); // Removes front item FIFO
        // Continues if the token is not an empty string
        if (token != "") {
            character = token[0]; // Extracts first character of string
            // Idetify if it is a number (between ASCII values of 0 and 9) using first character ... if it is a multidigit number, it will convert the entire 
            // string to a decimal but to use ASCII values for comparison, it must be a single digit. Otherwise, it checks if the character is an accepted operator
            if (character >= '0' && character <= '9') {
                number = stod(token); // Converts a string to decimal using C++ string class
                stk.push(number); // Pushes the value to the top of the stack
            }
            else if (token == "+") {
                popValue1 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                popValue2 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                stk.push(popValue2 + popValue1); // Pushes the value of the operation to the top of the stack
            } 
            else if (token == "-") {
                popValue1 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                popValue2 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                stk.push(popValue2 - popValue1); // Pushes the value of the operation to the top of the stack
            } 
            else if (token == "*") {
                popValue1 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                popValue2 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                stk.push(popValue2 * popValue1); // Pushes the value of the operation to the top of the stack
            } 
            else if (token == "/") {
                popValue1 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                popValue2 = stk.top(); // Gets top value
                stk.pop(); // Removes value from top of stack
                stk.push(popValue2 / popValue1); // Pushes the value of the operation to the top of the stack
            }
        }
    }
    
    number = stk.top(); // Removes final number in stack ... the value of the completed operation
    cout << "Value = " << number << endl;

    return 0;
}