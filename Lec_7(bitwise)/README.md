# Lecture 7: Bitwise Operators & Related Concepts

## Table of Contents
1. [Bitwise Operators](#bitwise-operators)
2. [Operator Precedence](#operator-precedence)
3. [Scope](#scope)
4. [Data Type Modifiers](#data-type-modifiers)

---

## Bitwise Operators

Bitwise operators work on bits and perform bit-by-bit operations. They work only on integral data types (int, char, long, etc.).

### 1. Bitwise AND (`&`)
- Compares each bit of two numbers
- Returns 1 only if both bits are 1
- **Example:** `6 & 10 = 2`
  ```
  6  = 0110
  10 = 1010
  ──────────
  2  = 0010
  ```

### 2. Bitwise OR (`|`)
- Compares each bit of two numbers
- Returns 1 if at least one bit is 1
- **Example:** `6 | 10 = 14`
  ```
  6  = 0110
  10 = 1010
  ──────────
  14 = 1110
  ```

### 3. Bitwise XOR (`^`)
- Compares each bit of two numbers
- Returns 1 if bits are different, 0 if same
- **Example:** `6 ^ 10 = 12`
  ```
  6  = 0110
  10 = 1010
  ──────────
  12 = 1100
  ```

### 4. Bitwise NOT (`~`)
- Inverts all bits (1's complement)
- **Example:** `~5 = -6`
  ```
  5  = 00000101
  ~5 = 11111010 (in 2's complement = -6)
  ```

### 5. Left Shift (`<<`)
- Shifts bits to the left by specified positions
- Fills with 0s from the right
- **Effect:** Multiplies number by 2^n
- **Example:** `8 << 2 = 32`
  ```
  8  = 00001000
  << 2 = 00100000 = 32
  (8 × 2² = 32)
  ```

### 6. Right Shift (`>>`)
- Shifts bits to the right by specified positions
- **Effect:** Divides number by 2^n
- **Example:** `32 >> 2 = 8`
  ```
  32 = 00100000
  >> 2 = 00001000 = 8
  (32 ÷ 2² = 8)
  ```

### Common Applications

#### Check if Number is Power of 2
```cpp
int checkPowerOf2(int n) {
    if (n <= 0) return 0;
    return (n & (n - 1)) == 0 ? 1 : 0;
}
```
**Logic:** A power of 2 has only one bit set. When we subtract 1, all bits after that bit become 1, and the bit itself becomes 0. AND operation returns 0.

**Examples:**
- `8 = 1000`, `7 = 0111`, `8 & 7 = 0000` ✓
- `10 = 1010`, `9 = 1001`, `10 & 9 = 1000` ✗

#### Count Set Bits (Brian Kernighan's Algorithm)
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}
```

#### Swap Two Numbers Without Temp Variable
```cpp
a = a ^ b;
b = a ^ b;  // b = (a ^ b) ^ b = a
a = a ^ b;  // a = (a ^ b) ^ a = b
```

---

## Operator Precedence

Operator precedence determines the order in which operators are evaluated in expressions.

### Precedence Table (High to Low)

| Priority | Operator | Description | Associativity |
|----------|----------|-------------|---------------|
| 1 | `()` `[]` `->` `.` | Parentheses, Array subscript, Member access | Left to Right |
| 2 | `++` `--` `!` `~` `+` `-` `*` `&` | Unary operators | Right to Left |
| 3 | `*` `/` `%` | Multiplication, Division, Modulus | Left to Right |
| 4 | `+` `-` | Addition, Subtraction | Left to Right |
| 5 | `<<` `>>` | Bitwise shift | Left to Right |
| 6 | `<` `<=` `>` `>=` | Relational operators | Left to Right |
| 7 | `==` `!=` | Equality operators | Left to Right |
| 8 | `&` | Bitwise AND | Left to Right |
| 9 | `^` | Bitwise XOR | Left to Right |
| 10 | `|` | Bitwise OR | Left to Right |
| 11 | `&&` | Logical AND | Left to Right |
| 12 | `||` | Logical OR | Left to Right |
| 13 | `?:` | Ternary conditional | Right to Left |
| 14 | `=` `+=` `-=` `*=` `/=` etc. | Assignment operators | Right to Left |
| 15 | `,` | Comma operator | Left to Right |

### Important Notes
- **Use parentheses** to make expressions clear and avoid ambiguity
- **Example:** `cout << (6 & 10) << endl;` - Parentheses required to avoid ambiguity
- Bitwise operators have lower precedence than comparison operators

### Examples
```cpp
int a = 5 + 3 * 2;      // = 11 (not 16), because * has higher precedence
int b = (5 + 3) * 2;    // = 16 (parentheses override precedence)
int c = 10 < 20 && 30 > 15;  // = 1 (true)
```

---

## Scope

Scope defines the region of code where a variable is accessible and its lifetime.

### Types of Scope

#### 1. Local Scope (Block Scope)
- Variables declared inside a function or block `{}`
- Only accessible within that block
- Created when block is entered, destroyed when block exits

```cpp
void function() {
    int x = 10;  // Local to function
    {
        int y = 20;  // Local to this block
        cout << x << y;  // Both accessible here
    }
    // cout << y;  // ERROR: y is out of scope
}
```

#### 2. Global Scope
- Variables declared outside all functions
- Accessible throughout the program
- Exist for the entire program duration

```cpp
int globalVar = 100;  // Global scope

void function1() {
    cout << globalVar;  // Accessible
}

void function2() {
    globalVar = 200;  // Can modify
}
```

#### 3. Function Scope
- Function parameters and variables
- Only accessible within the function

```cpp
int add(int a, int b) {  // a, b have function scope
    int sum = a + b;      // sum has function scope
    return sum;
}
// a, b, sum are NOT accessible here
```

#### 4. Class Scope
- Variables declared inside a class
- Accessible using object or class name

```cpp
class MyClass {
    int privateVar;     // Class scope (private)
public:
    int publicVar;      // Class scope (public)
};
```

### Scope Resolution
```cpp
int x = 10;  // Global

int main() {
    int x = 20;  // Local (shadows global)
    cout << x;       // Prints 20 (local)
    cout << ::x;     // Prints 10 (global, using scope resolution)
}
```

### Important Points
- **Shadowing:** Local variable hides global variable with same name
- **Lifetime:** Variables exist only within their scope
- **Best Practice:** Minimize use of global variables
- Variables should be declared in the narrowest scope possible

---

## Data Type Modifiers

Modifiers alter the meaning of base data types to fit specific situations.

### Types of Modifiers

#### 1. `signed` (Default for most types)
- Can store both positive and negative values
- Uses one bit for sign (MSB)

```cpp
signed int a = -10;
signed char b = -128;  // Range: -128 to 127
```

#### 2. `unsigned`
- Can store only non-negative values (0 and positive)
- All bits used for magnitude (doubles positive range)

```cpp
unsigned int a = 10;
unsigned char b = 255;  // Range: 0 to 255
// unsigned int c = -5;  // ERROR or wraps around
```

#### 3. `short`
- Decreases storage size
- Usually 2 bytes (16 bits)

```cpp
short int a = 32767;     // Range: -32,768 to 32,767
unsigned short b = 65535; // Range: 0 to 65,535
```

#### 4. `long`
- Increases storage size
- Usually 4 or 8 bytes

```cpp
long int a = 2147483647L;
long long b = 9223372036854775807LL;
```

### Size and Range Table

| Data Type | Size (bytes) | Range |
|-----------|--------------|-------|
| `char` | 1 | -128 to 127 |
| `unsigned char` | 1 | 0 to 255 |
| `short int` | 2 | -32,768 to 32,767 |
| `unsigned short int` | 2 | 0 to 65,535 |
| `int` | 4 | -2,147,483,648 to 2,147,483,647 |
| `unsigned int` | 4 | 0 to 4,294,967,295 |
| `long int` | 4/8 | System dependent |
| `long long int` | 8 | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `unsigned long long` | 8 | 0 to 18,446,744,073,709,551,615 |

### Combinations
```cpp
unsigned long long int a;
signed short int b;
long double c;  // For floating point
```

### Important Points
- **Default:** `int` is `signed int`
- **Overflow:** Exceeding range causes wrap-around (undefined for signed, defined for unsigned)
- **Size varies:** Use `sizeof()` operator to check actual size on your system
- **Choice depends on:** Range needed and memory constraints

### Using `sizeof()` Operator
```cpp
cout << sizeof(int);          // Typically 4
cout << sizeof(long long);    // Typically 8
cout << sizeof(char);         // Always 1
cout << sizeof(unsigned int); // Typically 4
```

---

## Practice Problems

1. **Find the only non-repeating element** in an array where every element repeats twice except one (Use XOR)
2. **Check if ith bit is set** in a number
3. **Set the ith bit** of a number
4. **Clear the ith bit** of a number
5. **Toggle the ith bit** of a number
6. **Count number of 1s** in binary representation
7. **Find two non-repeating elements** in array where all others repeat twice
8. **Swap alternate bits** of a number

---

## Key Takeaways

✅ Bitwise operators work at bit level and are very fast  
✅ Power of 2 check: `n & (n-1) == 0`  
✅ Left shift multiplies by 2, right shift divides by 2  
✅ Use parentheses to avoid operator precedence issues  
✅ Minimize global scope, use local scope when possible  
✅ Use `unsigned` when you don't need negative numbers  
✅ Choose appropriate data type based on range requirements  
✅ XOR is useful for finding unique elements and swapping  

---

**Happy Coding! 🚀**
