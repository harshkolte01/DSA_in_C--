#include <iostream>

using namespace std;

/*
Character Array info

about null \0

*/

int main() {
    char str[10];
    cout << "enter words: ";
    // cin >> str;
    cin.getline(str, 100, '$');

    
    cout << "Output: " << str << endl;
}