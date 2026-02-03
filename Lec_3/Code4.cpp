#include <iostream>
using namespace std;


// check prime number
int main() {
    int n = 11;
    for (int i = 2; i <= n - 1; i++) {
        if (n % i == 0) {
            cout << "It is prime number";
            break;
        }
        else {
            cout << "It is not prime number";
            break;
        }
    }
    return 0;
}