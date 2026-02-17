/*
Prime Numbers
*/

#include <iostream>
#include <vector>

using namespace std;

// to check n is prime or not 
int isPrime(int n) {
    int count = 0;
    for (int i = 2; i * i < n; i++) {
        if (n % i != 0) {
            count++;
        }
    }
    return count;
}

// print n prime numbers (sieve of eratosthenes)
/*
204. Count Primes
Medium
Topics
premium lock icon
Companies
Hint
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n + 1, true);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;

                for (int j = i * 2; j < n; j = j + i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};

int main() {
    int n = 50;
    cout << isPrime(n) << endl;
    return 0;
}