#include <iostream>
using namespace std;

// Butterfly pattern
int main() {
    int n = 4;  // Adjust n as needed

    // Upper half
    for (int i = 0; i < n; i++) {
        // Left asterisks
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        // Middle spaces
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << " ";
        }
        // Right asterisks
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 0; i--) {
        // Left asterisks
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        // Middle spaces
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << " ";
        }
        // Right asterisks
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}