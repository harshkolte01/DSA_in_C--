# Lecture 16: C++ STL (Standard Template Library)

## Overview
The C++ STL consists of:
- **Containers**: Data structures (vector, list, deque, stack, queue, map, set, etc.)
- **Iterators**: Objects to traverse containers
- **Algorithms**: Functions for operations (sort, reverse, search, etc.)
- **Functors**: Function objects

---

## 1. Vector (Code1.cpp)
**Dynamic array with resizable capacity**

### Creation
```cpp
vector<int> vec;                  // empty vector
vector<int> vec = {1, 2};        // initializer list
vector<int> vec(3, 10);          // 3 elements, all 10
vector<int> vec2(vec1);          // copy constructor
```

### O(1) Functions
- `size()` - number of elements
- `capacity()` - allocated space
- `push_back(val)` - add at end
- `pop_back()` - remove from end
- `emplace_back(val)` - construct at end (faster than push_back)
- `at(i)` or `[i]` - access element
- `front()` - first element
- `back()` - last element
- `empty()` - check if empty

### O(n) Functions
- `erase(iterator)` - remove element
- `insert(iterator, val)` - insert element
- `clear()` - remove all elements

### Iterators
```cpp
vec.begin()   // points to first element
vec.end()     // points after last element
vec.rbegin()  // reverse begin
vec.rend()    // reverse end

// Forward iteration
for(auto it = vec.begin(); it != vec.end(); it++) {
    cout << *it << " ";
}

// Backward iteration
for(auto it = vec.rbegin(); it != vec.rend(); it++) {
    cout << *it << " ";
}
```

---

## 2. List (Code2.cpp)
**Doubly linked list**

```cpp
list<int> l = {1, 2, 3};
```

### Functions
- `push_back()` & `push_front()`
- `emplace_back()` & `emplace_front()`
- `pop_back()` & `pop_front()`
- `size()`, `erase()`, `clear()`, `empty()`
- `begin()`, `end()`, `rbegin()`, `rend()`
- `insert()`, `front()`, `back()`

---

## 3. Deque (Code3.cpp)
**Double Ended Queue**

```cpp
deque<int> d = {1, 2, 3};
```

### Functions (same as list)
- `push_back()` & `push_front()`
- `emplace_back()` & `emplace_front()`
- `pop_back()` & `pop_front()`
- `size()`, `erase()`, `clear()`, `empty()`
- `begin()`, `end()`, `rbegin()`, `rend()`
- `insert()`, `front()`, `back()`

---

## 4. Pair (Code3.cpp)
**Store two values together**

```cpp
pair<int, int> p = {3, 5};
pair<char, int> p = {'a', 1};

cout << p.first << " " << p.second;
```

---

## 5. Stack (Code4.cpp)
**LIFO (Last In First Out)**

```cpp
stack<int> s;
```

### Functions
- `push(val)` - add element
- `emplace(val)` - construct element
- `top()` - get top element
- `pop()` - remove top element
- `size()` - number of elements
- `empty()` - check if empty
- `swap(stack2)` - swap contents

---

## 6. Queue (Code4.cpp)
**FIFO (First In First Out)**

```cpp
queue<int> q;
```

### Functions
- `push(val)` - add at back
- `emplace(val)` - construct at back
- `front()` - get front element
- `pop()` - remove front element
- `size()` - number of elements
- `empty()` - check if empty
- `swap(queue2)` - swap contents

---

## 7. Map (Code5.cpp)
**Key-value pairs (ordered by key)**

```cpp
map<string, int> m;
m["key"] = value;
m.insert({"apple", 5});
```

### Functions
- `insert()`, `emplace()` - add elements
- `count(key)` - returns 1 if exists, 0 otherwise
- `erase(key)` - remove element
- `find(key)` - returns iterator to element
- `size()`, `empty()`, `clear()`

### Variants
- **Multimap**: `multimap<string, int> m;` - allows duplicate keys
- **Unordered Map**: `unordered_map<string, int> m;` - hash-based, O(1) average access

---

## 8. Set (Code6.cpp)
**Unique elements (ordered)**

```cpp
set<int> s;
s.insert(5);
```

### Functions
- `insert()`, `emplace()` - add elements
- `count(val)` - returns 1 if exists, 0 otherwise
- `erase(val)` - remove element
- `find(val)` - returns iterator to element
- `size()`, `empty()`, `clear()`
- `lower_bound(val)` - iterator to first element ≥ val
- `upper_bound(val)` - iterator to first element > val

### Variants
- **Multiset**: `multiset<int> s;` - allows duplicates
- **Unordered Set**: `unordered_set<int> s;` - hash-based, O(1) average access

---

## 9. Algorithms (Code7.cpp)

### Sorting
```cpp
sort(arr, arr+n);                      // ascending
sort(arr, arr+n, greater<int>());      // descending
sort(v.begin(), v.end());              // vector
```

### Reverse
```cpp
reverse(v.begin(), v.end());
```

### Next Permutation
```cpp
next_permutation(v.begin(), v.end());
```

### Swap, Min, Max
```cpp
swap(a, b);
int maximum = max(a, b);
int minimum = min(a, b);
```

### Max & Min Element
```cpp
auto maxIt = max_element(v.begin(), v.end());
auto minIt = min_element(v.begin(), v.end());
cout << *maxIt << " " << *minIt;
```

### Binary Search
```cpp
bool found = binary_search(v.begin(), v.end(), target);
```

### Count Set Bits
```cpp
int bits = __builtin_popcount(n);      // for int
int bits = __builtin_popcountl(n);     // for long
int bits = __builtin_popcountll(n);    // for long long
```

---

## Quick Reference Table

| Container | Ordered | Duplicates | Access Time | Use Case |
|-----------|---------|------------|-------------|----------|
| Vector    | Yes     | Yes        | O(1) by index | Dynamic array |
| List      | Yes     | Yes        | O(n) | Insert/delete anywhere |
| Deque     | Yes     | Yes        | O(1) both ends | Double-ended queue |
| Stack     | LIFO    | Yes        | O(1) top | Last-in-first-out |
| Queue     | FIFO    | Yes        | O(1) front | First-in-first-out |
| Map       | Yes     | No keys    | O(log n) | Key-value pairs |
| Set       | Yes     | No         | O(log n) | Unique elements |
| Unordered Map | No  | No keys    | O(1) avg | Fast key-value |
| Unordered Set | No  | No         | O(1) avg | Fast unique check |

---

## Time Complexities

### Vector
- Access: O(1)
- Insert/Delete at end: O(1)
- Insert/Delete in middle: O(n)

### List/Deque
- Access: O(n)
- Insert/Delete at ends: O(1)
- Insert/Delete in middle: O(1) with iterator

### Map/Set
- Insert/Delete/Search: O(log n)

### Unordered Map/Set
- Insert/Delete/Search: O(1) average, O(n) worst case

### Stack/Queue
- Push/Pop: O(1)

---

## Tips for Usage
1. Use **vector** for most cases (best performance)
2. Use **list** when frequent insertions/deletions in middle
3. Use **map** for key-value associations
4. Use **set** for unique elements with ordering
5. Use **unordered_map/set** when order doesn't matter (faster)
6. Use **stack** for recursion, backtracking
7. Use **queue** for BFS, level-order traversal

---

**Files:**
- Code1.cpp - Vector operations
- Code2.cpp - List operations
- Code3.cpp - Deque and Pair
- Code4.cpp - Stack and Queue
- Code5.cpp - Map variants
- Code6.cpp - Set variants
- Code7.cpp - Algorithms
