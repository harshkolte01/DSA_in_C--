# Lecture 15: Sorting Algorithms

## 📚 Basic Sorting Algorithms

### 1. Bubble Sort
**File:** `BubbleSort.cpp`

**Logic:** 
- Compare adjacent elements and swap if they're in wrong order
- After each pass, the largest element "bubbles up" to its correct position
- Repeat n-1 times

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

### 2. Selection Sort
**File:** `SelectionSort.cpp`

**Logic:**
- Find the smallest element in the unsorted part
- Swap it with the first element of unsorted part
- Move boundary of sorted part one step ahead
- Repeat until entire array is sorted

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

### 3. Insertion Sort
**File:** `InsertionSort.cpp`

**Logic:**
- Pick an element and compare with elements before it
- Shift all larger elements one position ahead
- Insert the element at correct position
- Works like sorting playing cards in your hand

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

## 🎯 LeetCode Problems

### 1. Sort Colors (Dutch National Flag)
**File:** `Code1.cpp` | **LeetCode:** #75

**Problem:** Sort array with only 0s, 1s, and 2s

**Logic (DNF Algorithm):**
- Use 3 pointers: low, mid, high
- **0 found:** swap with low, move both low and mid forward
- **1 found:** just move mid forward
- **2 found:** swap with high, move high backward
- Continue until mid crosses high

**Time Complexity:** O(n) - Single pass!  
**Space Complexity:** O(1)

---

### 2. Merge Sorted Array
**File:** `Code2.cpp` | **LeetCode:** #88

**Problem:** Merge two sorted arrays into first array

**Logic:**
- Start from the end of both arrays
- Compare elements from back and place larger one at end of nums1
- Work backwards to avoid overwriting elements
- Fill remaining elements from nums2 if any

**Time Complexity:** O(m+n)  
**Space Complexity:** O(1)

---

### 3. Next Permutation
**File:** `Code3.cpp` | **LeetCode:** #31

**Problem:** Find next lexicographically greater permutation

**Logic:**
1. Find **pivot** from right where a[i] < a[i+1] (breaking point)
2. If no pivot found → reverse entire array (it's already largest)
3. From right, find first element > pivot and swap them
4. Reverse everything after pivot position

**Example:** `[1,3,2]` → `[2,1,3]`

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

## 💡 Quick Tips

- **Bubble, Selection, Insertion:** All O(n²) but good for small arrays
- **Insertion Sort:** Best for nearly sorted arrays
- **Selection Sort:** Minimum number of swaps
- **Bubble Sort:** Can be optimized by stopping if no swaps occur
- **DNF Algorithm:** Master technique for 3-way partitioning problems
- **Working backwards:** Common trick for in-place merging

---

## 🔥 Remember
- Always check if array modification is in-place or new array needed
- For optimization, think if you can reduce passes or work from back
- DNF pattern useful for segregation problems (0s, 1s, 2s)
