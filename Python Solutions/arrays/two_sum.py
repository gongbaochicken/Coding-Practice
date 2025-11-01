"""
Problem: Two Sum
Difficulty: Easy
Source: LeetCode #1

Description:
Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may
not use the same element twice.

You can return the answer in any order.

Examples:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Approach: Use hash map to store complements
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        seen = {}  # value -> index

        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i

        return []  # Should never reach here given constraints


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Test case 1
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1], "Test case 1 failed"

    # Test case 2
    assert sol.twoSum([3, 2, 4], 6) == [1, 2], "Test case 2 failed"

    # Test case 3 - Same numbers
    assert sol.twoSum([3, 3], 6) == [0, 1], "Test case 3 failed"

    # Test case 4 - Negative numbers
    assert sol.twoSum([-1, -2, -3, -4, -5], -8) == [2, 4], "Test case 4 failed"

    # Test case 5 - Large numbers
    result = sol.twoSum([1000000000, 2, 3, 4, 5], 1000000002)
    assert result == [0, 1], "Test case 5 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
