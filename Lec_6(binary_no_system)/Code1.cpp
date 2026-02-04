#include <iostream>
using namespace std;

// Decimal to binary
void decTobin(int n)
{
    int decN = n;
    int ans = 0;
    int pow = 1;
    while (decN > 0)
    {
        int rem = decN % 2;
        decN = decN / 2;
        ans += rem * pow;
        pow = pow * 10;
    }

    cout << "Decimal to Binary: " << ans << endl;
}

// Binary to decimal
int binToDec(int n) {
    int binN = n;
    int pow = 1;
    int ans = 0;

    while (binN > 0) {
        int rem = binN % 10;
        ans += rem * pow;
        binN /= 10;
        pow = pow * 2;
    }
    cout << "Binary to Decimal: " << ans << endl;
    return ans;
}

// 2's compliment
void secCompliment(int n) {
    int binN = binToDec(n);
    
}

int main()
{
    decTobin(10);
    binToDec(1010);
}