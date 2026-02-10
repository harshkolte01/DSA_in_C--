// Pair sum
// 2 7 11 15 -> target 9

#include <iostream>
#include <vector>
using namespace std;

// vector<int> pairSum(vector<int>& vec, int target) {
//     vector<int> ans;
//     for (int i = 0; i < vec.size(); i++) {
//         for (int j = i + 1; j < vec.size(); j++) {
//             if (vec[i] + vec[j] == target) {
//                 ans.push_back(i);
//                 ans.push_back(j);
//             }
//         }
//     }
//     return ans;
// }

vector<int> pairSum(vector<int>& vec, int target) {
    int i = 0;
    int j = vec.size() - 1;
    vector<int> ans;
    while (i < j) {
        int pairsum = vec[i] + vec[j];
        if (pairsum > target) {
            j--;
        }
        else if (pairsum < target) {
            i++;
        }
        else  {
            ans.push_back(i);
            ans.push_back(j);
            i++;
            j--;
        }
    }
    return ans;
}


int main() {
    vector<int> vec = {2, 7, 11, 15};
    int target = 13;
    vector<int> ans = pairSum(vec, target);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;

}