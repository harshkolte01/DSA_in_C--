#include <iostream>
using namespace std;

// sum of all odd number from 1 to n

int main() {
    int n, sum = 0;
    cout << "Enter n: ";
    cin >> n;
    // for (int i = 0; i <= n; i++) {
    //     if (i % 2 != 0 ) {
    //         sum = sum + i;
    //     }
    // }
    int i = 0;
    while ( i <= n ) {
        if ( i % 2 != 0 ) {
            sum = sum + i;
            
        }
        i++;
    }
    cout << "Odd no sum: " << sum;
    return 0;
}