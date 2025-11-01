"""
Problem: AddTwoNumbers
Difficulty: [Easy/Medium/Hard]
Source: LeetCode #0002

Description:
2. Add Two Numbers
DescriptionHintsSubmissionsDiscussSolution
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)， Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*
Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
/

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
