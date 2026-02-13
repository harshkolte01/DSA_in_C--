#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> vec, int target) {
    int start = 0;
    int end = vec.size() - 1;
    while (start <= end) {
        // int mid = (start + end) / 2;
        // to avoid overflow
        int mid = start + ((end - start) / 2);
        if (target > vec[mid]) {
            start = mid + 1;
        }
        else if (target < vec[mid]) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

// recursive binary array

int recursiveBinary(vector<int> vec, int target, int start, int end) {
    if (start <= end) {
        int mid = start + ((end - start) / 2);
        if (target > vec[mid]) {
            return recursiveBinary(vec, target, start, end);
        } else if(target < vec[mid]) {
            return recursiveBinary(vec, target, start, end);
        } else {
            return mid;
        }
    }
    return -1;
}
int main() {
    // vector<int> vec = {0, 1, 2, 3, 4, 19, 243, 2999};
    vector<int> vec = {1, 2, 3, 4, 19, 243, 2999};
    int target = 4;

    cout << binarySearch(vec, target) << endl;
    int start = 0;
    int end = vec.size() - 1;
    cout << recursiveBinary(vec, target, start, end);

    return 0;
}