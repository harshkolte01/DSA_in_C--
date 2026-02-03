#include <iostream>
using namespace std;

/* Ascii Value 
A -> 65, Z -> 90
a -> 97, z -> 122 
*/

int main() {
    char ch;
    cout << "Enter Character: ";
    cin >> ch;

    if (ch >= 'a' && ch <= 'z') {
        cout << "Character is lowercase";
    } else {
        cout << "Character is uppercase";
    }
    return 0;
}

// ternary statement
/*
val = condition ? val1 (true) : val2 (false)
*/