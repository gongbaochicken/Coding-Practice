// 675. Cut Off Trees for Golf Event
/*
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
 

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. 
And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off 
all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:
Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
 
Example 2:
Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
 
Example 3:
Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
*/

// BFS:

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.size() == 0 || forest[0].size() == 0) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<tree> v;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(forest[i][j] > 1) v.push_back(tree(i, j, forest[i][j]));
            }
        }
        sort(v.begin(), v.end(), compare);
        int x = 0, y = 0, sum = 0;
        for(const tree& t: v){
            int step = minStepToTarget(forest, x, y, t);
            if (step < 0) return -1;
            sum += step;
            // after cutting the tree, standing at t.x, t.y, continue
            x = t.x;
            y = t.y;
        }
        return sum;
    }

private:
    vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    struct tree{
        int x, y, height;
        tree(int a, int b, int c):x(a), y(b), height(c){}
    };

    static bool compare(tree& a, tree& b){
        return a.height < b.height;
    }

    int minStepToTarget(vector<vector<int>>& forest, int x, int y, tree t) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                // find the target tree 
                if (curr.first == t.x && curr.second == t.y) return step;
                for (const auto& d : dir) {
                    int nr = curr.first + d[0], nc = curr.second + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || forest[nr][nc] == 0 || visited[nr][nc]) continue;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            step++;
        }
        return -1;
    }
};