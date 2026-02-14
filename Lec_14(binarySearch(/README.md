# Lecture 14: Binary Search 🔍

## Quick Recap

Binary Search is a **fast searching algorithm** that works on **sorted arrays**. Instead of checking every element, it divides the search space in half each time.

---

## ⚡ Time Complexity: O(log n)

---

## Topics Covered:

### 1️⃣ **Basic Binary Search** (Code1.cpp)
- **Iterative approach**: Using while loop
- **Recursive approach**: Function calls itself
- **Key formula**: `mid = start + (end - start) / 2` (avoids overflow)
- Returns index if found, else -1

---

### 2️⃣ **Search in Rotated Sorted Array** (Code2.cpp)
- Sorted array is rotated at some point
- Example: `[4,5,6,7,0,1,2]`
- Check which half is sorted, then search accordingly

---

### 3️⃣ **Peak Index in Mountain Array** (Code3.cpp)
- Array increases then decreases (mountain shape ⛰️)
- Find the peak (highest point)
- Compare mid with neighbors to decide direction

---

### 4️⃣ **Single Element in Sorted Array** (Code4.cpp)
- All elements appear twice except one
- Use binary search on indices
- Check pairs to find the unique element

---

### 5️⃣ **Book Allocation Problem** (Code5.cpp)
- Allocate N books to M students
- Minimize the maximum pages a student reads
- Books must be allocated in contiguous order
- Binary search on answer range (min pages to total pages)

---

### 6️⃣ **Painter's Partition Problem** (Code6.cpp)
- N boards, M painters
- Each painter paints continuous boards
- Minimize the maximum time taken by any painter
- Similar logic to book allocation

---

### 7️⃣ **Aggressive Cows Problem** (Code7.cpp)
- Place C cows in N stalls
- Maximize the minimum distance between any two cows
- Sort stalls first, then binary search on distance

---

## 💡 Key Pattern:
**Binary Search on Answer** - Problems 5, 6, 7 use this pattern:
- Define a range [min, max]
- Binary search on this range
- Check if mid is valid using a helper function
- Adjust range based on feasibility

---

## 🎯 Remember:
- Binary search only works on **sorted** or **monotonic** data
- Always check for **overflow** in mid calculation
- For rotated/modified arrays, identify the pattern first
- "Binary search on answer" is powerful for optimization problems

---

Happy Coding! 💻
