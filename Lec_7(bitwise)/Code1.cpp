#include <iostream>
using namespace std;

// check if number is power of 2
int checkNo(int n) {
    if (n <= 0) return 0;
    return (n & (n - 1)) == 0 ? 1 : 0;
}

// write the program to reverse the int
int revNo(int n) {
    int reversed = 0;
    while (n > 0) {
        int last_digit = n % 10;
        reversed = reversed * 10 + last_digit;
        n = n / 10;
    }
    return reversed;
}
int main() {
    cout << (6 & 10) << endl;
    cout << (6 | 10) << endl;
    cout << (6 ^ 10) << endl;
    cout << (8 << 2) << endl;

    cout << "Is 8 a power of 2? " << checkNo(8) << endl;
    cout << "Is 10 a power of 2? " << checkNo(10) << endl;

    cout << "Reverse of 123: " << revNo(123) << endl;
    cout << "Reverse of -456: " << revNo(-456) << endl; 


}