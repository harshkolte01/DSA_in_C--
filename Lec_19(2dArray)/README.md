# Lec 19 - 2D Arrays & Array Problems (Quick Revision)

---

## 2D Array Basics (Code1.cpp)

A 2D array is basically a matrix — rows and columns.

```cpp
int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
```

### Linear Search in 2D Matrix
Just loop through every element using two nested loops.  
**Time: O(n * m)**

### Max Row Sum / Max Column Sum
- Loop through each row, calculate sum, track maximum.
- For columns: swap i and j while accessing `matrix[j][i]`.

### Diagonal Sum
Two diagonals in a square matrix:
- **Primary diagonal**: `matrix[i][i]`
- **Secondary diagonal**: `matrix[i][n-i-1]`

> Watch out: If `i == n-i-1` (middle of odd-sized matrix), don't add it twice!

**Optimized — O(n)** (single loop instead of nested loops)

---

## Searching in a 2D Matrix (Code2.cpp)

### LC 74 - Search a 2D Matrix
**Properties:** Each row is sorted, first element of next row > last element of previous row.

**Approach:** Binary search on rows first to find which row the target can be in, then binary search within that row.  
**Time: O(log m + log n) = O(log(m*n))**

### LC 240 - Search a 2D Matrix II
**Properties:** Rows sorted left-to-right, columns sorted top-to-bottom.

**Approach (Staircase Search):** Start from **top-right corner**.
- If `target < current` → move left (col--)
- If `target > current` → move down (row++)

**Time: O(m + n)** — very clean trick!

### LC 54 - Spiral Matrix
Traverse the matrix layer by layer in spiral order: **Top → Right → Bottom → Left**, then shrink the boundaries.

Use 4 pointers: `srow, erow, scol, ecol`  
**Time: O(m * n)**

---

## Classic Array Problems (Code3.cpp)

### LC 1 - Two Sum
Find two indices where `nums[i] + nums[j] == target`.

**Approach:** Use a hashmap.
- For each element, check if `target - nums[i]` already exists in map.
- If yes → found the pair. If no → store current element in map.

**Time: O(n) | Space: O(n)**

### LC 2965 - Find Missing and Repeated Values (2D Grid)
Given an n×n grid with values 1 to n², one number repeats (a) and one is missing (b).

**Approach:**
- Use a hashset to detect the repeated number while traversing.
- Use formula: `expectedSum = (n²)(n²+1)/2`
- `b (missing) = expectedSum + a - actualSum`

**Time: O(n²) | Space: O(n²)**

### LC 287 - Find the Duplicate Number
Array of n+1 integers, each in range [1, n]. Find the duplicate **without modifying the array** and in **O(1) space**.

**Approach: Floyd's Cycle Detection (Linked List trick)**
- Treat array values as pointers: `slow = nums[slow]`, `fast = nums[nums[fast]]`
- When slow == fast, reset slow to start
- Move both one step at a time → they meet at the duplicate

**Time: O(n) | Space: O(1)** — smartest solution here!

---

## 3Sum (Code4.cpp)

### LC 15 - 3Sum
Find all unique triplets in array that sum to 0.

| Approach | Time | Space |
|---|---|---|
| Brute Force (3 nested loops) | O(n³) | O(n) for set |
| Better (fix one, use hashset for other two) | O(n²) | O(n) |
| Optimal (sort + two pointers) | O(n²) | O(1) |

**Key trick:** Sort the array, fix `i`, use two pointers `j` and `k` from both ends.  
Skip duplicates at every level to avoid repeated triplets.

---

## 4Sum (Code5.cpp)

### LC 18 - 4Sum
Same idea as 3Sum but one more loop.

**Approach:** Sort array → fix `i` and `j` → use two pointers `p` and `q` for the remaining two.

> Use `long long` for the sum to avoid integer overflow!

Skip duplicates for `i` and `j` after each step.  
**Time: O(n³) | Space: O(1)**

---

## Subarray Sum Equals K (Code6.cpp)

### LC 560 - Subarray Sum Equals K
Count total subarrays whose elements sum to `k`.

| Approach | Time | Space |
|---|---|---|
| Brute Force (nested loops) | O(n²) | O(1) |
| Optimal (prefix sum + hashmap) | O(n) | O(n) |

**Optimal Idea:**
- Build prefix sum array.
- For each `prefixSum[j]`, check if `prefixSum[j] - k` exists in the hashmap.
- If it does, those many subarrays end at `j` and sum to `k`.

> Remember: Start the prefix sum loop from `i = 1`, not `i = 0`!

---

## Quick Summary Table

| Problem | Key Technique | Time |
|---|---|---|
| Linear Search in Matrix | Nested loops | O(n*m) |
| Search Sorted Matrix I | Binary Search | O(log(m*n)) |
| Search Sorted Matrix II | Staircase (top-right) | O(m+n) |
| Spiral Matrix | Boundary shrinking | O(m*n) |
| Two Sum | HashMap | O(n) |
| Find Duplicate | Floyd's Cycle Detection | O(n) |
| 3Sum | Sort + Two Pointers | O(n²) |
| 4Sum | Sort + Two Pointers | O(n³) |
| Subarray Sum = K | Prefix Sum + HashMap | O(n) |

---

## Things to Remember

- Always use `long long` when summing multiple large integers (especially 4Sum).
- Floyd's cycle detection works because the duplicate creates a cycle in the "linked list" of indices.
- In staircase search, always start from **top-right** (not top-left or bottom-right).
- Prefix sum: `prefixSum[i] = prefixSum[i-1] + arr[i]` → start loop from index **1**.
- To avoid duplicates in 3Sum/4Sum, **sort first**, then skip equal adjacent elements.
