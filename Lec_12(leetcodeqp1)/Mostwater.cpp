#include <iostream>
#include <vector>
using namespace std;

// Brute Force
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); i++) {
                int w = j - i;
                int ht = min(height[i], height[j]);
                int currWater = w * ht;
                maxWater = max(maxWater, currWater);
            }
        }
        return maxWater;
    }
};

// 2 Pointer approach
class OptimizedSolution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int lp = 0;
        int rp = n - 1;
        while (lp < rp) {
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w * ht;
            maxWater = max(maxWater, currWater);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};