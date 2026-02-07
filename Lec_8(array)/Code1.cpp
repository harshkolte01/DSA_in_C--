// Arrays
#include <iostream>
using namespace std;

int initializeArray() {
    int arr[5];
    int marks[5] = {1, 2, 3, 4, 5};
    int price[] = {1, 2, 3, 4};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_size; i++) {
        cout << "Enter Value: ";
        cin >> arr[i];
    }
    for (int i = 0; i < arr_size; i++) {
        cout << "Value: " << arr[i] << " ";
    }
    return 0;
}

//Smallest and largest array
void checkValue() {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int arr[5] = {10, 8, 12, 14, 7};
    int arr_size = 5;

    for (int i = 0; i < arr_size; i++) {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }
        cout << "Smallest Value: " << smallest << endl;
        cout << "Largest Value: " << largest;
}

void checkValueWithIndex() {
    int arr[5] = {10, 2, 5, 12, 1};
    int size = 5;
    int smallest = arr[0];
    int smallest_idx = 0;
    int largest = arr[0];
    int largest_idx = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_idx = i;
        }
        if (arr[i] > largest) {
            largest = arr[i];
            largest_idx = i;
        }
    }
    swap(arr[smallest_idx], arr[largest_idx]);

for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}
    cout << endl;
        cout << "Smallest Value: " << smallest << " Index: " << smallest_idx << endl;
        cout << "Largest Value: " << largest << " Index: " << largest_idx << endl;
}

//write about pass by reference

// Linear search

int linearSearch(int target_value) {
    int arr[5] = {1, 2, 10, 12, 15};
    int size = 5;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target_value) {
            cout << "Value Found at " << i << "  index." << endl;
            break;
        }
    }
    return -1;
}

// reverse array
void reverseArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for (int i = 0; i < size; i++) {
        cout << "Value: " << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    // initializeArray();
    checkValueWithIndex();
    linearSearch(100);
    reverseArray();


    return 0;
}