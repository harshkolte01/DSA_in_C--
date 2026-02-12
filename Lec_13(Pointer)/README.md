# Lecture 13: Pointers - Quick Revision

## 🎯 What is a Pointer?

**Pointer** = Variable that stores the **memory address** of another variable

```cpp
int a = 10;
int* ptr = &a;  // ptr stores the address of 'a'
```

| Symbol | Name | Description | Example |
|--------|------|-------------|---------|
| `*` | Dereference | Access value at address | `*ptr` gives 10 |
| `&` | Address-of | Get address of variable | `&a` gives address |
| `*` | Declaration | Declare pointer variable | `int* ptr;` |

---

## 📦 Declaration & Initialization

```cpp
// Declaration (different styles, all same)
int* ptr;    // Preferred style
int *ptr;    // Also valid
int * ptr;   // Also valid

// Initialization
int a = 10;
int* ptr = &a;      // ptr points to a
int* ptr2 = NULL;   // NULL pointer (safe practice)
int* ptr3 = nullptr; // Modern C++ (C++11+)

// Uninitialized pointer (DANGEROUS!)
int* ptr4;  // Contains garbage address - Never use!
```

**⚠️ Always initialize pointers!** Uninitialized pointers are a common source of bugs.

---

## 🔍 Basic Pointer Operations

### 1. Address-of Operator (&)
```cpp
int a = 10;
cout << &a;  // Prints address of 'a' (e.g., 0x7ffd5e...)
```

### 2. Dereference Operator (*)
```cpp
int a = 10;
int* ptr = &a;

cout << ptr;   // Prints address stored in ptr
cout << *ptr;  // Prints value at that address (10)

*ptr = 20;     // Modify value through pointer
cout << a;     // a is now 20
```

### 3. Pointer Example
```cpp
int a = 5;
int* ptr = &a;

cout << "Value of a: " << a << endl;           // 5
cout << "Address of a: " << &a << endl;        // 0x7ffd...
cout << "Value in ptr: " << ptr << endl;       // 0x7ffd... (same)
cout << "Value at ptr: " << *ptr << endl;      // 5
cout << "Address of ptr: " << &ptr << endl;    // Different address
```

---

## 🔗 Pointer to Pointer (Double Pointer)

A pointer that stores the address of another pointer.

```cpp
int a = 10;
int* ptr = &a;        // Single pointer
int** parptr = &ptr;  // Pointer to pointer

cout << a;           // 10 (value)
cout << &a;          // Address of a
cout << ptr;         // Address of a (same as &a)
cout << *ptr;        // 10 (dereference once)
cout << &ptr;        // Address of ptr itself
cout << parptr;      // Address of ptr (same as &ptr)
cout << *parptr;     // Address stored in ptr (same as ptr)
cout << **parptr;    // 10 (dereference twice)
```

### Visual Representation
```
        a = 10
        Address: 0x100
        
ptr → [0x100]
      Address: 0x200
      
parptr → [0x200]
         Address: 0x300
```

### Code Example
```cpp
int a = 5;
int* p = &a;
int** q = &p;

cout << *p;    // 5 (value of a)
cout << **q;   // 5 (value of a, through double dereference)
cout << p;     // Address of a
cout << *q;    // Address of a (same as p)
```

---

## 📊 Arrays and Pointers

**Important:** Array name is a pointer to the first element!

```cpp
int arr[] = {10, 20, 30, 40};
int* ptr = arr;  // arr is same as &arr[0]

// These are equivalent:
cout << arr[0];    // 10
cout << *arr;      // 10
cout << *ptr;      // 10

// Array indexing vs pointer arithmetic:
cout << arr[2];      // 30
cout << *(arr + 2);  // 30 (same thing!)
```

### Array Pointer Relationship
```cpp
int arr[] = {10, 20, 30, 40};

arr       = &arr[0]  // Address of first element
arr + 1   = &arr[1]  // Address of second element
arr + i   = &arr[i]  // Address of ith element

*arr      = arr[0]   // Value: 10
*(arr+1)  = arr[1]   // Value: 20
*(arr+i)  = arr[i]   // Value at index i
```

---

## ➕ Pointer Arithmetic

### Allowed Operations

```cpp
int arr[] = {10, 20, 30, 40};
int* ptr = arr;

// 1. Increment/Decrement
ptr++;              // Move to next element
ptr--;              // Move to previous element
cout << *ptr;       // 20 (after increment)

// 2. Addition/Subtraction with integer
ptr = ptr + 2;      // Move 2 elements forward
ptr = ptr - 1;      // Move 1 element backward
cout << *(ptr + 3); // Access element 3 positions ahead

// 3. Pointer subtraction (same type only)
int* p1 = &arr[0];
int* p2 = &arr[3];
cout << p2 - p1;    // 3 (number of elements between)

// 4. Comparison
if (p1 < p2) { }    // Valid for same array
```

### Important Points
- `ptr++` moves by **sizeof(data_type)** bytes, not 1 byte
- `int* ptr++` moves 4 bytes (on 32-bit) or 8 bytes (on 64-bit)
- `char* ptr++` moves 1 byte

```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << ptr;       // Address: 0x100
ptr++;
cout << ptr;       // Address: 0x104 (moved by 4 bytes)
```

### ⚠️ NOT Allowed
```cpp
int* ptr1 = &arr[0];
int* ptr2 = &arr[1];

// ❌ Can't add two pointers
ptr1 + ptr2;  // ERROR

// ❌ Can't multiply/divide
ptr1 * 2;     // ERROR
ptr1 / 2;     // ERROR

// ❌ Can't subtract pointers of different types
int* p1;
float* p2;
p1 - p2;      // ERROR
```

---

## 🔑 NULL Pointer

```cpp
int* ptr = NULL;      // C-style
int* ptr = nullptr;   // Modern C++ (preferred)

// Always check before dereferencing
if (ptr != NULL) {
    cout << *ptr;
}

// Dereferencing NULL causes crash!
int* ptr = NULL;
cout << *ptr;  // ❌ SEGMENTATION FAULT
```

---

## 📝 Code Examples from Lecture

### Code 1: Basic Pointers & Double Pointers
```cpp
int a = 10;
int* ptr = &a;
int** parptr = &ptr;

cout << &ptr << endl;      // Address of ptr
cout << &parptr << endl;   // Address of parptr
cout << **(parptr) << endl; // Value of a (10)
```

### Code 2: Double Pointer Practice
```cpp
int a = 5;
int* p = &a;
int** q = &p;

cout << *p << endl;   // 5
cout << **q << endl;  // 5
cout << p << endl;    // Address of a
cout << *q << endl;   // Address of a
```

### Code 3: Array Pointers & Arithmetic
```cpp
int arr[] = {10, 20, 30, 40};
int* ptr = arr;

cout << *(ptr + 1) << endl;  // 20
cout << *(ptr + 3) << endl;  // 40

ptr++;                        // Move to next element
cout << *ptr << endl;         // 20
```

---

## 🎓 Pass by Reference vs Pass by Value

### Pass by Value (Copy)
```cpp
void change(int x) {
    x = 100;  // Only local copy changes
}

int main() {
    int a = 10;
    change(a);
    cout << a;  // Still 10
}
```

### Pass by Reference (Using Pointers)
```cpp
void change(int* ptr) {
    *ptr = 100;  // Original value changes
}

int main() {
    int a = 10;
    change(&a);   // Pass address
    cout << a;    // Now 100
}
```

### Pass by Reference (Using &)
```cpp
void change(int& ref) {
    ref = 100;  // Original value changes
}

int main() {
    int a = 10;
    change(a);   // No & needed in call
    cout << a;   // Now 100
}
```

---

## 🔑 Key Points to Remember

✅ **Pointer stores address**, not value  
✅ **&** = address-of operator  
✅ **\*** = dereference operator (also used in declaration)  
✅ **Array name is a pointer** to first element  
✅ **Pointer arithmetic** moves by sizeof(datatype)  
✅ **Double pointer** = pointer to pointer  
✅ **Always initialize** pointers (use NULL/nullptr)  
✅ **Check NULL** before dereferencing  
✅ **Same type pointers** can be subtracted  
✅ **Can't add two pointers** together  

---

## ⚠️ Common Mistakes

### 1. Uninitialized Pointer
```cpp
// ❌ Wrong
int* ptr;
*ptr = 10;  // CRASH! ptr has garbage address

// ✅ Correct
int* ptr = NULL;  // Safe initialization
int a = 10;
ptr = &a;
*ptr = 20;  // Now safe
```

### 2. Dereferencing NULL
```cpp
// ❌ Wrong
int* ptr = NULL;
cout << *ptr;  // CRASH!

// ✅ Correct
int* ptr = NULL;
if (ptr != NULL) {
    cout << *ptr;
}
```

### 3. Dangling Pointer
```cpp
// ❌ Wrong
int* getPointer() {
    int a = 10;
    return &a;  // DANGER! 'a' destroyed after function ends
}

// ✅ Correct - use dynamic memory or pass reference
int* getPointer() {
    int* ptr = new int(10);  // Heap memory
    return ptr;
}
// Don't forget to delete later!
```

### 4. Confusing * in declaration vs dereference
```cpp
int* ptr;      // * means "pointer declaration"
*ptr = 10;     // * means "dereference"
int *ptr;      // Same as int* ptr
```

### 5. Array bounds with pointers
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr;

// ❌ Wrong
cout << *(ptr + 10);  // Out of bounds!

// ✅ Correct - check bounds
if (index < 5) {
    cout << *(ptr + index);
}
```

---

## 💡 Quick Syntax Reference

```cpp
// Declaration
int* ptr;              // Pointer to int
int** parptr;          // Pointer to pointer to int
int* arr[10];          // Array of 10 pointers

// Initialization
int* ptr = &var;       // Point to variable
int* ptr = NULL;       // NULL pointer
int* ptr = nullptr;    // Modern NULL (C++11+)
int* ptr = arr;        // Point to array

// Dereference
*ptr                   // Get value at address
**parptr               // Double dereference

// Address
&var                   // Get address of var
&ptr                   // Get address of pointer itself

// Arithmetic
ptr++                  // Next element
ptr--                  // Previous element
ptr + n                // Move n elements forward
ptr - n                // Move n elements backward
ptr2 - ptr1            // Elements between pointers

// Array-Pointer equivalence
arr[i]   ≡   *(arr + i)
&arr[i]  ≡   arr + i
```

---

## 📊 Memory Allocation

```cpp
// Stack (automatic)
int a = 10;
int* ptr = &a;  // ptr is on stack, points to 'a' on stack

// Heap (dynamic) - for later lectures
int* ptr = new int(10);      // Allocate on heap
delete ptr;                   // Free memory
```

---

## 🎯 Quick Recap

| Concept | Syntax | Output |
|---------|--------|--------|
| Get address | `&a` | Address of a |
| Dereference | `*ptr` | Value at ptr |
| Declare pointer | `int* ptr` | - |
| Assign address | `ptr = &a` | ptr points to a |
| Double pointer | `int** p` | - |
| Array to pointer | `int* ptr = arr` | ptr points to arr[0] |
| Pointer arithmetic | `ptr + 1` | Next element |
| NULL pointer | `int* ptr = NULL` | Safe initialization |

---

## 🚀 Practice Problems

1. Write a function that swaps two numbers using pointers
2. Find the largest element in an array using pointers (no [])
3. Reverse an array using two pointers
4. Count occurrences of an element using pointers
5. Copy one array to another using pointers

---

## 📚 Coming Up Next

- Dynamic Memory Allocation (`new` and `delete`)
- Pointers with Functions (detailed)
- Pointers with Structures
- Memory Management
- Smart Pointers (Modern C++)

---

## 🔗 Related Topics

- [Lecture 8: Arrays](../Lec_8(array)/README.md)
- [Lecture 9: Vectors](../Lec_9(Vector)/README.md)
- [Lecture 5: Functions](../Lec_5(function)/README.md)

---

**Happy Coding! 🚀**

Remember: *"A pointer is like a street address - it tells you where to find something, not what it is."*
