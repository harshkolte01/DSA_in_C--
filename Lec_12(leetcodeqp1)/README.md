# Lecture 12: LeetCode Problems - Part 1 🚀

## Quick Revision Guide

---

## 1. Container With Most Water (Mostwater.cpp)
**LeetCode Problem**: Given an array of heights, find maximum water that can be trapped between two lines.

### Approaches:

#### Brute Force - O(n²)
- Check all pairs (i, j)
- Calculate area = (j - i) × min(height[i], height[j])
- Track maximum

#### ✅ Optimized (Two Pointer) - O(n)
```cpp
int lp = 0, rp = n - 1;
while (lp < rp) {
    int width = rp - lp;
    int ht = min(height[lp], height[rp]);
    maxWater = max(maxWater, width * ht);
    
    // Move pointer with smaller height
    height[lp] < height[rp] ? lp++ : rp--;
}
```

**Key Insight**: Move the pointer with smaller height inward (only way to potentially get larger area)

---

## 2. Power Function - x^n (POW.cpp)
**LeetCode 50**: Implement pow(x, n) which calculates x raised to power n.

### Binary Exponentiation - O(log n)
```cpp
// Key idea: x^n = (x²)^(n/2) if n is even
//            x^n = x × (x²)^((n-1)/2) if n is odd

while (n > 0) {
    if (n % 2 == 1) {
        ans *= x;  // If odd, multiply once
    }
    x *= x;  // Square the base
    n /= 2;  // Halve the exponent
}
```

**Edge Cases**:
- n = 0 → return 1
- x = 0 → return 0
- n < 0 → x = 1/x, n = -n

**Time**: O(log n) | **Space**: O(1)

---

## 3. Product of Array Except Self (productofarray)
**LeetCode 238**: Return array where output[i] = product of all elements except nums[i]  
**Constraint**: Don't use division, solve in O(n)

### Approaches:

#### Method 1: Prefix × Suffix Arrays - O(n) time, O(n) space
```cpp
// prefix[i] = product of all elements before i
// suffix[i] = product of all elements after i
// ans[i] = prefix[i] × suffix[i]

for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] * nums[i-1];
}
for (int i = n-2; i >= 0; i--) {
    suffix[i] = suffix[i+1] * nums[i+1];
}
```

#### ✅ Method 2: Space Optimized - O(n) time, O(1) space
```cpp
// Use ans array to store prefix first
for (int i = 1; i < n; i++) {
    ans[i] = ans[i-1] * nums[i-1];
}

// Then multiply with suffix on the fly
int suffix = 1;
for (int i = n-2; i >= 0; i--) {
    suffix *= nums[i+1];
    ans[i] *= suffix;
}
```

**Core Logic**: 
- ans[i] = (product of all before i) × (product of all after i)

---

## 4. Best Time to Buy and Sell Stock (STOCKB&S.cpp)
**LeetCode 121**: Find maximum profit from one buy and one sell transaction.

### Single Pass Solution - O(n)
```cpp
int bestBuy = prices[0];
int maxProfit = 0;

for (int i = 1; i < n; i++) {
    if (prices[i] > bestBuy) {
        maxProfit = max(maxProfit, prices[i] - bestBuy);
    }
    bestBuy = min(bestBuy, prices[i]);
}
```

**Key Insight**: 
- Track minimum price seen so far (best buy point)
- At each day, calculate profit if we sell today
- Keep updating maximum profit

**Time**: O(n) | **Space**: O(1)

---

## Common Patterns Covered 🎯

| Pattern | Problems | Time Complexity |
|---------|----------|-----------------|
| **Two Pointers** | Container with Most Water | O(n) |
| **Binary Exponentiation** | Power(x, n) | O(log n) |
| **Prefix/Suffix Products** | Product Array Except Self | O(n) |
| **Kadane's Variant** | Stock Buy & Sell | O(n) |

---

## Key Takeaways 💡

1. **Two Pointers**: Useful for array problems requiring pair selection
2. **Prefix/Suffix Arrays**: Pre-compute cumulative results for O(1) queries
3. **Space Optimization**: Try to reuse output array or use variables
4. **Greedy Approach**: For stock problem, track running minimum
5. **Binary Method**: Reduces O(n) operations to O(log n)

---

## Interview Tips 📝

✅ Always clarify constraints (array size, value ranges, negative numbers?)  
✅ Start with brute force, then optimize  
✅ Think about edge cases (empty array, single element, all same)  
✅ Can you do it in one pass?  
✅ Can you reduce space complexity?

---

## Practice Problems (Similar)

- **Two Pointers**: 3Sum, Trapping Rain Water
- **Power**: Fast Exponentiation, Matrix Exponentiation
- **Product Array**: Range Product Queries
- **Stock**: Best Time to Buy Sell Stock II (multiple transactions)

---

**Next Steps**: Practice these problems on LeetCode until you can solve them without looking at the solution! 💪
