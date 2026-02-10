#include <iostream>
#include <vector>
using namespace std;

// Brute force
// int main() {
//     vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
//     int maxSum = INT_MIN;

//     for (int st = 0; st < vec.size(); st++) {
//         int currSum = 0;
//         for (int end = st; end < vec.size(); end++) {
//             currSum += vec[end];
//             maxSum = max(currSum, maxSum);
//         }
//     }
//     cout << maxSum;
//     return 0;
// }

int main() {
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < vec.size(); i++) {
        currSum += vec[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    cout << maxSum;

    return 0;
}