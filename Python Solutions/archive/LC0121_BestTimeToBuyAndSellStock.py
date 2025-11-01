"""
Problem: Best Time to Buy and Sell Stock
Difficulty: Easy
Source: LeetCode #121

Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any
profit, return 0.

Examples:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
- 1 <= prices.length <= 10^5
- 0 <= prices[i] <= 10^4
"""

from typing import List, Optional


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Approach: Track minimum price and maximum profit
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
    # assert sol.maxProfit([7,1,5,3,6,4]) == 5, "Test case 1 failed"

    # Test case 2
    # assert sol.maxProfit([7,6,4,3,1]) == 0, "Test case 2 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
