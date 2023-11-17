/* Kyle Tranfaglia
 * Test Code
 * 05/18/2023
*/
#include <iostream>

using namespace std;

int main() {
    int size = 10;
    int *a = new int[size];
    int *b = new int[size];

    for (int i = 0; i < size; i++) {
        *(a + i) = i;
        cout << *(a + i) << " ";
    }
    cout << endl;
    for (int i = 0, j = size - 1; i < size; i++, j--) {
        *(b + i) = *(a + j);
        cout << *(b + i) << " ";
    }
    cout << endl;

    delete [] a;
    delete [] b;
}