# Lecture 11: Time Complexity ⏱️

## Quick Revision Notes

### What is Time Complexity?
Time complexity measures how the runtime of an algorithm grows as the input size increases. It helps us analyze algorithm efficiency.

---

## Common Time Complexities (Best to Worst)

| Complexity | Name | Example |
|------------|------|---------|
| **O(1)** | Constant | Accessing array element, arithmetic operations |
| **O(log n)** | Logarithmic | Binary search, balanced BST operations |
| **O(n)** | Linear | Single loop, linear search |
| **O(n log n)** | Linearithmic | Merge sort, quick sort (average case) |
| **O(n²)** | Quadratic | Nested loops, bubble sort |
| **O(n³)** | Cubic | Triple nested loops |
| **O(2ⁿ)** | Exponential | Recursive fibonacci (naive) |
| **O(n!)** | Factorial | Generating all permutations |

---

## Key Points to Remember

### 1. **Drop Constants**
   - O(2n) → O(n)
   - O(3n + 100) → O(n)

### 2. **Drop Lower Order Terms**
   - O(n² + n) → O(n²)
   - O(n³ + n² + n) → O(n³)

### 3. **Time Complexity of Loops**
```cpp
// O(n) - Linear
for (int i = 0; i < n; i++) {
    // O(1) operations
}

// O(n²) - Quadratic
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) operations
    }
}

// O(log n) - Logarithmic
for (int i = 1; i < n; i *= 2) {
    // O(1) operations
}
```

### 4. **Best, Average, Worst Case**
   - **Best Case**: Minimum time taken (Omega Ω notation)
   - **Average Case**: Expected time (Theta Θ notation)
   - **Worst Case**: Maximum time taken (Big-O notation) ← Most commonly used

---

## Space Complexity

Space complexity measures the amount of memory used by an algorithm.

- **Auxiliary Space**: Extra space used (excluding input)
- **Total Space**: Input space + Auxiliary space

### Examples:
```cpp
// O(1) space
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
}

// O(n) space
vector<int> temp(n);  // Creates array of size n
```

---

## Quick Tips for Interviews 💡

1. Always analyze worst-case scenario
2. Consider both time and space complexity
3. Look for optimization opportunities (nested loops → two pointers)
4. Recursion: Time = Number of calls × Work per call
5. Space for recursion = Depth of recursion tree

---

## Practice Strategy

✅ First solve the problem (any solution)  
✅ Analyze the time complexity  
✅ Think: Can I do better?  
✅ Optimize and implement

---

## Common Algorithm Complexities

| Algorithm | Time Complexity |
|-----------|-----------------|
| Linear Search | O(n) |
| Binary Search | O(log n) |
| Bubble Sort | O(n²) |
| Merge Sort | O(n log n) |
| Quick Sort | O(n log n) average, O(n²) worst |
| Kadane's Algorithm | O(n) |
| Two Pointer | O(n) |

---

**Remember**: In competitive programming and interviews, aim for the most optimal solution! 🎯
