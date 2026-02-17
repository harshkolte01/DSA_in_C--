#include <iostream>
#include <vector>

using namespace std;

/* 
 Digits in a numbers

Same logic for
- count of digit
- sum of digit
- print digit
*/

void printDigits(int n) {
    while (n != 0) {
        int digit = n % 10;
        cout << digit << " ";
        n = n / 10;
    }
}

void countDigits(int n) {
    int count = 0;
    while (n != 0) {
        int digit = n % 10;
        count++;
        n = n / 10;
    }
    cout << count << " ";
}

void sumDigits(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum+=digit;
        n = n / 10;
    }
    cout << sum << " ";
}

// reverse a number
int reverseNo(int n) {
    int revNum = 0;
        while (n != 0) {

            int digit = n % 10;
            if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
                return 0;
            }
            revNum = (revNum * 10) + digit;
            n = n / 10;
        }
        return revNum;
}

/*
Armstrong Number

Armstrong number is a number that is equal to the sum of cubes of its digits.

153, 371,1
*/

bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    while(n != 0) {
        int digit = n % 10;
        sum += pow(digit, 3);
        n = n / 10;
    }
    return sum == original;
}

/*
GCD / HCF
a = 20, b = 28;
*/

// simple approach
int gcd(int a, int b) {
    int gcd;
    for(int i = 1; i < min(a, b); i++) {
        if (a%i==0 && b%i ==0) {
            gcd = i;
        }
    }
    return gcd;
}
// gcd -> better approach -> euclids algorithm
int euclidsalgo(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if ( a == 0) return b;
    return a;
}

// gcd ends

// least common multiple (LCM)
int getLCM(int a, int b) {
    int lcm = (a * b) / gcd(a, b);
    return lcm;
}

// Palindrome no

bool isPalindrome(int n) {
        if (n < 0) return false;

        int revNum = reverseNo(n);
        return n == revNum;
}

/* modulo arithematic
850. Rectangle Area II
Hard
Topics
premium lock icon
Companies
You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.

Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.

Return the total area. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:


Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
From (1,1) to (2,2), the green and red rectangles overlap.
From (1,0) to (2,3), all three rectangles overlap.
Example 2:

Input: rectangles = [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 1018 modulo (109 + 7), which is 49.
 

Constraints:

1 <= rectangles.length <= 200
rectanges[i].length == 4
0 <= xi1, yi1, xi2, yi2 <= 109
xi1 <= xi2
yi1 <= yi2
All rectangles have non zero area.

*/


int main() {
    int n = 153;
    int a = 20, b = 28;

    // printDigits(n);
    // countDigits(n);
    // sumDigits(n);
    // cout << isArmstrong(n) << endl;
    // cout << gcd(a, b) << endl;
    // cout << euclidsalgo(a, b) << endl;
    //cout << getLCM(a, b) << endl;
    // reverseNo(n);
    // cout << isPalindrome(n) << endl;

    return 0;
}