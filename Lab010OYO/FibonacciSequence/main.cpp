/* Kyle Tranfaglia
 * COSC220 - Lab10 - OYO - Ex.1
 * 05/01/2023
 * A program to test the computation expense of different fibonacci sequence functions by analyzing runtime with Linux Ubuntu
*/
#include <iostream>

using namespace std;

// Prototypes for iterative, binary recursion, and linear recursion fibonacci sequence functions
unsigned long long IterativeFib(int n);
unsigned long long BinaryRecursiveFib(int n);
unsigned long long LinearRecursiveFib(int n, unsigned long long value = 1, unsigned long long prev = 0);

int main() {
    // Variables
    // int n = -1;
    int n = 50;

    // while (n < 0) {
    //     cout << "Enter a natural number (including 0): ";
    //     cin >> n;

    //     if (n < 0)
    //         cout << "Invalid input! only numbers n >= 0 accepted" << endl;
    // }

    // Iterative loop to print the value at the ith index of the Fibonacci sequence using one of the function calls and goes for n elements
    for (int i = 0; i < n; i++) {
        // cout << IterativeFib(i) << " ";
        // cout << BinaryRecursiveFib(i) << " ";
        cout << LinearRecursiveFib(i) << " ";
    }

    return 0;
}
// Iterative Fibonacci Function to return the value at n index of the sequence
unsigned long long IterativeFib(int n) {
    // Base Case 1: n is zero, return zero
    if (n == 0)
        return 0;
    // Base Case 2: n 1 or 2, return 1
    if (n == 1 || n == 2)
        return 1;

    unsigned long long prev = 1, curr = 1, next = 0; // Variables to track n-2, n-1, and n
    // Iterative loop to calculate sequence value for indexes greater than 2 and up to n
    for (int i = 2; i < n; i++) {
        next = curr + prev; // Calculates the following term
        prev = curr; // Stores the term before newly calculated term
        curr = next; // sets current term to the newly calculated term
    }
    return curr; // Returns the current term ... last calculated when loop terminates
}
// Binary Recursion Fibonacci Function to return the value at n index of the sequence
unsigned long long BinaryRecursiveFib(int n) {
     // Base Case 1: n is zero, return zero
    if (n == 0)
        return 0;
    // Base Case 2: n 1 or 2, return 1
    if (n == 1 || n ==2)
        return 1;
    
    return BinaryRecursiveFib(n - 1) + BinaryRecursiveFib(n - 2); // Binary Recursive calls to return the sum of n-2 and n-1

}
// Linear Recursion Fibonacci Function to return the value at n index of the sequence
unsigned long long LinearRecursiveFib(int n, unsigned long long value, unsigned long long prev) {
    // Base Case that will always get triggered at some point and exit the recursive call, when n is zero it returns prev variable
    if (n == 0)
        return prev;
    // Recursive call to decrement the term number, set value as the sum of the previous two terms (prev and value), and set prev as value such that prev is always the last sumation
    return LinearRecursiveFib(n - 1, value + prev, value);
}

//**************************//
//* Fibonacci Runtime Data *//
//**************************//
/*
    Binary:     1m6.313s
    Linear:     0m0.001s
    Iterative:  0m0.001s

    Runtime data gathered using Linux Ubuntu terminal command "Time" and capturing "real" time data

*/
