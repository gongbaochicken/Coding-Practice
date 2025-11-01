"""
Problem: reorderList
Difficulty: [Easy/Medium/Hard]
Source: [TODO: Add source]

Description:
Reorder List
Question:
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
C++ Code:
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
