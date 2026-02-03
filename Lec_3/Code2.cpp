#include <iostream>
using namespace std;

// sum of numbers 1 to n

int main() {
    int n, sum = 0;
    cout << "Enter N: ";
    cin >> n;
    // for (int i = 0; i <= n; i++) {
    //     sum = sum + i;
    // }
    int i = 0;
    while (i <= n) {
        sum = sum + i;
        i++;
    }
    cout << "Sum = " << sum;
    return 0;
}

// Break -> exit loop
// Continue -> skip that iteration

/*
Do while loop & nested loop
*/