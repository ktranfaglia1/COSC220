/* Kyle Tranfaglia
 * COSC220 - Lab10 - InLab - Ex.1
 * 04/24/2023
 * A recursive program to calculate n choose k using the principle of Pascal's Triangle
*/
#include <iostream>

using namespace std;

// Prototype for recursive combinations funtion
unsigned long Combinations(int n, int k);

int main() {
	// Variables for n and k
	int n = 0, k = 0;
	
	// Gets n and k from user
	cout << "Enter n and k (integer) with a space between them: ";
	cin >> n;
	cin >> k;
	
	cout << n << " Choose " << k << " = " << Combinations(n, k) << endl; // Calls Combinations function and prints result
	
	return 0;
}
// Recursive Combinations function (n choose k)
unsigned long Combinations(int n, int k) {
	// First base case, if n or k is negative of k is greater than n, 0 is returned
	if (n < 0 || k < 0 || k > n) {
		return 0;
	}
	// Base case 2, if n or k is 0 or n equals k, 1 is returned
	else if (n == 0 || k == 0 || n == k) {
		return 1;
	}
	return (Combinations(n - 1, k) + Combinations(n - 1, k - 1)); // Recursive call using n choose k formula 
}