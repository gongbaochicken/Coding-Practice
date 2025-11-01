"""
Problem: SlidingWindowMaximum
Difficulty: [Easy/Medium/Hard]
Source: [TODO: Add source]

Description:
239. Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].
Solution: Use deque to main a window, which should follow 2 rules.
rule 1: In the window, the elements are descending orders. The front
is the maximum element.
rule 2: The window contains index to avoid repeating issues.
Time Complexisity: O(N)

Examples:
[TODO: Add examples]

Constraints:
[TODO: Add constraints]
"""

from typing import List, Optional


class Solution:
    def solve(self, param):
        """
        Approach: [TODO: Describe approach]
        Time Complexity: O(?)
        Space Complexity: O(?)
        """
        # TODO: Implement solution
        pass


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Test case 1
    # assert sol.solve(...) == expected, "Test case 1 failed"

    # Test case 2
    # assert sol.solve(...) == expected, "Test case 2 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
