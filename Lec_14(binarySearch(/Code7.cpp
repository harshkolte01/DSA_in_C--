#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
N=5

C = 3

Aggressive Cows Problem
Assign C cows to N stalls such that min distance between them is largest possible.
Return largest minimum distance.

arr = (1, 2,8, 4, 9]
*/

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDistance) {
    int cows = 1;
    int lastStallPos = arr[0];

    for (int i = 1; i < N; i++) {
        if(arr[i] - lastStallPos >= minAllowedDistance) {
            cows++;
            lastStallPos = arr[i];
        } 
        if (cows == C) {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end());
    int start = 1, end = arr[N - 1] - arr[0], ans = -1;

    while (start <= end) {
        int mid = start + ((end - start) / 2);

        if(isPossible(arr, N, C, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout << getDistance(arr, N, C) << endl;

    return 0;
}
