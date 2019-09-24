/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which 
turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of 
islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0

Follow up:
Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

// Union Find
// Time: O(MN+L) Space: O(MN)
class UnionFind{
public:
  UnionFind(int N) {
    count = 0;
    for (int i = 0; i < N; ++i) {
      parent.push_back(-1);
      rank.push_back(0);
    }
  }

  bool isValid(int i) const {
    return parent[i] >= 0;
  }

  void setParent(int i) {
    parent[i] = i;
    ++count;
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    UnionFind uf (m * n); //cost O(M*N) in both time and space

    // for each position, union all possible neighors
    for (auto& pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's neighbors to see if they are in the existing islands or not
      vector<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.push_back((r-1) * n + c);
      if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.push_back((r+1) * n + c);
      if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.push_back(r * n + c - 1);
      if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.push_back(r * n + c + 1);

      int index = r * n + c;
      uf.setParent(index);
      for (auto i : overlap) uf.Union(i, index);
      ans.push_back(uf.getCount());
    }

    return ans;
  }
};


// Other:
class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
      vector<int> ans;
      UnionFind uf (m * n);

      for (auto& pos : positions) {
          int r = pos.first, c = pos.second;

          // check pos's neighbors to see if they are in the existing islands or not
          vector<int> overlap; // how many existing islands overlap with 'pos'
          if (r - 1 >= 0 && uf.isIsland((r-1) * n + c)) overlap.push_back((r-1) * n + c);
          if (r + 1 < m && uf.isIsland((r+1) * n + c)) overlap.push_back((r+1) * n + c);
          if (c - 1 >= 0 && uf.isIsland(r * n + c - 1)) overlap.push_back(r * n + c - 1);
          if (c + 1 < n && uf.isIsland(r * n + c + 1)) overlap.push_back(r * n + c + 1);

          int index = r * n + c;
          uf.setParent(index);
          for (auto i : overlap) uf.Union(i, index);
          ans.push_back(uf.getCount());
      }
      return ans;
  }
};
// Time complexity : O(m* n + L)