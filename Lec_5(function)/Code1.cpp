#include <iostream>
using namespace std;

int minNum(int n1, int n2) {
    int min = (n1 < n2) ? n1 : n2;
    return min;
}

int nFactorial(int n) {
    int fact = 1;
    for (int i = 1; i<=n; i++) {
        fact = fact * i;
    }
    return fact;
}

// calculate sum of digits of number

int sumOfDigit(int n) {
    int sum = 0;
    while(n > 0) {
        int digit = n % 10;
        sum = sum + digit;
        n = n / 10;
    }
    return sum;
}

// calculate ncr
int binomial(int n, int r) {
    int factofN = nFactorial(n);
    int factofR = nFactorial(r);
    int factnmr = nFactorial(n - r);

    double ncr = (factofN) / (factofR * factnmr);
    return ncr;
}

int checkPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(n); i+=2) {
        if (n % i == 0 ) return 0;
    }
    return 1;
}

void printNPrime(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (checkPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;
}

void Fibonacci(int n) {
    int a = 0;
    int b = 1;
    while ( n > 0 ) {
        cout << a << " ";
        int temp = a;
        a = b;
        b = temp + b;
        n--;
    }
}

int main() {
    cout << "Minimum= " << minNum(15, 3) << endl;
    cout << "Factorial= " << nFactorial(5) << endl;
    cout << "Sum of digit= " << sumOfDigit(145) << endl;
    cout << "Binomial NCR= " << binomial(8, 2) << endl;
    int isPrime = checkPrime(7);
    cout << "is Prime= " << (isPrime ? "Yes" : "No") << endl;
    printNPrime(10);
    Fibonacci(10);
}