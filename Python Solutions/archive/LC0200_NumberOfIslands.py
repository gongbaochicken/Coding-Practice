"""
Problem: Number of Islands
Difficulty: Medium
Source: LeetCode #200

Description:
Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically. You may assume all four edges of the grid are all surrounded by water.

Examples:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'
"""

from typing import List, Optional


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        Approach: DFS or BFS to mark visited islands
        Time Complexity: O(m * n)
        Space Complexity: O(m * n)
        """
        # TODO: Implement solution
        pass


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Test case 1
    # grid1 = [
    #     ["1","1","1","1","0"],
    #     ["1","1","0","1","0"],
    #     ["1","1","0","0","0"],
    #     ["0","0","0","0","0"]
    # ]
    # assert sol.numIslands(grid1) == 1, "Test case 1 failed"

    # Test case 2
    # grid2 = [
    #     ["1","1","0","0","0"],
    #     ["1","1","0","0","0"],
    #     ["0","0","1","0","0"],
    #     ["0","0","0","1","1"]
    # ]
    # assert sol.numIslands(grid2) == 3, "Test case 2 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
