# 🐹➡️🐍 Golang to Python Guide for Coding Interviews

**For Go developers transitioning to Python for technical interviews**

Since you use Go daily, you already have most of the mental models needed for Python! This guide focuses on the **differences** and **quick wins**.

---

## 🎯 Key Insight: Go and Python are Similar!

Good news: Go and Python share many concepts that C++ doesn't:

| Feature | Go ✅ | Python ✅ | C++ ❌ |
|---------|-------|----------|--------|
| Garbage collection | Yes | Yes | Manual |
| Slice syntax `[1:4]` | Yes | Yes | No |
| Built-in hash maps | Yes | Yes | Need `<unordered_map>` |
| Simple syntax | Yes | Yes | Complex |
| No semicolons | Yes | Yes | Required |
| Duck typing (interfaces) | Kind of | Yes | No |
| Multiple return values | Yes | Yes (tuples) | No (need pair) |
| First-class functions | Yes | Yes | Kind of |

**Bottom line:** You're 70% there already! Focus on syntax differences, not concepts.

---

## 🔄 Direct Go-Python Mapping

### Data Structures

| Go | Python | Notes |
|-----|--------|-------|
| `[]int` | `list` | Dynamic arrays |
| `make([]int, n)` | `[0] * n` | Pre-allocated list |
| `append(slice, x)` | `list.append(x)` | Go returns new slice, Python mutates |
| `slice[1:4]` | `list[1:4]` | **Same syntax!** |
| `map[string]int` | `dict` | Hash maps |
| `make(map[K]V)` | `{}` or `dict()` | No make needed |
| `delete(map, key)` | `del dict[key]` | Remove key |
| No built-in set | `set()` | Python has native sets! |
| No built-in stack | `list` | Use list as stack |
| No built-in queue | `deque` | Import from collections |
| No built-in heap | `heapq` | Import heapq |

### Control Flow

| Go | Python |
|-----|--------|
| `if x > 0 { ... }` | `if x > 0:` |
| `else if` | `elif` |
| `for i := 0; i < n; i++` | `for i in range(n):` |
| `for _, val := range arr` | `for val in arr:` |
| `for i, val := range arr` | `for i, val in enumerate(arr):` |
| `for k, v := range map` | `for k, v in dict.items():` |
| `for { ... }` (infinite) | `while True:` |
| `break` | `break` (same!) |
| `continue` | `continue` (same!) |

### Functions

**Go:**
```go
func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)
    for i, num := range nums {
        complement := target - num
        if j, ok := seen[complement]; ok {
            return []int{j, i}
        }
        seen[num] = i
    }
    return []int{}
}
```

**Python:**
```python
def twoSum(nums: List[int], target: int) -> List[int]:
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []
```

**Key differences:**
- No `func` keyword, use `def`
- Type hints are optional (but recommended)
- No `make()` needed for maps/dicts
- `if x in dict` instead of `if val, ok := map[x]; ok`
- Indentation instead of braces

### Multiple Return Values

**Go:**
```go
func divmod(a, b int) (int, int) {
    return a / b, a % b
}

quotient, remainder := divmod(10, 3)
```

**Python:**
```python
def divmod(a: int, b: int) -> tuple[int, int]:
    return a // b, a % b

quotient, remainder = divmod(10, 3)
```

**Very similar!** Python uses tuples for multiple returns.

### Error Handling

**Go style:**
```go
val, ok := myMap[key]
if !ok {
    // key doesn't exist
}
```

**Python style:**
```python
# Style 1: Check membership
if key in my_dict:
    val = my_dict[key]

# Style 2: get() with default
val = my_dict.get(key, default_value)

# Style 3: Try-except (not common in interviews)
try:
    val = my_dict[key]
except KeyError:
    # handle error
```

---

## 🚀 Quick Wins for Go Developers

### 1. Slice Operations (Almost Identical!)

**Go:**
```go
nums := []int{0, 1, 2, 3, 4, 5}

nums[1:4]     // [1 2 3]
nums[:3]      // [0 1 2]
nums[3:]      // [3 4 5]
nums[:]       // Copy entire slice
len(nums)     // 6
```

**Python:**
```python
nums = [0, 1, 2, 3, 4, 5]

nums[1:4]     # [1, 2, 3] - SAME!
nums[:3]      # [0, 1, 2] - SAME!
nums[3:]      # [3, 4, 5] - SAME!
nums[:]       # Copy entire list - SAME!
len(nums)     # 6 - SAME!

# Python extras:
nums[-1]      # 5 - last element (negative indexing!)
nums[-2:]     # [4, 5] - last 2 elements
nums[::-1]    # [5, 4, 3, 2, 1, 0] - REVERSE!
nums[::2]     # [0, 2, 4] - every 2nd element
```

### 2. Range Loops (Very Similar!)

**Go:**
```go
// Index + value
for i, val := range nums {
    fmt.Println(i, val)
}

// Just value
for _, val := range nums {
    fmt.Println(val)
}

// Just index
for i := range nums {
    fmt.Println(i)
}

// Map iteration
for key, val := range myMap {
    fmt.Println(key, val)
}
```

**Python:**
```python
# Index + value
for i, val in enumerate(nums):
    print(i, val)

# Just value
for val in nums:
    print(val)

# Just index
for i in range(len(nums)):
    print(i)

# Dict iteration
for key, val in my_dict.items():
    print(key, val)

# Just keys
for key in my_dict:
    print(key)

# Just values
for val in my_dict.values():
    print(val)
```

### 3. No Make/New Needed!

**Go:**
```go
// Need make for maps and slices
myMap := make(map[string]int)
slice := make([]int, 10)
slice2 := []int{}
```

**Python:**
```python
# Just use literals!
my_dict = {}
my_list = [0] * 10
my_list2 = []
```

### 4. String Operations

**Go:**
```go
import "strings"

s := "hello world"
strings.Split(s, " ")           // ["hello", "world"]
strings.Join([]string{"a", "b"}, ",")  // "a,b"
strings.Contains(s, "world")    // true
strings.ToUpper(s)              // "HELLO WORLD"
len(s)                          // 11
```

**Python:**
```python
s = "hello world"
s.split(" ")           # ["hello", "world"] - method, not function!
",".join(["a", "b"])   # "a,b" - join is on the separator!
"world" in s           # True - simpler!
s.upper()              # "HELLO WORLD" - method
len(s)                 # 11 - same
```

### 5. Append vs Append

**Go (returns new slice):**
```go
nums := []int{1, 2, 3}
nums = append(nums, 4)     // Must reassign!
```

**Python (mutates in place):**
```python
nums = [1, 2, 3]
nums.append(4)             # No reassignment needed
# nums is now [1, 2, 3, 4]
```

**Important:** Python's `append()` mutates the list, Go's `append()` returns a new slice.

### 6. Type Checking

**Go:**
```go
// Type is always explicit or inferred
var x int = 5
y := 10        // Type inferred
```

**Python:**
```python
# Type is dynamic
x = 5          # int
x = "hello"    # Now a string - OK!

# Type hints (optional, for clarity)
x: int = 5
y: str = "hello"

def add(a: int, b: int) -> int:
    return a + b
```

---

## 📊 Side-by-Side Problem Comparison

### Problem: Two Sum

**Go:**
```go
func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)

    for i, num := range nums {
        complement := target - num
        if j, ok := seen[complement]; ok {
            return []int{j, i}
        }
        seen[num] = i
    }

    return []int{}
}
```

**Python:**
```python
def twoSum(self, nums: List[int], target: int) -> List[int]:
    seen = {}

    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i

    return []
```

**Differences:**
1. `func` → `def`
2. `make(map[int]int)` → `{}`
3. `if j, ok := seen[x]; ok` → `if x in seen`
4. `[]int{j, i}` → `[j, i]`
5. `range nums` → `enumerate(nums)`

### Problem: Valid Parentheses

**Go:**
```go
func isValid(s string) bool {
    stack := []rune{}
    pairs := map[rune]rune{
        ')': '(',
        '}': '{',
        ']': '[',
    }

    for _, char := range s {
        if _, ok := pairs[char]; ok {
            if len(stack) == 0 || stack[len(stack)-1] != pairs[char] {
                return false
            }
            stack = stack[:len(stack)-1]  // Pop
        } else {
            stack = append(stack, char)    // Push
        }
    }

    return len(stack) == 0
}
```

**Python:**
```python
def isValid(self, s: str) -> bool:
    stack = []
    pairs = {
        ')': '(',
        '}': '{',
        ']': '[',
    }

    for char in s:
        if char in pairs:
            if not stack or stack[-1] != pairs[char]:
                return False
            stack.pop()
        else:
            stack.append(char)

    return len(stack) == 0
```

**Differences:**
1. `[]rune{}` → `[]` (Python strings are iterable)
2. `if _, ok := pairs[x]; ok` → `if x in pairs`
3. `stack[len(stack)-1]` → `stack[-1]` (negative indexing!)
4. `stack[:len(stack)-1]` → `stack.pop()` (cleaner!)
5. No `rune` type needed

### Problem: Binary Tree Level Order

**Go:**
```go
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }

    result := [][]int{}
    queue := []*TreeNode{root}

    for len(queue) > 0 {
        levelSize := len(queue)
        level := []int{}

        for i := 0; i < levelSize; i++ {
            node := queue[0]
            queue = queue[1:]  // Dequeue (O(n) - not ideal!)

            level = append(level, node.Val)

            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
        }

        result = append(result, level)
    }

    return result
}
```

**Python:**
```python
from collections import deque

def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level = []

        for _ in range(level_size):
            node = queue.popleft()  # O(1) - efficient!

            level.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level)

    return result
```

**Key differences:**
1. `nil` → `None` or `not root`
2. Use `deque` for efficient queue (Go slices are O(n) for dequeue)
3. `queue.popleft()` → O(1) vs `queue = queue[1:]` → O(n)
4. `node.Val` → `node.val` (Python convention: lowercase)
5. `for i := 0; i < n; i++` → `for _ in range(n):`

### Problem: Group Anagrams

**Go:**
```go
import "sort"
import "strings"

func groupAnagrams(strs []string) [][]string {
    groups := make(map[string][]string)

    for _, s := range strs {
        // Sort string to use as key
        chars := strings.Split(s, "")
        sort.Strings(chars)
        key := strings.Join(chars, "")

        groups[key] = append(groups[key], s)
    }

    result := [][]string{}
    for _, group := range groups {
        result = append(result, group)
    }

    return result
}
```

**Python:**
```python
from collections import defaultdict

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    groups = defaultdict(list)

    for s in strs:
        # Sort string to use as key
        key = ''.join(sorted(s))
        groups[key].append(s)

    return list(groups.values())
```

**Key differences:**
1. `defaultdict(list)` auto-creates empty lists (no append check needed!)
2. `sorted(s)` returns sorted characters
3. `''.join(sorted(s))` is cleaner than Go's split→sort→join
4. `groups.values()` extracts all values
5. Much more concise!

---

## 🎨 Python Features Go Doesn't Have

### 1. List Comprehensions (Game Changer!)

**Go:**
```go
// Filter even numbers
evens := []int{}
for _, num := range nums {
    if num % 2 == 0 {
        evens = append(evens, num)
    }
}

// Square all numbers
squares := []int{}
for _, num := range nums {
    squares = append(squares, num * num)
}
```

**Python:**
```python
# Filter even numbers
evens = [num for num in nums if num % 2 == 0]

# Square all numbers
squares = [num * num for num in nums]

# Both at once
even_squares = [num * num for num in nums if num % 2 == 0]
```

**This is huge for interviews!** Much faster to write.

### 2. Dictionary Comprehensions

**Go:**
```go
// Create frequency map
freq := make(map[int]int)
for _, num := range nums {
    freq[num]++
}
```

**Python:**
```python
# Using Counter (best for this)
from collections import Counter
freq = Counter(nums)

# Or dict comprehension
freq = {num: nums.count(num) for num in set(nums)}

# Invert a dict
inverted = {v: k for k, v in original.items()}
```

### 3. Negative Indexing

**Go:**
```go
nums := []int{1, 2, 3, 4, 5}
last := nums[len(nums)-1]           // Last element
secondLast := nums[len(nums)-2]     // Second to last
```

**Python:**
```python
nums = [1, 2, 3, 4, 5]
last = nums[-1]          # Last element
second_last = nums[-2]   # Second to last

# Even in slicing
last_two = nums[-2:]     # [4, 5]
```

### 4. Multiple Assignment & Unpacking

**Go:**
```go
// Swap requires temp
temp := a
a = b
b = temp

// Multiple returns
q, r := divmod(10, 3)
```

**Python:**
```python
# Swap without temp!
a, b = b, a

# Multiple assignment
x, y, z = 1, 2, 3

# Unpack list
first, second, *rest = [1, 2, 3, 4, 5]
# first=1, second=2, rest=[3, 4, 5]

first, *middle, last = [1, 2, 3, 4, 5]
# first=1, middle=[2, 3, 4], last=5
```

### 5. Any/All (Super Useful!)

**Go:**
```go
// Check if any element > 10
hasLarge := false
for _, num := range nums {
    if num > 10 {
        hasLarge = true
        break
    }
}

// Check if all positive
allPositive := true
for _, num := range nums {
    if num <= 0 {
        allPositive = false
        break
    }
}
```

**Python:**
```python
# Check if any element > 10
has_large = any(num > 10 for num in nums)

# Check if all positive
all_positive = all(num > 0 for num in nums)
```

### 6. Built-in Sets

**Go:**
```go
// Need to simulate with map[T]bool or map[T]struct{}
seen := make(map[int]bool)
seen[5] = true
if seen[5] {
    // exists
}
```

**Python:**
```python
# Native set support!
seen = set()
seen.add(5)
if 5 in seen:
    # exists

# Set operations
set1 & set2    # Intersection
set1 | set2    # Union
set1 - set2    # Difference
```

### 7. String Methods (Not Functions!)

**Go:**
```go
import "strings"

strings.Split(s, " ")
strings.Join(parts, ",")
strings.ToUpper(s)
strings.Contains(s, "x")
```

**Python:**
```python
# Methods on the string itself
s.split(" ")
",".join(parts)      # Note: join is on the separator!
s.upper()
"x" in s             # More readable than contains
```

---

## ⚡ Common Gotchas for Go Developers

### 1. Append Mutates in Python

**Go (returns new):**
```go
nums := []int{1, 2}
nums = append(nums, 3)  // MUST reassign
```

**Python (mutates):**
```python
nums = [1, 2]
nums.append(3)  # No reassign needed
# nums is now [1, 2, 3]
```

### 2. Integer Division

**Go:**
```go
x := 5 / 2      // 2 (integer division)
x := 5.0 / 2    // 2.5 (float division)
```

**Python 3:**
```python
x = 5 / 2       # 2.5 (float division by default!)
x = 5 // 2      # 2 (integer division - use //)
```

**Important:** Use `//` for integer division in Python!

### 3. Strings are Immutable (Like Go!)

**Both Go and Python:**
```go
// Go - can't do this:
s := "hello"
s[0] = 'H'  // Error!
```

```python
# Python - can't do this:
s = "hello"
s[0] = 'H'  # Error!

# Must create new string:
s = 'H' + s[1:]  # "Hello"
```

### 4. No While Loop with Init/Post

**Go:**
```go
for i := 0; i < n; i++ {
    // ...
}

// Or C-style while
for i < n {
    // ...
    i++
}
```

**Python:**
```python
# Use range for traditional for loop
for i in range(n):
    # ...

# Or while
i = 0
while i < n:
    # ...
    i += 1
```

### 5. Truth Values

**Go:**
```go
if len(slice) == 0 {  // Must be explicit
    // ...
}

if myMap != nil {
    // ...
}
```

**Python:**
```python
# Can use truthiness
if not my_list:  # Empty list is False
    # ...

if my_dict:  # Non-empty dict is True
    # ...

# But can also be explicit
if len(my_list) == 0:
    # ...
```

**Truthy/Falsy in Python:**
- Falsy: `None`, `False`, `0`, `0.0`, `''`, `[]`, `{}`, `set()`
- Truthy: Everything else

### 6. No Increment Operators

**Go:**
```go
i++
i--
```

**Python:**
```python
i += 1
i -= 1

# No i++ or i-- !
```

---

## 🎯 Quick Reference: Go → Python

| Go | Python | Notes |
|-----|--------|-------|
| `make([]int, n)` | `[0] * n` | Pre-allocated list |
| `append(s, x)` | `s.append(x)` | Python mutates |
| `s[1:]` | `s[1:]` | Same! |
| `len(s)` | `len(s)` | Same! |
| `make(map[K]V)` | `{}` | No make needed |
| `delete(m, k)` | `del m[k]` | Remove key |
| `val, ok := m[k]` | `k in m` then `m[k]` | Or use `m.get(k)` |
| `for k, v := range m` | `for k, v in m.items()` | Dict iteration |
| `for i, v := range s` | `for i, v in enumerate(s)` | Index + value |
| `nil` | `None` | Null value |
| `true`, `false` | `True`, `False` | Capitalized! |
| `&&`, `||`, `!` | `and`, `or`, `not` | Words not symbols |
| `i++` | `i += 1` | No ++ operator |
| `5 / 2` | `5 // 2` | Use // for int div |
| `fmt.Sprintf("%d", x)` | `str(x)` or `f"{x}"` | String conversion |
| `strconv.Atoi(s)` | `int(s)` | String to int |
| No set | `set()` | Native sets! |
| No heap | `import heapq` | Min heap by default |
| `math.MaxInt` | `float('inf')` | Infinity |

---

## 📚 Week-by-Week Plan (Accelerated for Go Devs)

### Week 1: Python Syntax (10 hours total)

**Day 1-2: Core Differences (3 hours)**
- Indentation instead of braces
- `def` instead of `func`
- Type hints (optional)
- No `make()`, use literals
- **Practice**: Convert 10 Go solutions to Python

**Day 3-4: Collections (3 hours)**
- `dict` vs `map`
- `list` vs `slice`
- `set` (new for you!)
- `deque` for queues
- **Practice**: Convert 10 more problems

**Day 5-6: Python Idioms (3 hours)**
- List comprehensions
- `enumerate()`, `zip()`
- `any()`, `all()`
- Negative indexing
- **Practice**: Rewrite 10 old solutions more Pythonically

**Day 7: Mock Interview (1 hour)**
- Solve 3 medium problems in Python
- Time yourself

### Week 2: Speed & Fluency (10 hours total)

**Daily**: Solve 5-7 problems in Python
- Focus on speed
- Use Python idioms
- Explain solutions out loud

### Week 3+: Mastery

**Daily**: 3-5 new problems in Python
**Weekly**: 1 mock interview

---

## 💪 Your Advantages as a Go Developer

1. ✅ **Already comfortable with slicing** - same syntax!
2. ✅ **Already use `range`** - similar to `enumerate()`
3. ✅ **Already use maps** - just called `dict` in Python
4. ✅ **Already comfortable with garbage collection** - no manual memory
5. ✅ **Already write simple, clean code** - Go philosophy carries over
6. ✅ **Already understand interfaces/duck typing** - Python is even more dynamic
7. ✅ **Already understand multiple returns** - Python uses tuples

### What You Need to Learn (Minimal!)

1. ❌ Indentation instead of braces (1 day to get used to)
2. ❌ `in` operator instead of `if val, ok := map[key]; ok`
3. ❌ List comprehensions (game changer - 2 days to master)
4. ❌ `//` for integer division (easy to remember)
5. ❌ Native `set` support (you'll love this!)
6. ❌ `heapq` for priority queues
7. ❌ Methods on types (e.g., `s.split()` not `strings.Split(s)`)

**Estimated time to fluency: 2-3 weeks** (much faster than typical C++ developer!)

---

## 🚀 Final Recommendation

**You should definitely learn Python!**

**Why:**
1. Your Go experience makes Python easy (70% similar)
2. You'll learn Python 2-3x faster than a pure C++ dev
3. Most companies prefer Python for interviews
4. You can be productive in Python within 1-2 weeks

**How:**
1. Spend 3-4 days converting 30-40 of your C++ solutions to Python
2. Focus on list comprehensions, `enumerate()`, and `in` operator
3. Practice explaining code in Python (not Go terms)
4. Use Python for all new practice problems

**Timeline:**
- Week 1: Learn syntax, convert old problems
- Week 2: New problems in Python, build speed
- Week 3: Mock interviews in Python

**You got this!** 🎉

Your Go background is actually a **huge advantage** over pure C++ developers learning Python. Use it wisely!
