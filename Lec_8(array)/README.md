# Lecture 8: Arrays

## Table of Contents
1. [Array Basics](#array-basics)
2. [Array Initialization](#array-initialization)
3. [Finding Smallest and Largest](#finding-smallest-and-largest)
4. [Linear Search](#linear-search)
5. [Reverse Array](#reverse-array)
6. [Sum and Product](#sum-and-product)
7. [Unique Values](#unique-values)
8. [Array Intersection](#array-intersection)
9. [Key Concepts](#key-concepts)

---

## Array Basics

**Definition**: An array is a collection of elements of the same data type stored in contiguous memory locations.

**Syntax**:
```cpp
datatype arrayName[size];
```

**Size Calculation**:
```cpp
int arr_size = sizeof(arr) / sizeof(arr[0]);
```

---

## Array Initialization

### Three Ways to Initialize Arrays:

```cpp
// 1. Declaration without initialization
int arr[5];

// 2. Declaration with initialization
int marks[5] = {1, 2, 3, 4, 5};

// 3. Size inferred from initializer list
int price[] = {1, 2, 3, 4};  // Size is automatically 4
```

### Input/Output Example:
```cpp
for (int i = 0; i < arr_size; i++) {
    cin >> arr[i];      // Input
    cout << arr[i];     // Output
}
```

---

## Finding Smallest and Largest

### Method 1: Using INT_MAX and INT_MIN
```cpp
int smallest = INT_MAX;
int largest = INT_MIN;

for (int i = 0; i < size; i++) {
    smallest = min(arr[i], smallest);
    largest = max(arr[i], largest);
}
```

### Method 2: With Index Tracking
```cpp
int smallest = arr[0];
int smallest_idx = 0;
int largest = arr[0];
int largest_idx = 0;

for (int i = 0; i < size; i++) {
    if (arr[i] < smallest) {
        smallest = arr[i];
        smallest_idx = i;
    }
    if (arr[i] > largest) {
        largest = arr[i];
        largest_idx = i;
    }
}
```

**Use Case**: Tracking indices allows you to swap or manipulate elements at those positions.

---

## Linear Search

**Algorithm**: Search for a target value by checking each element sequentially.

```cpp
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}
```

**Time Complexity**: O(n)  
**Space Complexity**: O(1)

---

## Reverse Array

**Two-Pointer Approach**:

```cpp
int start = 0;
int end = size - 1;

while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
}
```

**Algorithm**:
1. Initialize two pointers: one at the start, one at the end
2. Swap elements at both pointers
3. Move start forward and end backward
4. Repeat until pointers meet

**Time Complexity**: O(n/2) ≈ O(n)  
**Space Complexity**: O(1)

---

## Sum and Product

```cpp
void sum_prod_array(int arr[], int sz) {
    int sum = 0;
    int prod = 1;
    
    for (int i = 0; i < sz; i++) {
        sum += arr[i];
        prod *= arr[i];
    }
    
    cout << "SUM: " << sum << "  PROD: " << prod << endl;
}
```

**Note**: Initialize `sum = 0` (additive identity) and `prod = 1` (multiplicative identity).

---

## Unique Values

**Problem**: Find elements that appear exactly once in the array.

```cpp
void unique_value(int arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        int value = arr[i];
        int count = 0;
        
        // Count occurrences
        for (int j = 0; j < sz; j++) {
            if (value == arr[j]) {
                count++;
            }
        }
        
        if (count == 1) {
            cout << "Unique Value: " << value << endl;
        }
    }
}
```

**Time Complexity**: O(n²)  
**Space Complexity**: O(1)

**Better Approach**: Use hash map for O(n) time complexity.

---

## Array Intersection

**Problem**: Find common elements between two arrays.

```cpp
void intersection_array() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {3, 4, 5, 6, 7};
    
    for (int i = 0; i < 5; i++) {
        int value = arr1[i];
        for (int j = 0; j < 5; j++) {
            if (value == arr2[j]) {
                cout << value << " ";
            }
        }
    }
}
```

**Time Complexity**: O(n × m) where n and m are array sizes  
**Space Complexity**: O(1)

**Note**: This approach may print duplicates. Use a set or additional logic to avoid duplicates.

---

## Key Concepts

### 1. **Pass by Reference**
When passing arrays to functions, they are automatically passed by reference:
```cpp
void modifyArray(int arr[], int size) {
    arr[0] = 100;  // Modifies original array
}
```

### 2. **Array Indexing**
- Arrays are 0-indexed: first element at `arr[0]`, last at `arr[size-1]`
- Accessing out-of-bounds indices causes undefined behavior

### 3. **Common Functions**
- `swap(a, b)` - Swaps two values
- `min(a, b)` - Returns minimum
- `max(a, b)` - Returns maximum

### 4. **Important Constants**
- `INT_MAX` - Maximum integer value (2,147,483,647)
- `INT_MIN` - Minimum integer value (-2,147,483,648)

### 5. **Memory Layout**
Arrays are stored in contiguous memory locations, which makes accessing elements by index very fast: O(1).

---

## Practice Problems

1. ✅ Find the second largest element in an array
2. ✅ Remove duplicates from a sorted array
3. ✅ Rotate an array by k positions
4. ✅ Find the missing number in an array of 1 to n
5. ✅ Merge two sorted arrays

---

## Time Complexity Summary

| Operation | Time Complexity |
|-----------|----------------|
| Access by index | O(1) |
| Linear search | O(n) |
| Insert/Delete at end | O(1) |
| Insert/Delete at beginning | O(n) |
| Find min/max | O(n) |
| Reverse array | O(n) |

---

## Tips for Revision

1. **Always check array bounds** to avoid segmentation faults
2. **Initialize variables properly** (sum=0, product=1, etc.)
3. **Use two-pointer technique** for problems involving array reversal or pairing
4. **Consider edge cases**: empty array, single element, all same elements
5. **Arrays are passed by reference** - modifications affect the original array

---

## Related Topics to Explore Next

- Sorting algorithms (Bubble Sort, Selection Sort, Insertion Sort)
- Binary Search (requires sorted array)
- Two-pointer and sliding window techniques
- Dynamic arrays (vectors in C++)
- Multi-dimensional arrays

---

*Last Updated: February 7, 2026*
