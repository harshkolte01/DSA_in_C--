# Lecture 3: Conditional Statements & Loops

## Overview
Control flow mechanisms that allow decision-making and repetitive execution in C++ programs.

---

## 🔀 Conditional Statements

### if-else Statement
```cpp
if (condition) {
    // execute if true
} else {
    // execute if false
}
```

**Example**: Check lowercase/uppercase
```cpp
if (ch >= 'a' && ch <= 'z') {
    cout << "lowercase";
} else {
    cout << "uppercase";
}
```

### if-else if-else Ladder
```cpp
if (condition1) {
    // block 1
} else if (condition2) {
    // block 2
} else {
    // default block
}
```

### Ternary Operator
```cpp
variable = (condition) ? value_if_true : value_if_false;
```

**Example**:
```cpp
int max = (a > b) ? a : b;
```

### Switch Statement
```cpp
switch (variable) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // code
}
```

---

## 🔁 Loops

### For Loop
Best when you know the number of iterations.

```cpp
for (initialization; condition; update) {
    // code to repeat
}
```

**Example**: Sum of 1 to n
```cpp
int sum = 0;
for (int i = 1; i <= n; i++) {
    sum = sum + i;
}
```

### While Loop
Best when iterations depend on a condition.

```cpp
while (condition) {
    // code to repeat
    // update condition
}
```

**Example**: Sum using while
```cpp
int i = 1, sum = 0;
while (i <= n) {
    sum = sum + i;
    i++;
}
```

### Do-While Loop
Executes at least once, then checks condition.

```cpp
do {
    // code to repeat
} while (condition);
```

**Example**:
```cpp
int i = 1;
do {
    cout << i << " ";
    i++;
} while (i <= 5);
```

---

## 🎯 Loop Control Statements

### break
Exits the loop immediately.

```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;  // stops at 5
    cout << i;
}
// Output: 1234
```

### continue
Skips current iteration, moves to next.

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;  // skips 3
    cout << i;
}
// Output: 1245
```

---

## 🔢 Nested Loops
Loop inside another loop.

```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        cout << i << "," << j << " ";
    }
    cout << endl;
}
/* Output:
1,1 1,2 1,3
2,1 2,2 2,3
3,1 3,2 3,3
*/
```

---

## 💡 Common Patterns

### Sum of Numbers (1 to n)
```cpp
int sum = 0;
for (int i = 1; i <= n; i++) {
    sum += i;
}
// Formula: sum = n * (n + 1) / 2
```

### Sum of Odd Numbers
```cpp
int sum = 0;
for (int i = 1; i <= n; i++) {
    if (i % 2 != 0) {
        sum += i;
    }
}
```

### Sum of Multiples of 3
```cpp
int sum = 0;
for (int i = 0; i <= n; i++) {
    if (i % 3 == 0) {
        sum += i;
    }
}
```

### Factorial
```cpp
int fact = 1;
for (int i = 1; i <= n; i++) {
    fact = fact * i;
}
// 5! = 1 × 2 × 3 × 4 × 5 = 120
```

### Prime Number Check
```cpp
bool isPrime = true;
for (int i = 2; i < n; i++) {
    if (n % i == 0) {
        isPrime = false;
        break;
    }
}
```

---

## 📊 Quick Reference

| Loop Type | When to Use | Key Feature |
|-----------|-------------|-------------|
| `for` | Known iterations | Init, condition, update in one line |
| `while` | Condition-based | Checks before execution |
| `do-while` | At least one execution | Checks after execution |

| Statement | Purpose |
|-----------|---------|
| `if-else` | Two-way decision |
| `if-else if-else` | Multiple conditions |
| `switch` | Multiple fixed values |
| `ternary` | Quick conditional assignment |

---

## 📁 Code Examples
- **Code1.cpp**: Character case checking (if-else)
- **Code2.cpp**: Sum of numbers 1 to n (while loop)
- **Code3.cpp**: Sum of odd numbers (while with if)
- **Code4.cpp**: Prime number check (for loop with break)
- **Code5.cpp**: Sum of multiples of 3 (for loop)
- **Code6.cpp**: Factorial calculation (for loop)

---

## ⚡ Quick Tips

1. **Infinite Loop Prevention**: Always update loop variable
   ```cpp
   // ❌ Wrong
   while (i <= n) { sum += i; }  // i never changes!
   
   // ✅ Correct
   while (i <= n) { sum += i; i++; }
   ```

2. **Off-by-One Errors**: Check loop boundaries
   ```cpp
   for (int i = 0; i < n; i++)   // 0 to n-1
   for (int i = 1; i <= n; i++)  // 1 to n
   ```

3. **Break vs Continue**:
   - `break` → Exit loop completely
   - `continue` → Skip to next iteration

4. **Choose Right Loop**:
   - Count-based → `for`
   - Condition-based → `while`
   - Must run once → `do-while`

5. **Logical Operators**:
   - `&&` (AND) → Both conditions true
   - `||` (OR) → At least one true
   - `!` (NOT) → Negates condition

---

## 🎓 ASCII Values Reference
- `A-Z`: 65-90
- `a-z`: 97-122
- `0-9`: 48-57

---

*Master these patterns—they're the foundation of algorithmic thinking!*