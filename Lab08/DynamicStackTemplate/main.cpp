/* Kyle Tranfaglia
 * COSC220 - Lab08 - Ex.2
 * 04/04/2023
 * Driver program to test the functionality of the linked list based DynamicStack class
*/
#include "DynamicStack.h"

int main() {
// Creates StaticStack objects defaulted and set with a size and two items to hold the removed value
    DynamicStack<char> characters;
    DynamicStack<double> floating;
    char item1 = ' ';
    double item2 = 0;
    
    // Adds items to top of stack
    characters.push('1');
    characters.push('!'); 
    characters.push('7');  
    characters.push('m'); 
    characters.push('k'); 
    characters.push('%');
    characters.push('2'); 
    characters.push('u');
    characters.push('@');
    characters.push('p'); 
    
    // Removes item from stack and prints the item removed
    characters.pop(item1);
    cout << "Item Removed: " << item1 << endl;
    characters.pop(item1);
    cout << "Item Removed: " << item1 << endl;

    characters.PrintStack(); // Prints stack

    // Adds items to top of stack
    characters.push('v'); 
    characters.push('c'); 
    characters.push('x'); 

    characters.PrintStack(); // Prints stack

    cout << endl;

    // Adds items to top of stack
    floating.push(2.2);
    floating.push(3.5);
    floating.push(0.6);

    floating.PrintStack(); // Prints stack

    // Removes item from stack and prints the item removed
    floating.pop(item2);
    cout << "Item Removed: " << item2 << endl;
    floating.pop(item2);
    cout << "Item Removed: " << item2 << endl;
    floating.pop(item2);
    cout << "Item Removed: " << item2 << endl;
    floating.pop(item2);
    cout << "Item Removed: " << item2 << endl;

    floating.PrintStack(); // Prints stack

    // User created integer stack
    int size = 0, value = 0, item3 = 0; // Variables to hold user input 

    // Gets size from user
    cout << "what size stack would you like: ";
    cin >> size;

    DynamicStack<int> integers; // Creates stack

    // Prompts the user to enter a value for each index of stack and pushes the value
    for (int i = 0; i < size; i++) {
        cout << "Enter a stack item " << i + 1 << ": ";
        cin >> value;
        integers.push(value);
    }
    cout << endl;

    integers.PrintStack(); // Prints stack

    // Removes item from stack and prints the item removed
    integers.pop(item3);
    cout << "Item Removed: " << item3 << endl;
    integers.pop(item3);
    cout << "Item Removed: " << item3 << endl;

    // Adds items to top of stack
    integers.push(999);
    integers.push(600);
    integers.push(22);

    integers.PrintStack(); // Prints stack

    // Gets data on top and size
    cout << integers.getTop() << endl;
    cout << integers.getSize() << endl;

    integers.clear(); // Clears stack

    // Pushes values on now empty stack
    integers.push(1);
    integers.push(2);
    integers.push(3);

    integers.PrintStack(); // Prints stack

    // Gets data on top and size
    cout << integers.getTop() << endl;
    cout << integers.getSize() << endl;

    return 0;
}