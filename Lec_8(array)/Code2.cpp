#include <iostream>
using namespace std;

// calculate sum & product of array
void sum_prod_array(int arr[], int sz) {
    int sum = 0;
    int prod = 1;
    for (int i = 0; i < sz; i++) {
        sum = sum + arr[i];
        prod = prod * arr[i];
    }
    cout << "SUM: " << sum << "  PROD: " << prod << endl;
}

// Write a program to print unique values

void unique_value(int arr[], int sz) {
    for (int i =0; i < sz;i++) {
        int value = arr[i];
        int count = 0;
        for (int i =0; i < sz; i++) {
            if (value == arr[i]) {
                count++;
            }
        }
        if (count == 1) {
            cout << "Unique Value: " << value << " " << endl;
        }
    }
}

// print intersection of two arrays (common element)

void intersection_array() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {3, 4, 5, 6, 7};

    for (int i = 0; i < 5; i++) {
        int value = arr1[i];
        for (int i = 0; i < 5; i++) {
            if (value == arr2[i]){
                cout << value << " " << endl;
            }
        }
    }
}

int main() { 
    int arr[] = {1, 2, 3, 4, 5, 2, 1, 2, 3, 4, 6};
    int sz = 11;
    // sum_prod_array(arr, sz);
    unique_value(arr, sz);
    intersection_array();
    return 0;
}