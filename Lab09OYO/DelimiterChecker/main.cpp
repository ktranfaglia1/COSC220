/* Kyle Tranfaglia
 * COSC220 - Lab09 - OYO - Ex.1
 * 04/24/2023
 * An Expression Delimiter Checker that uses STL stack to access delimiters to determine a balance or imbalance
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Variables
    string input = "";
    char top = ' ', currentChar = ' ';
    bool status = true;

    // Object Variable
    stack<char> stk;

    // Gets Expression from user
    cout << "Enter expression: ";
    getline(cin, input);

    // Loop to run for length of user input string (number of characters)
    for (unsigned int i = 0; i < input.length(); i++) {
        currentChar = input[i]; // Char variable to store the character at i index of the string

        // Statement to add the value of current to the top of the stack if it is a opening delimiter
        if (currentChar == '[' || currentChar == '{' || currentChar == '(') {
            stk.push(currentChar);
        }
        // Statement to caputure and remove the value at the top of the stack and test statements that render the expression not balanced.
        // Statement only runs if the delimiter of current is closed as it either satisfies a proper closing or is an error and non-delimiters are not needed
        else if (currentChar == ']' || currentChar == '}' || currentChar == ')') {
            // If stack is empty, breaks out of loop and sets status to false since there is a closing delimiter prior to an opening.
            // This could result from the very first delimiter being closed or anywhere along the string as the pop function call 
            // could result in an empty stack after all previously opened dilimiters are closed
            if (stk.empty()) {
                status = false;
                break;
            }
            // Top and Pop
            top = stk.top();
            stk.pop();
            // Statement to check if the current closing delimiter is closing the most recently opened dilimter (the value last added 
            // to the stack - top), and if not, then there is a delimiter imbalance and so status is set to false and the loop terminates
            if ((currentChar == ')' && top != '(') || (currentChar == '}' && top != '{') ||(currentChar == ']' && top != '[')) {
                status = false;
                break;
            }
        }
    }
    // Statement to check boolean values after loop terminates. If the stack is empty, meaning the number of opening and closing delimiters 
    // were equal - all opening delimiters were removed from the stack. This must be compared as even if status is true, meaning
    // nothing triggered a "must be imbalanced statment," the stack could end in an opening delimiter and not influence a status change.
    // Status is defaulted to true and must be true as well as stack empty as there are two statements tested above that immediately determine
    // the delimiters to not be balanced, even if more of the expression remains. The Delimiter status is printed accordingly
    if (stk.empty() && status) {
        cout << "Delimiters are balanced" << endl;
    }
    else {
        cout << "Delimiters are not balanced" << endl;
    }

    return 0;
}