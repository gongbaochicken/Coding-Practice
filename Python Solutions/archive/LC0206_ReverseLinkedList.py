"""
Problem: Reverse Linked List
Difficulty: Easy
Source: LeetCode #206

Description:
Given the head of a singly linked list, reverse the list, and return the reversed list.

Examples:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []

Constraints:
- The number of nodes in the list is the range [0, 5000]
- -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
"""

from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Approach: Iterative reversal with three pointers
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        # TODO: Implement solution
        pass


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Helper function to create linked list from array
    def create_list(arr):
        if not arr:
            return None
        head = ListNode(arr[0])
        curr = head
        for val in arr[1:]:
            curr.next = ListNode(val)
            curr = curr.next
        return head

    # Helper function to convert linked list to array
    def list_to_array(head):
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result

    # Test case 1
    # head1 = create_list([1,2,3,4,5])
    # result1 = sol.reverseList(head1)
    # assert list_to_array(result1) == [5,4,3,2,1], "Test case 1 failed"

    # Test case 2
    # head2 = create_list([1,2])
    # result2 = sol.reverseList(head2)
    # assert list_to_array(result2) == [2,1], "Test case 2 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
