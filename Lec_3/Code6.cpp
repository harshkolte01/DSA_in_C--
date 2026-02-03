#include <iostream>
using namespace std;

// prime factorial
int main() {
    int n = 5, fact = 1;
    for ( int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    cout << fact;
    return 0;
}