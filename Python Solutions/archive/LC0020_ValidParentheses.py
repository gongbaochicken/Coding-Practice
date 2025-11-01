"""
Problem: Valid Parentheses
Difficulty: Easy
Source: LeetCode #20

Description:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Examples:
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Input: s = "([)]"
Output: false

Constraints:
- 1 <= s.length <= 10^4
- s consists of parentheses only '()[]{}'
"""

from typing import List, Optional


class Solution:
    def isValid(self, s: str) -> bool:
        """
        Approach: Use stack to match brackets
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        # TODO: Implement solution
        pass


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Test case 1
    # assert sol.isValid("()") == True, "Test case 1 failed"

    # Test case 2
    # assert sol.isValid("()[]{}") == True, "Test case 2 failed"

    # Test case 3
    # assert sol.isValid("(]") == False, "Test case 3 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
