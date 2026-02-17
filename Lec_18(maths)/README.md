# Lecture 18: Mathematics in DSA

## Quick Revision & Recap

This lecture covers essential mathematical concepts and operations commonly used in DSA problems.

---

## 📚 Topics Covered

1. **Digits Operations** - Extract, count, sum of digits
2. **Reverse a Number** - With overflow protection
3. **Armstrong Number** - Sum of cubes equals the number
4. **GCD / HCF** - Euclid's algorithm
5. **LCM** - Using GCD formula
6. **Palindrome Number** - Same forwards and backwards
7. **Modulo Arithmetic** - Handle large numbers (MOD 10⁹ + 7)

### 1. **Digits Operations**

#### Extract/Print Digits
```cpp
void printDigits(int n) {
    while (n != 0) {
        int digit = n % 10;  // Get last digit
        cout << digit << " ";
        n = n / 10;          // Remove last digit
    }
}
```
**Example:** `n = 153` → Output: `3 5 1`

#### Count Digits
```cpp
int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = n / 10;
    }
    return count;
}
```
**Example:** `n = 153` → Output: `3`

#### Sum of Digits
```cpp
int sumDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}
```
**Example:** `n = 153` → Output: `9` (1+5+3)

---

### 2. **Reverse a Number**

Reverse the digits of a number with overflow protection.

```cpp
int reverseNo(int n) {
    int revNum = 0;
    while (n != 0) {
        int digit = n % 10;
        // Check for overflow before multiplying
        if (revNum > INT_MAX/10 || revNum < INT_MIN/10) {
            return 0;
        }
        revNum = revNum * 10 + digit;
        n = n / 10;
    }
    return revNum;
}
```
**Example:** `n = 123` → Output: `321`

**Key Point:** Always check for overflow when dealing with 32-bit integers!

---

### 3. **Armstrong Number**

A number equals the sum of cubes of its digits (for 3-digit numbers).

```cpp
bool isArmstrong(int n) {
    int original = n;  // Store original value
    int sum = 0;
    while(n != 0) {
        int digit = n % 10;
        sum += pow(digit, 3);
        n = n / 10;
    }
    return sum == original;
}
```
**Examples:** 
- `153` → `1³ + 5³ + 3³ = 1 + 125 + 27 = 153` ✅
- `371` → `3³ + 7³ + 1³ = 27 + 343 + 1 = 371` ✅
- `123` → `1³ + 2³ + 3³ = 1 + 8 + 27 = 36` ❌

---

### 4. **GCD / HCF (Greatest Common Divisor)**

#### Simple Approach (Brute Force)
```cpp
int gcd(int a, int b) {
    int gcd = 1;
    for(int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}
```
**Time Complexity:** O(min(a, b))

#### Euclid's Algorithm (Optimal)
```cpp
int euclidsAlgo(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return (a == 0) ? b : a;
}
```
**Time Complexity:** O(log(min(a, b)))

**Example:** `GCD(20, 28)`
- Step 1: `28 % 20 = 8`
- Step 2: `20 % 8 = 4`
- Step 3: `8 % 4 = 0`
- Result: `4`

---

### 5. **LCM (Least Common Multiple)**

Formula: `LCM(a, b) = (a × b) / GCD(a, b)`

```cpp
int getLCM(int a, int b) {
    return (a * b) / gcd(a, b);
}
```
**Example:** `LCM(20, 28) = (20 × 28) / 4 = 560 / 4 = 140`

---

### 6. **Palindrome Number**

A number that reads the same forwards and backwards.

```cpp
bool isPalindrome(int n) {
    if (n < 0) return false;  // Negative numbers are not palindromes
    int revNum = reverseNo(n);
    return n == revNum;  // Use == for comparison, not =
}
```
**Examples:**
- `121` → `true` ✅
- `153` → `false` ❌
- `-121` → `false` ❌
- `10` → `false` ❌

---

### 7. **Modulo Arithmetic**

Modulo operation returns the remainder when one number is divided by another. In competitive programming, results are often asked "modulo 10⁹ + 7" to prevent overflow.

#### Why Use Modulo?
- Large calculations can exceed `long long` range
- `10⁹ + 7` is a prime number (good for hash functions)
- Keeps numbers manageable while preserving relative differences

#### Modulo Properties

```cpp
const int MOD = 1e9 + 7;  // 1000000007

// Addition
(a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD

// Subtraction
(a - b) % MOD = ((a % MOD) - (b % MOD) + MOD) % MOD

// Multiplication
(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD

// Division (NOT DISTRIBUTIVE - needs modular inverse)
(a / b) % MOD ≠ (a % MOD) / (b % MOD)
```

#### Common Usage Example

```cpp
const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Calculate factorial with modulo
long long factorialMod(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}
```

**Example:** Calculate area modulo 10⁹ + 7
```cpp
long long area = length * width;
area = area % MOD;
return area;
```

**Real Problem:** LeetCode 850 - Rectangle Area II  
Calculate total area covered by rectangles and return result modulo 10⁹ + 7.

#### Important Notes
- Always use `long long` for intermediate calculations to avoid overflow
- Apply modulo at each step, not just at the end
- For subtraction, add MOD before taking modulo to handle negative results
- Division requires modular multiplicative inverse

---

## 🎯 Key Takeaways

1. **Digit Extraction:** Use `n % 10` to get last digit, `n / 10` to remove it
2. **Overflow Protection:** Always check before multiplying large numbers
3. **Armstrong Numbers:** For 3-digit numbers, sum of cubes equals the number
4. **GCD:** Use Euclid's algorithm for optimal performance
5. **LCM Formula:** `LCM = (a × b) / GCD(a, b)`
6. **Palindrome:** Reverse the number and compare with original
7. **Modulo Arithmetic:** Apply modulo at each step to prevent overflow (use 10⁹ + 7)
8. **Common Mistakes:**
   - Using `=` (assignment) instead of `==` (comparison)
   - Not storing original value before modifying in loops
   - Forgetting overflow checks for reverse operations
   - Applying modulo only at the end instead of each step
   - Forgetting to add MOD before modulo in subtraction

---

## 🔍 Common Patterns

### Pattern 1: Processing Each Digit
```cpp
while (n != 0) {
    int digit = n % 10;
    // Do something with digit
    n = n / 10;
}
```

### Pattern 2: Building a Number
```cpp
int result = 0;
while (condition) {
    result = result * 10 + digit;
}
```

### Pattern 3: Overflow Check
```cpp
if (result > INT_MAX/10 || result < INT_MIN/10) {
    return 0;  // Handle overflow
}
```

### Pattern 4: Modulo Operations
```cpp
const int MOD = 1e9 + 7;

// For multiplication
result = (result * value) % MOD;

// For addition
result = ((result % MOD) + (value % MOD)) % MOD;

// For subtraction (avoid negative)
result = ((result % MOD) - (value % MOD) + MOD) % MOD;
```

---

## 💡 Practice Tips

1. Test with edge cases: 0, negative numbers, INT_MAX, INT_MIN
2. Always consider overflow for reverse/multiplication operations
3. Remember to store original values before modifying in loops
4. Use Euclid's algorithm for GCD - it's much faster!
5. For Armstrong numbers, generalize by counting digits first
6. When using modulo, apply it at each step, not just at the end
7. Use `long long` for intermediate calculations with modulo
8. Remember: `(a - b) % MOD` needs `+ MOD` to handle negatives

---

## 📊 Time Complexities

| Operation | Simple Approach | Optimal Approach |
|-----------|----------------|------------------|
| Count Digits | O(log n) | O(log n) |
| Reverse Number | O(log n) | O(log n) |
| Armstrong Check | O(log n) | O(log n) |
| GCD | O(min(a,b)) | O(log(min(a,b))) |
| LCM | O(min(a,b)) | O(log(min(a,b))) |
| Palindrome | O(log n) | O(log n) |
| Modulo Operations | O(1) per operation | O(1) per operation |
| Power with Modulo | O(n) | O(log n) |

---

## 🚀 Quick Formulas to Remember

- **Number of Digits:** `floor(log10(n)) + 1`
- **LCM Formula:** `LCM(a,b) = (a × b) / GCD(a,b)`
- **GCD Property:** `GCD(a,b) = GCD(b, a % b)`
- **Overflow Check:** `x > INT_MAX / 10` before doing `x * 10`
- **Modulo Addition:** `(a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD`
- **Modulo Multiplication:** `(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD`
- **Modulo Subtraction:** `(a - b) % MOD = ((a % MOD) - (b % MOD) + MOD) % MOD`
- **Common MOD Value:** `1e9 + 7 = 1000000007`

---

Happy Coding! 🎉
