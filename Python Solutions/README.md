# Python Interview Solutions

A collection of Python solutions for coding interview questions, organized by topic with built-in testing framework.

## 📁 Directory Structure

```
Python Solutions/
├── arrays/                    # Array and matrix problems
├── strings/                   # String manipulation problems
├── tree/                      # Binary tree and tree problems
├── backtracking/              # Backtracking, DFS, BFS problems
├── dynamic_programming/       # DP problems
├── linked_lists/              # Linked list problems
├── stack_queue/               # Stack, queue, and heap problems
├── hash_table/                # Hash table problems
├── binary_search/             # Binary search problems
├── greedy/                    # Greedy algorithm problems
├── design/                    # Design problems
├── trie/                      # Trie problems
├── union_find/                # Union-Find problems
├── math_bit/                  # Math and bit manipulation
├── range_query/               # Range query and segment tree
├── archive/                   # Additional LeetCode templates
├── solution_template.py       # Template for new solutions
├── test_runner.py             # Automated test runner
└── convert_cpp_to_python.py   # C++ to Python converter
```

## 🚀 Quick Start

### Working with Existing Templates

All C++ solutions have been converted to Python template files. To work on a problem:

1. Find a problem file (e.g., `arrays/LC0001_2Sum.py`)
2. Implement the solution (replace `pass` with your code)
3. Add test cases
4. Run: `python3 arrays/LC0001_2Sum.py`

### Creating a New Solution

1. Copy the template:
```bash
cp solution_template.py arrays/your_problem_name.py
```

2. Fill in the problem details and implement your solution

3. Add test cases to the `test_solution()` function

4. Run your solution:
```bash
python3 arrays/your_problem_name.py
```

### Using the Archive

The `archive/` folder contains popular LeetCode questions not in the C++ collection:

1. Browse `archive/` for additional problems
2. Move to appropriate category when ready:
   ```bash
   mv archive/LC0070_ClimbingStairs.py dynamic_programming/
   ```
3. Implement and test

### Running Tests

Run all tests:
```bash
python3 test_runner.py
```

Run tests for a specific category:
```bash
python3 test_runner.py arrays
```

Run a specific solution:
```bash
python3 test_runner.py arrays/LC0001_2Sum.py
```

The test runner will show:
- ✓ **Passed**: Solution implemented and tests pass
- ✗ **Failed**: Solution has errors or tests fail
- ⊘ **Skipped**: Solution not yet implemented (template only)

## 📝 Solution Template Format

Each solution file includes:

- **Problem metadata**: Name, difficulty, source
- **Description**: Detailed problem statement
- **Examples**: Input/output examples
- **Constraints**: Problem constraints
- **Solution class**: Your implementation with type hints
- **Complexity analysis**: Time and space complexity comments
- **Test cases**: Comprehensive test suite

## 🧪 Writing Test Cases

Tests use simple assertions for clarity:

```python
def test_solution():
    sol = Solution()

    # Basic test
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1], "Test case 1 failed"

    # Edge case
    assert sol.twoSum([3, 3], 6) == [0, 1], "Edge case failed"

    print("✓ All test cases passed!")
```

## 💡 Tips

- Always include type hints for better code clarity
- Document your approach and complexity in the docstring
- Test edge cases (empty input, single element, large input, etc.)
- Run tests frequently to verify correctness
- Use descriptive variable names

## 📚 Example Problems by Category

### Arrays
- Two Sum
- Best Time to Buy and Sell Stock
- Maximum Subarray
- Container With Most Water

### Strings
- Valid Palindrome
- Longest Substring Without Repeating Characters
- Group Anagrams

### Trees
- Binary Tree Inorder Traversal
- Maximum Depth of Binary Tree
- Validate Binary Search Tree

### Dynamic Programming
- Climbing Stairs
- Longest Common Subsequence
- Coin Change

## 🎯 Study Plan Suggestions

1. **Week 1-2**: Arrays and Strings (fundamentals)
2. **Week 3-4**: Linked Lists, Stacks, and Queues
3. **Week 5-6**: Trees and Graphs
4. **Week 7-8**: Dynamic Programming and Backtracking
5. **Week 9-10**: Review and practice mixed problems

## 🔧 Requirements

- Python 3.7+
- No external dependencies required for basic usage
- Optional: `pytest` for advanced testing features

## 📊 Progress Tracking

Keep track of solved problems by difficulty:

- ✅ Easy: Focus on fundamental concepts
- ✅ Medium: Most common interview questions
- ✅ Hard: Advanced problems for top-tier companies

Happy coding! 🚀
