# Lecture 9: Vectors - Quick Revision

## 🎯 What is a Vector?

**Vector** = Dynamic array that can grow/shrink in size automatically

| Feature | Array (Static) | Vector (Dynamic) |
|---------|---------------|------------------|
| Size | Fixed at compile time | Can change at runtime |
| Memory | Stack | Heap |
| Flexibility | Limited | High |

---

## 📦 Include & Declaration

```cpp
#include <vector>

// Declaration
vector<int> vec;              // Empty vector
vector<int> vec = {1, 2, 3};  // Initialize with values
vector<int> vec(5);           // Vector of size 5 (all zeros)
vector<int> vec(5, 10);       // Vector of size 5 (all 10s)
```

---

## ⚡ Key Functions

| Function | Description | Example | Time |
|----------|-------------|---------|------|
| `size()` | Returns number of elements | `vec.size()` | O(1) |
| `push_back()` | Add element at end | `vec.push_back(10)` | O(1) |
| `pop_back()` | Remove last element | `vec.pop_back()` | O(1) |
| `front()` | Access first element | `vec.front()` | O(1) |
| `back()` | Access last element | `vec.back()` | O(1) |
| `at(i)` | Access element at index i (with bounds check) | `vec.at(2)` | O(1) |
| `clear()` | Remove all elements | `vec.clear()` | O(n) |
| `empty()` | Check if vector is empty | `vec.empty()` | O(1) |

---

## 🔄 Accessing Elements

```cpp
vector<int> vec = {10, 20, 30};

// Method 1: Using []
cout << vec[0];  // 10 (no bounds checking)

// Method 2: Using at()
cout << vec.at(0);  // 10 (with bounds checking, safer)

// Method 3: Using front/back
cout << vec.front();  // 10
cout << vec.back();   // 30
```

**⚠️ Important:** `vec[i]` is faster but unsafe, `vec.at(i)` is safer but slightly slower.

---

## 🔁 Looping Through Vectors

### 1. Traditional For Loop
```cpp
for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}
```

### 2. For-Each Loop (Range-based)
```cpp
for (int val : vec) {
    cout << val << " ";
}
```

### 3. For-Each with Reference (to modify)
```cpp
for (int &val : vec) {
    val *= 2;  // Modifies original vector
}
```

---

## 🔍 Linear Search in Vector

```cpp
int linearSearch(const vector<int>& vec, int key) {
    int index = 0;
    for (int val : vec) {
        if (val == key) {
            return index;  // Found: return index
        }
        index++;
    }
    return -1;  // Not found
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

## 🔄 Reverse a Vector

### Method 1: Create New Reversed Vector
```cpp
vector<int> revNumber(const vector<int>& vec) {
    vector<int> reversed;
    for (int i = vec.size() - 1; i >= 0; i--) {
        reversed.push_back(vec[i]);
    }
    return reversed;
}
```

### Method 2: In-place Reversal (Two Pointer)
```cpp
void reverseInPlace(vector<int>& vec) {
    int start = 0;
    int end = vec.size() - 1;
    while (start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1) for in-place, O(n) for new vector

---

## 🔑 Key Points to Remember

✅ Vectors are **passed by reference** to functions to avoid copying  
✅ Use `const` when you don't want to modify the vector  
✅ `vec.size()` returns `size_t` (unsigned), be careful in loops  
✅ Vector indices are **0-based** like arrays  
✅ Use `for-each` loop when you don't need indices  
✅ Use `.at()` during development (safer), `[]` for production (faster)  

---

## ⚠️ Common Mistakes

```cpp
// ❌ Wrong: size() returns unsigned, can cause issues
for (int i = vec.size() - 1; i >= 0; i--) { }

// ✅ Correct: Use int cast or check differently
for (int i = (int)vec.size() - 1; i >= 0; i--) { }
```

```cpp
// ❌ Wrong: Accessing out of bounds
vector<int> vec(5);
cout << vec[10];  // Undefined behavior

// ✅ Correct: Check bounds or use .at()
if (i < vec.size()) { cout << vec[i]; }
```

```cpp
// ❌ Wrong: Modifying size while iterating
for (int val : vec) {
    vec.push_back(val);  // Dangerous!
}

// ✅ Correct: Use traditional loop with fixed size
int n = vec.size();
for (int i = 0; i < n; i++) { }
```

---

## 🆚 Vector vs Array

```cpp
// Array: Fixed size
int arr[5] = {1, 2, 3, 4, 5};
// Can't do: arr[5] = 6; (out of bounds)

// Vector: Dynamic size
vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);  // Works! Size becomes 6
```

**Use Array when:** Size is known and fixed, need maximum performance  
**Use Vector when:** Size is dynamic, need flexibility, don't know size in advance

---

## 💡 Quick Syntax Reference

```cpp
vector<int> vec = {1, 2, 3, 4, 5};

vec.size();           // 5
vec.push_back(6);     // {1, 2, 3, 4, 5, 6}
vec.pop_back();       // {1, 2, 3, 4, 5}
vec.front();          // 1
vec.back();           // 5
vec.at(2);            // 3
vec[2];               // 3
vec.empty();          // false
vec.clear();          // {}
```

---

## � Input/Output in Vectors

### Taking User Input
```cpp
int n;
cout << "Enter number of elements: ";
cin >> n;

vector<int> vec;
vec.reserve(n);  // Optional: Pre-allocate memory for efficiency

for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
}
```

### Displaying Output
```cpp
// Method 1: Using index
for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}

// Method 2: Using for-each loop
for (int val : vec) {
    cout << val << " ";
}
```

---

## 🧮 Common Vector Operations

### 1. Sum of All Elements
```cpp
int sumOfElements(const vector<int>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 2. Find Maximum and Minimum
```cpp
void min_and_max(const vector<int>& vec) {
    int max = vec[0];
    int min = vec[0];
    
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    
    cout << "Maximum: " << max << " Minimum: " << min << endl;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 3. Count Even Numbers
```cpp
int countEven(const vector<int>& vec) {
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 4. Remove All Occurrences of a Value
```cpp
void removeOcc(vector<int>& vec, int x) {
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it == x) {
            it = vec.erase(it);  // erase returns next iterator
        } else {
            ++it;
        }
    }
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Note:** Use iterators for removing elements while traversing to avoid skipping elements.

---

## 📝 Practice Problems

1. ✅ Find sum of all elements in a vector
2. ✅ Find maximum and minimum in a vector
3. ✅ Count even/odd numbers in a vector
4. ✅ Remove all occurrences of a specific value
5. ✅ Reverse a vector
6. ✅ Linear search in vector
7. ⬜ Remove duplicates from a vector
8. ⬜ Rotate vector left/right by k positions
9. ⬜ Merge two sorted vectors

---

## 🎓 Next Topics

- 2D Vectors (Vector of Vectors)
- Vector of pairs
- STL Algorithms with vectors (sort, reverse, find)
- Vector capacity vs size
- Binary search in vectors

---

*Last Updated: February 9, 2026*
