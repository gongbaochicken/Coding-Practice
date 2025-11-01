"""
Problem: Climbing Stairs
Difficulty: Easy
Source: LeetCode #70

Description:
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Examples:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
- 1 <= n <= 45
"""

from typing import List, Optional


class Solution:
    def climbStairs(self, n: int) -> int:
        """
        Approach: Dynamic Programming (Fibonacci pattern)
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        # TODO: Implement solution
        pass


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Test case 1
    # assert sol.climbStairs(2) == 2, "Test case 1 failed"

    # Test case 2
    # assert sol.climbStairs(3) == 3, "Test case 2 failed"

    # Test case 3
    # assert sol.climbStairs(5) == 8, "Test case 3 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
