# 📚 C++ Coding Interview Study & Review Plan

## 📊 Repository Overview

**Total Problems: 406 C++ Solutions**

| Category | File Count | Percentage |
|----------|-----------|------------|
| Array & String | 92 | 22.7% |
| BackTracking & DFS & BFS | 63 | 15.6% |
| Tree | 44 | 10.9% |
| Dynamic Programming | 40 | 9.9% |
| Math & Bit Manipulation | 35 | 8.6% |
| HashTable | 26 | 6.4% |
| Stack & Queue & Heap | 22 | 5.4% |
| Binary Search | 20 | 4.9% |
| Design | 18 | 4.4% |
| LinkedList | 16 | 4.0% |
| Trie | 6 | 1.5% |
| Intervals | 5 | 1.2% |
| SpecialTopics | 5 | 1.2% |
| Divide And Conquer | 4 | 1.0% |
| SegmentTree | 4 | 1.0% |
| Range Query & Segment Tree | 3 | 0.7% |
| UnionFind | 2 | 0.5% |
| Greedy | 1 | 0.2% |

---

## 🗓️ 6-Week Study Plan

### **Phase 1: Foundation Review (Week 1-2)**

#### Week 1: Core Data Structures
- **Day 1-2**: Vector & Array manipulation
  - Review 15-20 problems from Array & String
  - Focus: two pointers, sliding window, prefix sum
- **Day 3-4**: HashTable (map/unordered_map/set)
  - Review HashTable folder (26 files)
  - Focus: frequency counting, anagrams, prefix problems
- **Day 5-6**: String manipulation
  - Review string-heavy problems in Array & String
  - Focus: parsing, pattern matching, substring
- **Day 7**: Stack & Queue basics
  - Review first 10 problems from Stack & Queue & Heap

#### Week 2: Advanced Containers & Algorithms
- **Day 8-9**: Stack applications
  - Calculator problems, parentheses, monotonic stack
- **Day 10-11**: Priority Queue (Heap)
  - K-th element problems, merge problems
- **Day 12-13**: Binary Search
  - Review all 20 Binary Search problems
  - Master upper_bound/lower_bound
- **Day 14**: Review & practice mixing techniques

### **Phase 2: Tree & Graph (Week 3-4)**

#### Week 3: Tree Mastery
- **Day 15-16**: Tree traversals
  - Pre/in/post-order (recursive & iterative)
  - Level-order traversal
- **Day 17-18**: BST operations
  - Validation, search, insert, delete
- **Day 19-20**: Advanced tree problems
  - LCA, serialize/deserialize, path problems
- **Day 21**: Trie (6 problems)

#### Week 4: Graph & BFS/DFS
- **Day 22-23**: BFS patterns
  - Level-order, shortest path, topological sort
- **Day 24-25**: DFS patterns
  - Path finding, cycle detection, connected components
- **Day 26-27**: Backtracking
  - Combination, permutation, word search
- **Day 28**: UnionFind (2 problems)

### **Phase 3: Dynamic Programming (Week 5)**

- **Day 29-30**: 1D DP
  - Climbing stairs, house robber, decode ways
- **Day 31-32**: 2D DP
  - Grid problems, LCS, edit distance
- **Day 33-34**: Advanced DP
  - Knapsack, partition, stock problems
- **Day 35**: DP optimization techniques

### **Phase 4: Special Topics (Week 6)**

- **Day 36**: Intervals (5 problems)
- **Day 37**: Math & Bit Manipulation (35 problems - select 15)
- **Day 38**: Segment Tree & Range Query (7 problems)
- **Day 39**: Divide and Conquer (4 problems)
- **Day 40**: Design problems (18 problems)
- **Day 41**: Greedy (review greedy patterns across categories)
- **Day 42**: Final review & weak areas

### **Daily Study Structure (2-3 hours)**
1. **Review phase (30 min)**: Re-read previous solutions, note patterns
2. **Solve phase (90 min)**: Attempt 2-4 problems without looking at solutions
3. **Analysis phase (30 min)**: Compare with your old solutions, optimize

---

## 🔑 Key C++ Data Structure Skills

### **1. Essential STL Containers**

```cpp
// Vector - Dynamic arrays (95% of problems)
vector<int> nums;                          // 1D array
vector<vector<int>> matrix;                // 2D array
vector<bool> visited;                      // Boolean flags

// HashMap - O(1) lookups (60% of problems)
unordered_map<int, int> freq;              // Frequency counting
unordered_map<string, vector<string>> mp;  // Grouping

// Queue - BFS, level-order (30%)
queue<TreeNode*> q;                        // Tree traversal
queue<pair<int,int>> q;                    // Grid BFS

// Stack - DFS, expression eval (25%)
stack<char> stk;                           // Parentheses
stack<int> mono_stk;                       // Monotonic stack

// Priority Queue - Heap operations (20%)
priority_queue<int> max_heap;              // Max heap (default)
priority_queue<int, vector<int>, greater<int>> min_heap;

// Set - Ordered unique elements (15%)
set<int> ordered_set;                      // BST-based
unordered_set<int> hash_set;               // Hash-based

// Map - Ordered key-value (10%)
map<int, int> ordered_map;                 // When order matters

// Deque - Double-ended queue (5%)
deque<int> dq;                             // Sliding window max

// List - Doubly linked list (3%)
list<pair<int,int>> cache;                 // LRU cache
```

### **2. Critical STL Algorithms**

```cpp
// Sorting (extremely common)
sort(vec.begin(), vec.end());
sort(vec.begin(), vec.end(), greater<int>());
sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });

// Binary search family
lower_bound(vec.begin(), vec.end(), target);  // First >= target
upper_bound(vec.begin(), vec.end(), target);  // First > target
binary_search(vec.begin(), vec.end(), target);

// Min/Max operations
max(a, b);
min(a, b);
*max_element(vec.begin(), vec.end());
*min_element(vec.begin(), vec.end());

// Other utilities
reverse(vec.begin(), vec.end());
next_permutation(vec.begin(), vec.end());
swap(a, b);
```

### **3. String Mastery**

```cpp
// Construction & manipulation
string s = "hello";
s.substr(start, len);                      // Substring
s.length() / s.size();                     // Length
s.push_back('c');                          // Append char
s.pop_back();                              // Remove last

// Conversion
to_string(123);                            // int -> string
stoi("123");                               // string -> int
stol("123456789012");                      // string -> long

// Parsing
istringstream iss(s);
getline(iss, word, ' ');                   // Split by delimiter

// Character operations
isdigit(c), isalpha(c), islower(c), isupper(c)
tolower(c), toupper(c)
c - 'a'  // Map to 0-25
```

### **4. Pointer Techniques**

```cpp
// Custom nodes
struct TreeNode { int val; TreeNode *left, *right; };
struct ListNode { int val; ListNode *next; };

// Two pointers
int left = 0, right = n - 1;
while (left < right) { ... }

// Fast/slow pointers (cycle detection)
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}

// Dummy node technique
ListNode* dummy = new ListNode(0);
dummy->next = head;
```

### **5. Bit Manipulation Essentials**

```cpp
// Basic operations
n & 1                 // Check if odd
n & (n-1)             // Remove rightmost 1 bit
1 << i                // 2^i
n >> 1                // Divide by 2
n << 1                // Multiply by 2

// Common tricks
n ^ n = 0             // XOR same number = 0
n ^ 0 = n             // XOR with 0 = itself
n & (n-1) == 0        // Check power of 2
```

### **6. Custom Comparators**

```cpp
// Function comparator
static bool comp(const Interval& a, const Interval& b) {
    return a.start < b.start;
}
sort(intervals.begin(), intervals.end(), comp);

// Struct comparator for priority_queue
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min heap
    }
};
priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

// Lambda (C++11)
auto cmp = [](int a, int b) { return a > b; };
sort(vec.begin(), vec.end(), cmp);
```

### **7. DP Table Initialization**

```cpp
// 1D DP
vector<int> dp(n, 0);
vector<int> dp(n, INT_MAX);

// 2D DP
vector<vector<int>> dp(m, vector<int>(n, 0));
vector<vector<bool>> visited(m, vector<bool>(n, false));

// Space optimization
int prev = 0, curr = 0;
vector<int> prev_row(n), curr_row(n);
```

---

## 🎯 Common Algorithm Patterns

### **Sliding Window Pattern**

```cpp
unordered_map<char, int> window;
int left = 0, right = 0;
while (right < s.length()) {
    window[s[right]]++;
    while (/* window invalid */) {
        window[s[left]]--;
        left++;
    }
    // Update result
    right++;
}
```

### **BFS Template**

```cpp
queue<Node*> q;
q.push(start);
while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        Node* curr = q.front();
        q.pop();
        // Process current node
        // Add neighbors to queue
    }
}
```

### **DFS with Backtracking**

```cpp
void dfs(state, result) {
    if (base_case) {
        result.push_back(current);
        return;
    }
    for (choice in choices) {
        make_choice();           // Choose
        dfs(new_state, result);  // Explore
        undo_choice();           // Backtrack
    }
}
```

### **Binary Search Template**

```cpp
// Type 1: Standard binary search
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}

// Type 2: Finding boundaries
int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (condition) right = mid;
    else left = mid + 1;
}
```

### **Two Pointers Pattern**

```cpp
// Opposite ends
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // Process
        left++; right--;
    }
}

// Same direction
int slow = 0, fast = 0;
while (fast < n) {
    if (condition) {
        swap(nums[slow], nums[fast]);
        slow++;
    }
    fast++;
}
```

### **Monotonic Stack**

```cpp
stack<int> stk;
for (int i = 0; i < n; i++) {
    while (!stk.empty() && nums[stk.top()] < nums[i]) {
        int idx = stk.top();
        stk.pop();
        // Process: found next greater element for nums[idx]
    }
    stk.push(i);
}
```

### **Union Find**

```cpp
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};
```

### **Trie Structure**

```cpp
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() : children(26, nullptr), isWord(false) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }
};
```

---

## 📝 Summary of Essential C++ Skills

To master coding interviews with this repository, you need proficiency in:

1. **Core STL mastery**: `vector`, `unordered_map`, `queue`, `stack`, `priority_queue`
2. **Algorithm library**: `sort`, binary search functions, `max`/`min`
3. **Pointer manipulation**: Custom nodes, linked structures
4. **Template usage**: Understanding generic containers
5. **Iterator concepts**: `begin`/`end`, distance calculations
6. **Custom comparators**: For sorting and priority queues
7. **Bit manipulation**: Common tricks and patterns
8. **String handling**: `substr`, parsing, conversion functions
9. **Recursion & backtracking**: DFS patterns
10. **Memory awareness**: `new`/`delete` for custom structures
11. **Math functions**: `pow`, `log`, `abs` family
12. **Pair and tuple usage**: Return multiple values
13. **Range-based loops**: Modern C++ iteration
14. **Auto keyword**: Type inference

---

## 🎓 Category-Specific Focus Areas

### Array & String (92 problems)
- **Key techniques**: Two pointers, sliding window, prefix sum
- **Data structures**: `vector`, `unordered_map`, `string`
- **Must-know**: Kadane's algorithm, KMP, sliding window with hash map

### BackTracking & DFS & BFS (63 problems)
- **Key techniques**: Recursion with backtracking, visited tracking
- **Data structures**: `queue` (BFS), `unordered_set` (visited)
- **Must-know**: BFS level-order, DFS backtracking template

### Tree (44 problems)
- **Key techniques**: Recursion, iterative traversal with stack
- **Data structures**: `TreeNode*`, `queue`, `stack`
- **Must-know**: All traversals, LCA, serialize/deserialize

### Dynamic Programming (40 problems)
- **Key techniques**: Bottom-up, top-down with memo, space optimization
- **Data structures**: `vector<vector<int>>` for DP tables
- **Must-know**: Knapsack, LCS, path problems

### HashTable (26 problems)
- **Key techniques**: Frequency counting, prefix sum + hash
- **Data structures**: `unordered_map`, `unordered_set`
- **Must-know**: Two sum pattern, anagram grouping

### Stack & Queue & Heap (22 problems)
- **Key techniques**: Monotonic stack, min/max heap
- **Data structures**: `stack`, `queue`, `priority_queue`
- **Must-know**: Calculator, next greater element, K-th largest

### Binary Search (20 problems)
- **Key techniques**: Template mastery, boundary finding
- **Data structures**: Sorted `vector`
- **Must-know**: `lower_bound`, `upper_bound`, rotated array search

### Design (18 problems)
- **Key techniques**: Combining multiple data structures
- **Data structures**: `list` + `map` (LRU), `vector` + `unordered_map`
- **Must-know**: LRU Cache, insert/delete/getRandom O(1)

### LinkedList (16 problems)
- **Key techniques**: Dummy node, fast/slow pointers, reversal
- **Data structures**: `ListNode*`
- **Must-know**: Cycle detection, merge lists, reverse in groups

---

## 🚀 Tips for Success

1. **Don't just read solutions** - Implement them from scratch
2. **Time yourself** - Practice under interview conditions (45 min/problem)
3. **Explain out loud** - Practice verbalizing your thought process
4. **Track patterns** - Notice when similar techniques apply
5. **Review regularly** - Revisit problems after 1 week, 1 month
6. **Focus on weak areas** - Spend extra time on challenging categories
7. **Mock interviews** - Practice with peers or platforms
8. **Optimize solutions** - Always try to improve time/space complexity

---

## 📈 Progress Tracking

Create a spreadsheet or document to track:
- [ ] Problems completed each day
- [ ] Difficulty level (Easy/Medium/Hard)
- [ ] Time taken vs target time
- [ ] Solutions that need review
- [ ] Patterns/techniques learned
- [ ] Topics that need more practice

---

**Good luck with your interview preparation! Practice makes perfect!** 🎯
