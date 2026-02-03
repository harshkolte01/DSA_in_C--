# Lecture 2: Variables, Data Types & Operators

## Overview
This lecture covers the fundamental building blocks of C++ programming: variables, data types, and operators.

## 📝 Variables
Variables are named storage locations that hold data values.

### Declaration and Initialization
```cpp
int age = 25;           // Declaration with initialization
char grade = 'A';       // Single character
float PI = 3.14f;       // Float precision
double PI2 = 3.14;      // Double precision
bool isSafe = false;    // Boolean value
```

### Variable Rules
- Must start with letter or underscore
- Can contain letters, digits, underscores
- Case-sensitive (`age` ≠ `Age`)
- Cannot use reserved keywords

## 🔢 Data Types

### Primitive Data Types
| Type | Size | Range | Example |
|------|------|-------|---------|
| `int` | 4 bytes | -2³¹ to 2³¹-1 | `int age = 25;` |
| `char` | 1 byte | -128 to 127 | `char grade = 'A';` |
| `float` | 4 bytes | 7 decimal digits | `float pi = 3.14f;` |
| `double` | 8 bytes | 15-17 decimal digits | `double pi = 3.14159;` |
| `bool` | 1 byte | true/false | `bool isValid = true;` |

### Additional Types
- `long` - Extended integer (8 bytes)
- `short` - Short integer (2 bytes)
- `unsigned` - Only positive values

## 🔄 Type Casting

### Implicit Type Casting (Automatic)
```cpp
char grade = 'a';      // ASCII value 97
int value = grade;     // Automatic conversion to 97
cout << value;         // Output: 97
```

### Explicit Type Casting (Manual)
```cpp
double price = 110.93;
int newp = int(price);    // Manual conversion
cout << newp;             // Output: 110 (decimal part lost)
```

### Type Casting Rules
- **Widening**: Smaller → Larger (Safe, automatic)
- **Narrowing**: Larger → Smaller (May lose data, requires explicit cast)

## ⌨️ Input/Output Operations

### Basic Input
```cpp
int age;
cout << "Enter your age: ";
cin >> age;                    // Read input from user
cout << "Age: " << age << endl;
```

### Multiple Inputs
```cpp
int a, b;
cin >> a >> b;    // Read two integers separated by space
```

## 🧮 Operators

### Arithmetic Operators
```cpp
int a = 10, b = 3;
cout << a + b;    // Addition: 13
cout << a - b;    // Subtraction: 7
cout << a * b;    // Multiplication: 30
cout << a / b;    // Division: 3 (integer division)
cout << a % b;    // Modulo: 1 (remainder)
```

### Assignment Operators
```cpp
int x = 5;
x += 3;    // x = x + 3  → x = 8
x -= 2;    // x = x - 2  → x = 6
x *= 2;    // x = x * 2  → x = 12
x /= 4;    // x = x / 4  → x = 3
x %= 2;    // x = x % 2  → x = 1
```

### Comparison Operators
```cpp
int a = 5, b = 3;
a == b    // Equal to: false
a != b    // Not equal: true
a > b     // Greater than: true
a < b     // Less than: false
a >= b    // Greater than or equal: true
a <= b    // Less than or equal: false
```

### Logical Operators
```cpp
bool a = true, b = false;
a && b    // AND: false
a || b    // OR: true
!a        // NOT: false
```

### Increment/Decrement Operators
```cpp
int x = 5;
++x;      // Pre-increment: x becomes 6, returns 6
x++;      // Post-increment: returns 6, then x becomes 7
--x;      // Pre-decrement: x becomes 6, returns 6
x--;      // Post-decrement: returns 6, then x becomes 5
```

## 💡 Key Points

1. **Memory Allocation**: Each data type uses specific memory size
2. **Type Safety**: C++ is strongly typed - variables have fixed types
3. **Overflow**: Exceeding data type range causes unexpected behavior
4. **Precision**: Use `double` for high precision calculations
5. **Boolean Values**: `0` is false, any non-zero value is true

## 📁 Code Examples
- **Code1.cpp**: Basic variable declaration and data types
- **Code2.cpp**: Type casting (implicit and explicit)
- **Code3.cpp**: User input with `cin`

## 🎯 Practice Tips
1. Always initialize variables before use
2. Choose appropriate data types for your data
3. Be careful with type casting to avoid data loss
4. Use meaningful variable names
5. Understand operator precedence for complex expressions

---
*This lecture establishes the foundation for all C++ programming concepts.*