# 🐍 C++ to Python Conversion Guide for Coding Interviews

A comprehensive guide for C++ developers learning Python for technical interviews. This guide uses real examples from your coding practice repository.

---

## 📋 Table of Contents

1. [Quick Start Setup](#quick-start-setup)
2. [Syntax Comparison](#syntax-comparison)
3. [Data Structures Mapping](#data-structures-mapping)
4. [Real Problem Conversions](#real-problem-conversions)
5. [Common Patterns](#common-patterns)
6. [Python-Specific Tricks](#python-specific-tricks)
7. [Week-by-Week Learning Plan](#week-by-week-learning-plan)

---

## 🚀 Quick Start Setup

### Installing Python
```bash
# Check if Python is installed
python3 --version

# Install Python (macOS)
brew install python3

# Create virtual environment (optional but recommended)
python3 -m venv interview_env
source interview_env/bin/activate
```

### Running Python Code
```bash
# Interactive mode (REPL)
python3

# Run a file
python3 solution.py

# LeetCode-style testing
python3 -c "from solution import Solution; print(Solution().twoSum([2,7,11,15], 9))"
```

---

## 🔄 Syntax Comparison

### Basic Syntax

| Feature | C++ | Python |
|---------|-----|--------|
| **Comments** | `// comment` or `/* comment */` | `# comment` |
| **Print** | `cout << "Hello" << endl;` | `print("Hello")` |
| **Variables** | `int x = 5;` | `x = 5` |
| **Const** | `const int MAX = 100;` | `MAX = 100` |
| **If statement** | `if (x > 0) { ... }` | `if x > 0:` |
| **For loop** | `for (int i=0; i<n; i++)` | `for i in range(n):` |
| **While loop** | `while (x > 0) { ... }` | `while x > 0:` |
| **Function** | `int add(int a, int b) { return a+b; }` | `def add(a, b): return a + b` |
| **Null/None** | `NULL` or `nullptr` | `None` |
| **Boolean** | `true`, `false` | `True`, `False` |
| **And/Or** | `&&`, `||` | `and`, `or` |
| **Not** | `!` | `not` |

### Control Flow

**C++:**
```cpp
if (x > 0) {
    cout << "positive" << endl;
} else if (x < 0) {
    cout << "negative" << endl;
} else {
    cout << "zero" << endl;
}
```

**Python:**
```python
if x > 0:
    print("positive")
elif x < 0:
    print("negative")
else:
    print("zero")
```

### Loops

**C++:**
```cpp
// Traditional for loop
for (int i = 0; i < n; i++) {
    cout << i << endl;
}

// Range-based for loop
for (int num : nums) {
    cout << num << endl;
}

// While loop
while (i < n) {
    i++;
}
```

**Python:**
```python
# For loop with range
for i in range(n):
    print(i)

# For loop over list
for num in nums:
    print(num)

# While loop
while i < n:
    i += 1
```

### Functions

**C++:**
```cpp
class Solution {
public:
    int add(int a, int b) {
        return a + b;
    }

    void helper(vector<int>& nums, int index) {
        // void function
    }
};
```

**Python:**
```python
class Solution:
    def add(self, a: int, b: int) -> int:
        return a + b

    def helper(self, nums: List[int], index: int) -> None:
        # void equivalent
        pass
```

---

## 🗂️ Data Structures Mapping

### 1. Arrays/Vectors → Lists

**C++:**
```cpp
#include <vector>

vector<int> nums;
vector<int> nums(10);           // Size 10, initialized to 0
vector<int> nums(10, 5);        // Size 10, all elements = 5
vector<int> nums = {1, 2, 3};

nums.push_back(4);              // Add to end
nums.pop_back();                // Remove from end
int size = nums.size();
int first = nums[0];
int last = nums[nums.size()-1];

// 2D array
vector<vector<int>> matrix(m, vector<int>(n, 0));
```

**Python:**
```python
nums = []
nums = [0] * 10                 # Size 10, all zeros
nums = [5] * 10                 # Size 10, all 5s
nums = [1, 2, 3]

nums.append(4)                  # Add to end
nums.pop()                      # Remove from end
size = len(nums)
first = nums[0]
last = nums[-1]                 # Negative indexing!

# 2D array
matrix = [[0] * n for _ in range(m)]
# OR
matrix = [[0 for _ in range(n)] for _ in range(m)]
```

**Python List Slicing (Powerful!):**
```python
nums = [0, 1, 2, 3, 4, 5]

nums[1:4]       # [1, 2, 3] - elements at index 1,2,3
nums[:3]        # [0, 1, 2] - first 3 elements
nums[3:]        # [3, 4, 5] - from index 3 to end
nums[-2:]       # [4, 5] - last 2 elements
nums[::2]       # [0, 2, 4] - every 2nd element
nums[::-1]      # [5, 4, 3, 2, 1, 0] - REVERSE!
```

### 2. Unordered Map → Dictionary

**C++:**
```cpp
#include <unordered_map>

unordered_map<int, int> freq;
unordered_map<string, int> mp;

// Insert/Update
freq[key] = value;
freq[nums[i]]++;

// Check existence
if (freq.find(key) != freq.end()) {
    // key exists
}

// Get value with default
int val = freq.count(key) ? freq[key] : 0;

// Iterate
for (auto& pair : freq) {
    int key = pair.first;
    int val = pair.second;
}
```

**Python:**
```python
freq = {}
mp = {}

# Insert/Update
freq[key] = value
freq[nums[i]] = freq.get(nums[i], 0) + 1  # Safe increment

# Check existence
if key in freq:
    # key exists

# Get value with default
val = freq.get(key, 0)

# Iterate
for key, val in freq.items():
    print(key, val)

# Or just keys
for key in freq:
    print(key)

# Or just values
for val in freq.values():
    print(val)
```

**Using Counter (Better for frequency!):**
```python
from collections import Counter

# Automatic frequency counting
freq = Counter(nums)              # Counter({2: 3, 1: 2, 3: 1})
freq = Counter("hello")           # Counter({'l': 2, 'h': 1, 'e': 1, 'o': 1})

# Most common elements
freq.most_common(2)               # Returns [(2, 3), (1, 2)]
```

**Using defaultdict (Auto-initialize!):**
```python
from collections import defaultdict

# Auto-create lists
graph = defaultdict(list)
graph[1].append(2)                # No need to check if key exists!

# Auto-create ints (for counting)
freq = defaultdict(int)
freq[nums[i]] += 1                # No need for get()

# Auto-create sets
groups = defaultdict(set)
groups[key].add(value)
```

### 3. Unordered Set → Set

**C++:**
```cpp
#include <unordered_set>

unordered_set<int> seen;

seen.insert(5);
seen.erase(5);
if (seen.find(5) != seen.end()) {
    // exists
}
int size = seen.size();

// Iterate
for (int num : seen) {
    cout << num << endl;
}
```

**Python:**
```python
seen = set()

seen.add(5)
seen.remove(5)          # Throws error if not exists
seen.discard(5)         # Safe - no error if not exists
if 5 in seen:
    # exists
size = len(seen)

# Iterate
for num in seen:
    print(num)

# Set operations
set1 & set2             # Intersection
set1 | set2             # Union
set1 - set2             # Difference
set1 ^ set2             # Symmetric difference
```

### 4. Queue → deque

**C++:**
```cpp
#include <queue>

queue<int> q;
queue<TreeNode*> q;

q.push(5);
int front = q.front();
q.pop();
bool empty = q.empty();
int size = q.size();
```

**Python:**
```python
from collections import deque

q = deque()
q = deque([1, 2, 3])    # Initialize with list

q.append(5)             # Add to right
front = q[0]            # Peek front (or q.popleft() without assignment)
q.popleft()             # Remove from left - O(1)!
empty = len(q) == 0
size = len(q)

# Can also use as stack
q.append(5)             # Push
q.pop()                 # Pop from right
```

**Why deque instead of list?**
- `list.pop(0)` is O(n) - slow!
- `deque.popleft()` is O(1) - fast!

### 5. Stack → List

**C++:**
```cpp
#include <stack>

stack<int> stk;
stack<char> stk;

stk.push(5);
int top = stk.top();
stk.pop();
bool empty = stk.empty();
int size = stk.size();
```

**Python:**
```python
stk = []

stk.append(5)           # Push
top = stk[-1]           # Peek top
stk.pop()               # Pop
empty = len(stk) == 0
size = len(stk)
```

### 6. Priority Queue → heapq

**C++:**
```cpp
#include <queue>

// Min heap (reversed: greater)
priority_queue<int, vector<int>, greater<int>> min_heap;

// Max heap (default)
priority_queue<int> max_heap;

min_heap.push(5);
int top = min_heap.top();
min_heap.pop();
int size = min_heap.size();
```

**Python:**
```python
import heapq

# Min heap (default in Python!)
min_heap = []
heapq.heappush(min_heap, 5)
top = min_heap[0]                    # Peek
smallest = heapq.heappop(min_heap)   # Pop
size = len(min_heap)

# Initialize from list
nums = [3, 1, 4, 1, 5]
heapq.heapify(nums)                  # In-place O(n)

# Max heap - negate values!
max_heap = []
heapq.heappush(max_heap, -5)         # Push -5
largest = -heapq.heappop(max_heap)   # Pop and negate

# Or heapify with negation
nums = [3, 1, 4, 1, 5]
max_heap = [-x for x in nums]
heapq.heapify(max_heap)

# For tuples - sorts by first element, then second, etc.
heapq.heappush(min_heap, (priority, value))
```

### 7. Map (Ordered) → OrderedDict or dict (Python 3.7+)

**C++:**
```cpp
#include <map>

map<int, int> ordered;
ordered[5] = 10;

// Lower bound
auto it = ordered.lower_bound(5);
```

**Python:**
```python
# Python 3.7+ dicts are ordered by insertion!
ordered = {}
ordered[5] = 10

# For explicit ordering
from collections import OrderedDict
ordered = OrderedDict()
ordered[5] = 10

# For sorted operations, use sorted()
keys = sorted(ordered.keys())
```

### 8. String Operations

**C++:**
```cpp
#include <string>

string s = "hello";
s.length();                    // or s.size()
s.substr(1, 3);                // "ell" - start, length
s.push_back('!');              // "hello!"
s.pop_back();                  // "hello"
s[0] = 'H';                    // "Hello"

// Concatenation
string result = s1 + s2;

// To int
int num = stoi("123");
long num = stol("123456789");

// To string
string s = to_string(123);

// Find
size_t pos = s.find("ll");     // 2
if (pos != string::npos) { ... }

// Compare
if (s1 == s2) { ... }

// Character check
isdigit('5');
isalpha('a');
tolower('A');
toupper('a');
```

**Python:**
```python
s = "hello"
len(s)                         # Length
s[1:4]                         # "ell" - slicing!
s += '!'                       # "hello!" (strings are immutable, creates new)
s = s[:-1]                     # "hello" - remove last char
# Can't do s[0] = 'H' - strings immutable!
s = 'H' + s[1:]                # "Hello"

# Concatenation
result = s1 + s2

# To int
num = int("123")

# To string
s = str(123)

# Find
pos = s.find("ll")             # 2
if pos != -1: ...              # -1 means not found

# In operator (better!)
if "ll" in s: ...

# Compare
if s1 == s2: ...

# Character check
'5'.isdigit()
'a'.isalpha()
'A'.lower()
'a'.upper()

# Split and join
words = s.split()              # Split by whitespace
words = s.split(',')           # Split by comma
result = ' '.join(words)       # Join with space
result = ','.join(words)       # Join with comma

# Strip whitespace
s = "  hello  ".strip()        # "hello"
s = "  hello  ".lstrip()       # "hello  "
s = "  hello  ".rstrip()       # "  hello"

# Replace
s = "hello".replace('l', 'L')  # "heLLo"

# Reverse
s = "hello"[::-1]              # "olleh"
```

### 9. Pair and Tuple

**C++:**
```cpp
#include <utility>

pair<int, int> p = make_pair(1, 2);
pair<int, int> p = {1, 2};
int first = p.first;
int second = p.second;

// Vector of pairs
vector<pair<int, int>> pairs;
pairs.push_back({1, 2});
```

**Python:**
```python
# Tuple (immutable)
p = (1, 2)
first = p[0]
second = p[1]

# Or tuple unpacking
first, second = p
first, second = (1, 2)

# List of tuples
pairs = []
pairs.append((1, 2))

# Or list of lists (mutable)
pairs = []
pairs.append([1, 2])
```

---

## 💡 Real Problem Conversions

### Example 1: Two Sum

**C++ Solution:**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
    }
};
```

**Python Solution:**
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
        return []  # No solution found
```

**Key Differences:**
- No type declarations
- `enumerate()` gives (index, value) pairs - cleaner than C++ loop
- `in` operator instead of `find()`
- List comprehension potential: `return [seen[complement], i]` is cleaner
- Implicit return type

### Example 2: Binary Tree Level Order Traversal

**C++ Solution (Iterative):**
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> curr, next;
        vector<int> level;
        curr.push(root);
        while(!curr.empty()){
            while(!curr.empty()){
                TreeNode* node = curr.front();
                curr.pop();
                level.push_back(node->val);
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(next, curr);
        }
        return result;
    }
};
```

**Python Solution:**
```python
from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            level = []
            level_size = len(queue)

            for _ in range(level_size):
                node = queue.popleft()
                level.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(level)

        return result
```

**Key Differences:**
- `deque` from collections (better than list for queue)
- `not root` instead of `root == NULL`
- Cleaner level-by-level processing with `len(queue)`
- No need for two queues - use queue size!
- `Optional[TreeNode]` type hint

### Example 3: Group Anagrams

**C++ Solution:**
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string s1 = s;
            sort(s1.begin(), s1.end());
            mp[s1].push_back(s);
        }
        for(auto pair: mp){
            res.push_back(pair.second);
        }
        return res;
    }
};
```

**Python Solution:**
```python
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        for s in strs:
            # Sort string as key
            key = ''.join(sorted(s))
            groups[key].append(s)

        return list(groups.values())
```

**Even More Pythonic:**
```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for s in strs:
            key = tuple(sorted(s))  # Tuple is hashable
            groups[key] = groups.get(key, []) + [s]
        return list(groups.values())
```

**One-liner (not recommended for interviews, but cool!):**
```python
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        [groups[''.join(sorted(s))].append(s) for s in strs]
        return list(groups.values())
```

**Key Differences:**
- `defaultdict(list)` - no need to check if key exists!
- `sorted(s)` returns a list, join it: `''.join(sorted(s))`
- `groups.values()` - cleaner extraction
- Can use tuple as key: `tuple(sorted(s))`

### Example 4: Climbing Stairs (DP)

**C++ Solution:**
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1) return 1;
        int a=1, b=1;
        int ans;
        for (int i=2; i<=n; i++) {
            ans = a + b;
            b = a;
            a = ans;
        }
        return ans;
    }
};
```

**Python Solution:**
```python
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1

        a, b = 1, 1
        for _ in range(2, n + 1):
            a, b = b, a + b

        return b
```

**Key Differences:**
- Multiple assignment: `a, b = b, a + b` (simultaneous update!)
- No need for temp variable `ans`
- `range(2, n + 1)` instead of `i=2; i<=n; i++`
- Can use `_` when loop variable not needed

### Example 5: Reverse Linked List

**C++ Solution (Iterative):**
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        while(head && head->next){
            ListNode* swapNode = head->next;
            ListNode* nextNode = head->next->next;
            swapNode->next = dummy->next;
            dummy->next = swapNode;
            head->next = nextNode;
        }
        return dummy->next;
    }
};
```

**Python Solution (Simple Iterative):**
```python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        return prev
```

**Python Solution (More Pythonic with tuple unpacking):**
```python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr:
            curr.next, prev, curr = prev, curr, curr.next

        return prev
```

**Python Solution (Recursive):**
```python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None

        return new_head
```

**Key Differences:**
- No manual memory management (`new`/`delete`)
- Tuple unpacking for elegant swaps
- `not head` instead of `head == nullptr`
- Cleaner recursive solution

### Example 6: Number of Islands (DFS)

**C++ Solution:**
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid){
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1') dfs(grid, i-1, j);
        if(i < grid.size()-1 && grid[i+1][j] == '1') dfs(grid, i+1, j);
        if(j > 0 && grid[i][j-1] == '1') dfs(grid, i, j-1);
        if(j < grid[0].size()-1 && grid[i][j+1] == '1') dfs(grid, i, j+1);
    }
};
```

**Python Solution:**
```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0

        rows, cols = len(grid), len(grid[0])
        count = 0

        def dfs(i, j):
            if i < 0 or i >= rows or j < 0 or j >= cols or grid[i][j] == '0':
                return

            grid[i][j] = '0'  # Mark as visited

            # Visit all 4 neighbors
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    count += 1
                    dfs(i, j)

        return count
```

**Python Solution (Using directions array):**
```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        count = 0
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def dfs(i, j):
            grid[i][j] = '0'

            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < rows and 0 <= nj < cols and grid[ni][nj] == '1':
                    dfs(ni, nj)

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    count += 1
                    dfs(i, j)

        return count
```

**Key Differences:**
- Nested function `dfs` inside main function (cleaner scope)
- Multiple unpacking: `rows, cols = len(grid), len(grid[0])`
- Cleaner boundary checking with `if 0 <= ni < rows`
- Directions array for cleaner neighbor iteration
- No separate private method needed

---

## 🎯 Common Patterns

### Pattern 1: Two Pointers

**C++:**
```cpp
int left = 0, right = nums.size() - 1;
while (left < right) {
    if (nums[left] + nums[right] == target) {
        return {left, right};
    } else if (nums[left] + nums[right] < target) {
        left++;
    } else {
        right--;
    }
}
```

**Python:**
```python
left, right = 0, len(nums) - 1
while left < right:
    current_sum = nums[left] + nums[right]
    if current_sum == target:
        return [left, right]
    elif current_sum < target:
        left += 1
    else:
        right -= 1
```

### Pattern 2: Sliding Window

**C++:**
```cpp
unordered_map<char, int> window;
int left = 0, right = 0;
int maxLen = 0;

while (right < s.length()) {
    char c = s[right];
    window[c]++;
    right++;

    while (window.size() > k) {
        char leftChar = s[left];
        window[leftChar]--;
        if (window[leftChar] == 0) {
            window.erase(leftChar);
        }
        left++;
    }

    maxLen = max(maxLen, right - left);
}
```

**Python:**
```python
from collections import defaultdict

window = defaultdict(int)
left = 0
max_len = 0

for right, char in enumerate(s):
    window[char] += 1

    while len(window) > k:
        window[s[left]] -= 1
        if window[s[left]] == 0:
            del window[s[left]]
        left += 1

    max_len = max(max_len, right - left + 1)
```

**Or with Counter:**
```python
from collections import Counter

window = Counter()
left = 0
max_len = 0

for right in range(len(s)):
    window[s[right]] += 1

    while len(window) > k:
        window[s[left]] -= 1
        if window[s[left]] == 0:
            del window[s[left]]
        left += 1

    max_len = max(max_len, right - left + 1)
```

### Pattern 3: Binary Search

**C++:**
```cpp
int left = 0, right = nums.size() - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return -1;
```

**Python:**
```python
left, right = 0, len(nums) - 1

while left <= right:
    mid = (left + right) // 2  # // is integer division

    if nums[mid] == target:
        return mid
    elif nums[mid] < target:
        left = mid + 1
    else:
        right = mid - 1

return -1
```

**Using bisect module:**
```python
import bisect

# Find insertion point
idx = bisect.bisect_left(nums, target)

# Check if target exists
if idx < len(nums) and nums[idx] == target:
    return idx
return -1
```

### Pattern 4: BFS

**C++:**
```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();

        // Process node

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

**Python:**
```python
from collections import deque

queue = deque([root])

while queue:
    level_size = len(queue)

    for _ in range(level_size):
        node = queue.popleft()

        # Process node

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
```

### Pattern 5: DFS with Backtracking

**C++:**
```cpp
void backtrack(vector<int>& nums, vector<int>& path,
               vector<vector<int>>& result, int start) {
    result.push_back(path);

    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(nums, path, result, i + 1);
        path.pop_back();
    }
}
```

**Python:**
```python
def backtrack(start, path):
    result.append(path[:])  # Copy path!

    for i in range(start, len(nums)):
        path.append(nums[i])
        backtrack(i + 1, path)
        path.pop()

result = []
backtrack(0, [])
return result
```

**Or more Pythonic:**
```python
def backtrack(start, path):
    result.append(path)

    for i in range(start, len(nums)):
        backtrack(i + 1, path + [nums[i]])  # Creates new list!

result = []
backtrack(0, [])
return result
```

### Pattern 6: Dynamic Programming

**C++ (2D DP):**
```cpp
vector<vector<int>> dp(m, vector<int>(n, 0));

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
            dp[i][j] = grid[i][j];
        } else if (i == 0) {
            dp[i][j] = dp[i][j-1] + grid[i][j];
        } else if (j == 0) {
            dp[i][j] = dp[i-1][j] + grid[i][j];
        } else {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
}
```

**Python:**
```python
# Initialize DP table
dp = [[0] * n for _ in range(m)]

for i in range(m):
    for j in range(n):
        if i == 0 and j == 0:
            dp[i][j] = grid[i][j]
        elif i == 0:
            dp[i][j] = dp[i][j-1] + grid[i][j]
        elif j == 0:
            dp[i][j] = dp[i-1][j] + grid[i][j]
        else:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

return dp[m-1][n-1]
```

**Space optimized (1D DP):**
```python
# Only need previous row
dp = [0] * n

for i in range(m):
    new_dp = [0] * n
    for j in range(n):
        if i == 0 and j == 0:
            new_dp[j] = grid[i][j]
        elif i == 0:
            new_dp[j] = new_dp[j-1] + grid[i][j]
        elif j == 0:
            new_dp[j] = dp[j] + grid[i][j]
        else:
            new_dp[j] = min(dp[j], new_dp[j-1]) + grid[i][j]
    dp = new_dp

return dp[n-1]
```

---

## 🪄 Python-Specific Tricks

### List Comprehensions (Very Important!)

**Instead of loops:**
```python
# C++ style
result = []
for i in range(10):
    result.append(i * i)

# Python style
result = [i * i for i in range(10)]

# With condition
evens = [x for x in nums if x % 2 == 0]

# 2D list
matrix = [[0 for _ in range(n)] for _ in range(m)]

# Flatten 2D list
flattened = [num for row in matrix for num in row]
```

### Dictionary Comprehensions

```python
# Create dict from list
squares = {x: x*x for x in range(5)}
# {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

# Invert dict
inverted = {v: k for k, v in original.items()}

# With condition
filtered = {k: v for k, v in d.items() if v > 10}
```

### Set Comprehensions

```python
unique_squares = {x*x for x in nums}
```

### Enumerate (Index + Value)

```python
# Instead of
for i in range(len(nums)):
    print(i, nums[i])

# Use
for i, num in enumerate(nums):
    print(i, num)

# With start index
for i, num in enumerate(nums, start=1):
    print(i, num)  # 1-indexed
```

### Zip (Iterate Multiple Lists)

```python
names = ['Alice', 'Bob', 'Charlie']
scores = [85, 90, 78]

for name, score in zip(names, scores):
    print(f"{name}: {score}")

# Create dict from two lists
d = dict(zip(names, scores))
```

### Any and All

```python
# Check if any element satisfies condition
if any(x > 10 for x in nums):
    print("At least one element > 10")

# Check if all elements satisfy condition
if all(x > 0 for x in nums):
    print("All elements positive")

# Instead of
has_positive = False
for num in nums:
    if num > 0:
        has_positive = True
        break
```

### Multiple Assignment

```python
# Swap without temp
a, b = b, a

# Multiple variables
x, y, z = 1, 2, 3

# Unpack list
first, second, *rest = [1, 2, 3, 4, 5]
# first=1, second=2, rest=[3,4,5]

first, *middle, last = [1, 2, 3, 4, 5]
# first=1, middle=[2,3,4], last=5
```

### Default Values with get()

```python
# Instead of
if key in freq:
    freq[key] += 1
else:
    freq[key] = 1

# Use
freq[key] = freq.get(key, 0) + 1
```

### Ternary Operator

```python
# C++: int result = (x > 0) ? 1 : -1;
result = 1 if x > 0 else -1

# Common use
max_val = a if a > b else b
```

### String Multiplication

```python
"*" * 10           # "**********"
[0] * 5            # [0, 0, 0, 0, 0]
```

### F-strings (Formatted Strings)

```python
name = "Alice"
age = 25

# Old way
print("Name: " + name + ", Age: " + str(age))

# F-string (Python 3.6+)
print(f"Name: {name}, Age: {age}")

# With expressions
print(f"Next year: {age + 1}")

# With formatting
pi = 3.14159
print(f"Pi: {pi:.2f}")  # "Pi: 3.14"
```

### Lambda Functions

```python
# Sort by custom key
intervals.sort(key=lambda x: x[0])

# Sort by multiple keys
people.sort(key=lambda x: (x[1], -x[0]))  # By age asc, height desc

# Map
squared = list(map(lambda x: x*x, nums))

# Filter
evens = list(filter(lambda x: x % 2 == 0, nums))
```

### Max/Min with Key

```python
words = ["apple", "pie", "zoo", "a"]

# Longest word
longest = max(words, key=len)  # "apple"

# Custom key
intervals = [[1,3], [2,6], [8,10]]
earliest = min(intervals, key=lambda x: x[0])  # [1,3]
```

### Infinity

```python
# Instead of INT_MAX, INT_MIN
min_val = float('inf')
max_val = float('-inf')

# Use in comparisons
if distance < float('inf'):
    # ...
```

### Multiple Conditions in One Line

```python
# Check range
if 0 <= i < n and 0 <= j < m:
    # ...

# Multiple comparisons
if a < b < c:  # Same as: a < b and b < c
    # ...
```

---

## 📅 Week-by-Week Learning Plan

### Week 1: Python Fundamentals

**Day 1: Basic Syntax (2 hours)**
- Variables, loops, if/else
- Functions and return statements
- Print and input
- **Practice**: Convert 3 simple array problems

**Day 2: Lists and Strings (2 hours)**
- List operations (append, pop, slicing)
- String operations (split, join, slicing)
- List comprehensions
- **Practice**: Convert 5 array/string problems

**Day 3: Dictionaries and Sets (2 hours)**
- Dictionary operations
- Set operations
- Counter and defaultdict
- **Practice**: Convert 5 hash table problems

**Day 4: Collections Module (2 hours)**
- deque for queues
- Counter for frequency
- defaultdict for grouping
- **Practice**: Convert 3 BFS problems

**Day 5: Heapq and Sorting (2 hours)**
- heapq for priority queue
- sorted() and sort()
- Custom sort keys
- **Practice**: Convert 3 heap problems

**Day 6: Practice Day (3 hours)**
- Convert 10 problems from different categories
- Focus on clean, Pythonic code
- Time yourself

**Day 7: Review and Consolidate (2 hours)**
- Review all converted problems
- Note patterns and tricks
- Create personal cheat sheet

### Week 2: Advanced Patterns

**Day 8: Tree Traversals (2 hours)**
- DFS (recursion vs iteration)
- BFS with queue
- **Practice**: Convert 5 tree problems

**Day 9: Backtracking (2 hours)**
- DFS with backtracking
- Combinations/permutations
- **Practice**: Convert 3 backtracking problems

**Day 10: Dynamic Programming (2 hours)**
- 1D and 2D DP
- Space optimization
- **Practice**: Convert 5 DP problems

**Day 11: Binary Search (2 hours)**
- Standard binary search
- bisect module
- **Practice**: Convert 3 binary search problems

**Day 12: Graph Algorithms (2 hours)**
- DFS and BFS on graphs
- Topological sort
- **Practice**: Convert 3 graph problems

**Day 13: Mixed Practice (3 hours)**
- Solve 10 new problems in Python
- Focus on speed and accuracy
- Time yourself strictly

**Day 14: Mock Interview (2 hours)**
- Simulate real interview
- 2-3 medium problems
- Explain code out loud

### Week 3+: Mastery and Speed

**Daily (1-2 hours):**
- Solve 2-3 new LeetCode problems in Python
- Review 2-3 old C++ solutions and convert
- Focus on:
  - Writing clean code
  - Explaining approach
  - Optimizing time/space
  - Edge cases

**Weekly:**
- 1 mock interview (90 min)
- Review weak areas
- Practice explaining solutions

---

## ✅ Conversion Checklist

When converting C++ to Python, remember:

- [ ] Remove all type declarations
- [ ] Change `NULL`/`nullptr` to `None`
- [ ] Use `not` instead of `!`
- [ ] Use `and`/`or` instead of `&&`/`||`
- [ ] Change `vector<int>` to `List[int]` (type hint)
- [ ] Use `len()` instead of `.size()`
- [ ] Use `in` for membership testing
- [ ] Use `enumerate()` for index+value loops
- [ ] Use list slicing instead of substr/subarray
- [ ] Use `deque` for queues (not list)
- [ ] Use `heapq` for priority queues
- [ ] Use `defaultdict` or `Counter` for hashmaps
- [ ] Use list comprehensions where appropriate
- [ ] Use tuple unpacking for swaps
- [ ] Use `range()` for loops
- [ ] Remove manual memory management
- [ ] Use f-strings for string formatting
- [ ] Use `//` for integer division
- [ ] Use `**` for exponentiation
- [ ] Use `float('inf')` for infinity

---

## 🎓 Tips for Success

1. **Start simple**: Don't try to be too "Pythonic" at first
2. **Run code often**: Use Python REPL to test snippets
3. **Read others' solutions**: Learn from clean Python code on LeetCode
4. **Use type hints**: Helps catch errors (optional but recommended)
5. **Practice explaining**: Say your approach out loud
6. **Time yourself**: Aim to be faster than your C++ solutions
7. **Don't overthink**: Simple, readable code > clever one-liners
8. **Test edge cases**: None, empty list, single element, etc.
9. **Use debugger**: Python has great debugging tools
10. **Have fun!**: Python should feel liberating after C++

---

## 📚 Resources

### Online Practice
- [LeetCode](https://leetcode.com) - Main practice platform
- [Python Tutor](http://pythontutor.com) - Visualize code execution
- [Real Python](https://realpython.com) - Tutorials and guides

### Documentation
- [Python Official Docs](https://docs.python.org/3/)
- [Python Collections](https://docs.python.org/3/library/collections.html)
- [Python heapq](https://docs.python.org/3/library/heapq.html)

### Quick References
- [Python Cheat Sheet](https://www.pythoncheatsheet.org/)
- [LeetCode Python Tips](https://leetcode.com/discuss/general-discussion/460599/blind-75-leetcode-questions)

---

## 🎯 Quick Reference: C++ to Python

| Category | C++ | Python |
|----------|-----|--------|
| **Array** | `vector<int> v` | `v = []` or `v = [1,2,3]` |
| **Size** | `v.size()` | `len(v)` |
| **Add** | `v.push_back(x)` | `v.append(x)` |
| **Remove** | `v.pop_back()` | `v.pop()` |
| **Hash Map** | `unordered_map<int,int>` | `dict` or `defaultdict` |
| **Hash Set** | `unordered_set<int>` | `set()` |
| **Queue** | `queue<int>` | `deque()` |
| **Stack** | `stack<int>` | `list` (use as stack) |
| **Heap** | `priority_queue` | `heapq` |
| **Null** | `NULL` or `nullptr` | `None` |
| **Boolean** | `true`, `false` | `True`, `False` |
| **And/Or** | `&&`, `||` | `and`, `or` |
| **Not** | `!` | `not` |
| **Loop** | `for(int i=0; i<n; i++)` | `for i in range(n):` |
| **For each** | `for(int x: v)` | `for x in v:` |
| **String substr** | `s.substr(i, len)` | `s[i:i+len]` |
| **Reverse** | `reverse(v.begin(), v.end())` | `v[::-1]` or `reversed(v)` |
| **Sort** | `sort(v.begin(), v.end())` | `v.sort()` or `sorted(v)` |
| **Min/Max** | `min(a, b)`, `max(a, b)` | `min(a, b)`, `max(a, b)` |
| **Swap** | `swap(a, b)` | `a, b = b, a` |
| **To string** | `to_string(n)` | `str(n)` |
| **To int** | `stoi(s)` | `int(s)` |
| **Infinity** | `INT_MAX`, `INT_MIN` | `float('inf')`, `float('-inf')` |
| **Division** | `a / b` (int div) | `a // b` (int div), `a / b` (float) |
| **Power** | `pow(a, b)` | `a ** b` or `pow(a, b)` |

---

**Good luck with your Python learning journey! 🚀**

Remember: The goal is not to become a Python expert, but to be comfortable enough to solve interview problems efficiently. Focus on clarity and correctness first, optimization second, and Pythonic elegance last.
