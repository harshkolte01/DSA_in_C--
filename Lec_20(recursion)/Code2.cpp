#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printAllSubsets(vector<int>& arr, vector<int>& ans, int i) {
    if (i == arr.size()) {
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // include
    ans.push_back(arr[i]);
    printAllSubsets(arr, ans, i+1);
    
    ans.pop_back(); // Backtracking
    // exclude
    printAllSubsets(arr, ans, i+1);

}

/*
78. Subsets
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

class SolutionOfSubsets {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back({ans});
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();
        // exclude
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

/*
90. Subsets II
Medium
Topics
premium lock icon
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class SolutionSubsetsII {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();

        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        getAllSubsets(nums, ans, idx, allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};


int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;

    printAllSubsets(arr, ans, 0);
    return 0;
}