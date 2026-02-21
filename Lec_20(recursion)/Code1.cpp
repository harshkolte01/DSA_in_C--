#include <iostream>
#include <vector>

using namespace std;
/*
Recurrance Relation - write about it in README.md
*/
void printNums(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    cout << n << " ";
    printNums(n-1);
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sumOfN(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumOfN(n - 1);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) return n; 

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// is array sorted
bool isArraySorted(vector<int> arr, int n) {
    if (n == 0 || n == 1) return true;

    return arr[n - 1] >= arr[n - 2] && isArraySorted(arr, n - 1);
}

// Binary Search

int binarySearch(vector<int>& arr, int target, int start, int end) {
        if (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] <= target) {
                return binarySearch(arr, target, mid + 1, end);
            } else {
                return binarySearch(arr, target, start, mid - 1);
            }
        }
        return -1;
    }
int search(vector<int>& arr, int target) {
        return binarySearch(arr, target, 0, arr.size() - 1);
    }

int main() {
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << isArraySorted(arr, arr.size());
    //cout << fibonacci(n);
    //cout << factorial(n);
    //cout << sumOfN(n);
    //printNums(5);
    return 0;
}