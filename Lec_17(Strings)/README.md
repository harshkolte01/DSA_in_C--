# Lecture 17 - Strings in C++

## Table of Contents
1. [Character Arrays](#character-arrays)
2. [String Class](#string-class)
3. [String Operations](#string-operations)
4. [LeetCode Problems](#leetcode-problems)

---

## Character Arrays

### Code1.cpp - Character Array Basics

**Concept:**
- Character arrays are null-terminated (`\0`)
- Used to store sequences of characters
- Fixed size, declared at compile time

**Input Methods:**
```cpp
cin >> str;              // Reads until whitespace
cin.getline(str, size);  // Reads entire line including spaces
cin.getline(str, size, delimiter); // Reads until custom delimiter
```

**Example:**
```cpp
char str[10];
cin.getline(str, 100, '$'); // Reads until '$' character
```

**Key Points:**
- `cin >>` stops at whitespace
- `getline()` reads complete line with spaces
- Always consider the null terminator `\0` in size

---

## String Class

### Code2.cpp - Strings vs Character Arrays

**Why Strings are Better:**
1. **Dynamic size** - grows/shrinks automatically
2. **Easy comparison** - use `==`, `!=` operators
3. **Built-in functions** - `reverse()`, `substr()`, `find()`, etc.
4. **No manual memory management**

**String Operations:**
```cpp
string str = "harsh";
reverse(str.begin(), str.end());  // Reverses the string
str.length();                      // Gets length
str.size();                        // Same as length()
```

**Loops:**
```cpp
// Normal loop
for(int i = 0; i < str.length(); i++) {
    cout << str[i];
}

// For-each loop
for(char ch : str) {
    cout << ch;
}
```

---

## String Operations

### Reverse String (Code2.cpp)

**Logic:**
- Use two pointers: `start` and `end`
- Swap characters and move pointers towards center
- Continue until `start >= end`

```cpp
void reverseString(vector<char>& s) {
    int start = 0;
    int end = s.size() - 1;
    
    while(start <= end) {
        swap(s[start++], s[end--]);
    }
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

## LeetCode Problems

### 1. Valid Palindrome (Code3.cpp)

**Problem:** Check if a string is a palindrome, considering only alphanumeric characters and ignoring cases.

**Logic:**
1. Use two pointers from start and end
2. Skip non-alphanumeric characters
3. Compare characters after converting to lowercase
4. Return false if mismatch found

```cpp
bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    
    while(start < end) {
        // Skip non-alphanumeric from start
        if(!isAlphaNum(s[start])) {
            start++;
            continue;
        }
        // Skip non-alphanumeric from end
        if(!isAlphaNum(s[end])) {
            end--;
            continue;
        }
        // Compare characters
        if(tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        start++; 
        end--;
    }
    return true;
}
```

**Helper Function:**
```cpp
bool isAlphaNum(char ch) {
    return (ch >= '0' && ch <= '9') || 
           (tolower(ch) >= 'a' && tolower(ch) <= 'z');
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 2. Remove All Occurrences of Substring (Code4.cpp)

**Problem:** Remove all occurrences of a substring from a string.

**Logic:**
1. Use `find()` to locate substring
2. Use `erase()` to remove it
3. Repeat until no occurrence found

```cpp
string removeOccurrences(string s, string part) {
    while(s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}
```

**String Functions Used:**
- `s.find(part)` - Returns index of first occurrence (or `npos` if not found)
- `s.erase(pos, len)` - Removes `len` characters from position `pos`

**Time Complexity:** O(n * m) where n = length of s, m = length of part  
**Space Complexity:** O(1)

**Example:**
- Input: s = "daabcbaabcbc", part = "abc"
- After 1st removal: "dabaabcbc"
- After 2nd removal: "dababc"
- After 3rd removal: "dab"

---

### 3. Permutation in String (Code5.cpp)

**Problem:** Check if string s2 contains any permutation of s1 as a substring.

**Logic - Sliding Window:**
1. Create frequency array for s1
2. Use sliding window of size = s1.length() on s2
3. For each window, compare frequency arrays
4. Return true if frequencies match

```cpp
bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};
    
    // Build frequency of s1
    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }
    
    int windSize = s1.length();
    
    // Check each window in s2
    for(int i = 0; i < s2.length(); i++) {
        int windFreq[26] = {0};
        int idx = i;
        
        // Build frequency for current window
        for(int j = 0; j < windSize && idx < s2.length(); j++) {
            windFreq[s2[idx] - 'a']++;
            idx++;
        }
        
        // Compare frequencies
        if(isFreqSame(freq, windFreq)) {
            return true;
        }
    }
    return false;
}
```

**Time Complexity:** O(n * m) where n = s2.length(), m = 26  
**Space Complexity:** O(1) - fixed size arrays

---

### 4. Reverse Words in a String (Code6.cpp)

**Problem:** Reverse the order of words in a string, handling extra spaces.

**Logic:**
1. Reverse the entire string
2. Reverse each individual word
3. Skip extra spaces

```cpp
string reverseWords(string s) {
    int n = s.length();
    string ans = "";
    
    // Step 1: Reverse entire string
    reverse(s.begin(), s.end());
    
    // Step 2: Reverse each word
    for(int i = 0; i < n; i++) {
        string word = "";
        
        // Extract word
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }
        
        // Reverse the word
        reverse(word.begin(), word.end());
        
        // Add to answer (skip empty words)
        if(word.length() > 0) {
            ans += " " + word;
        }
    }
    
    return ans.substr(1); // Remove leading space
}
```

**Example:**
- Input: "the sky is blue"
- After full reverse: "eulb si yks eht"
- After word reverses: " blue is sky the"
- Final: "blue is sky the"

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 5. String Compression (Code7.cpp)

**Problem:** Compress string by replacing consecutive characters with character + count.

**Logic:**
1. Count consecutive characters
2. Write character to array
3. If count > 1, write count as digits
4. Use single index to overwrite the array

```cpp
int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;  // Position to write compressed result
    
    for(int i = 0; i < n; i++) {
        char ch = chars[i];
        int count = 0;
        
        // Count consecutive occurrences
        while(i < n && chars[i] == ch) {
            count++;
            i++;
        }
        
        // Write character
        chars[idx++] = ch;
        
        // Write count if > 1
        if(count > 1) {
            string str = to_string(count);
            for(char dig : str) {
                chars[idx++] = dig;
            }
        }
        
        i--; // Adjust for loop increment
    }
    
    chars.resize(idx);
    return idx;
}
```

**Example:**
- Input: ["a","a","b","b","c","c","c"]
- Process: "aa" → "a2", "bb" → "b2", "ccc" → "c3"
- Output: ["a","2","b","2","c","3"] (length = 6)

**Time Complexity:** O(n)  
**Space Complexity:** O(1) - in-place modification

---

## Important String Functions

| Function | Description | Example |
|----------|-------------|---------|
| `str.length()` | Returns length | `"hello".length()` → 5 |
| `str.size()` | Same as length | `"hello".size()` → 5 |
| `str.find(s)` | Find substring | `"hello".find("ll")` → 2 |
| `str.substr(pos, len)` | Extract substring | `"hello".substr(1, 3)` → "ell" |
| `str.erase(pos, len)` | Remove characters | `s.erase(0, 2)` removes first 2 chars |
| `reverse(begin, end)` | Reverse string | `reverse(str.begin(), str.end())` |
| `tolower(ch)` | Convert to lowercase | `tolower('A')` → 'a' |
| `toupper(ch)` | Convert to uppercase | `toupper('a')` → 'A' |
| `isalnum(ch)` | Check alphanumeric | `isalnum('5')` → true |

---

## Common Patterns & Techniques

### 1. Two Pointer Technique
- Used for palindrome, reverse string
- Start from both ends, move towards center

### 2. Sliding Window
- Used for substring problems
- Maintain a window of fixed/variable size
- Move window across the string

### 3. Frequency Array
- Used for anagram, permutation problems
- Array of size 26 for lowercase letters
- Index = `char - 'a'`

### 4. String Manipulation
- Use `find()` and `erase()` for removals
- Use `substr()` for extraction
- Use `+` for concatenation

---

## Tips & Tricks

1. **Always use `str.length()` with parentheses** - it's a function, not a property
2. **Character comparison:** Use `'0'` to `'9'` (not 0 to 9) for digit checking
3. **Case insensitive:** Use `tolower()` or `toupper()` before comparison
4. **String vs char array:** Prefer strings for dynamic size and built-in functions
5. **Watch for edge cases:** Empty strings, single character, all same characters
6. **In-place modification:** Use index variable to overwrite input array

---

## Practice Problems

- ✅ Valid Palindrome
- ✅ Reverse String
- ✅ Remove Substring Occurrences
- ✅ Permutation in String
- ✅ Reverse Words in String
- ✅ String Compression

---

## Time & Space Complexity Summary

| Problem | Time | Space |
|---------|------|-------|
| Reverse String | O(n) | O(1) |
| Valid Palindrome | O(n) | O(1) |
| Remove Occurrence | O(n×m) | O(1) |
| Permutation in String | O(n×26) | O(1) |
| Reverse Words | O(n) | O(n) |
| String Compression | O(n) | O(1) |

---

**Happy Coding! 🚀**
