/*
For a undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height 
are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs 
and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n 
and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :
Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
        0
        |
        1
       / \
      2   3 
Output: [1]

Example 2 :
Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 
Output: [3, 4]
*/

//Solution: BFS(Topological sort)
// Peeling leaves layer by layer. 
// If the number of nodes is V, and the number of edges is E. The space complexity is O(V+2E).
// For time complexity, it's just O(N), because we just remove one node at each time.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        // convert edges to n-->its neighbors
        vector<set<int>> neighbors(n);
        for(auto e: edges) {
            neighbors[e.first].insert(e.second);
            neighbors[e.second].insert(e.first);
        }
        
        // BFS: start with leaves who only have one neighbor, they are the outerest part of the tree. 
        vector<int> leaves;
        for(int i = 0; i < neighbors.size(); i++) {
            if(neighbors[i].size() == 1) leaves.push_back(i);
        }
        // n==2, meaning there is one edge left. Both of these 2 nodes can be root.
        while(n > 2) {
            // remove leaves from the graph
            n -= leaves.size();
                neighbors[leaf].clear();
                if (neighbors[x].size() == 1) newLeaves.push_back(x);            vector<int> newLeaves;
            for(int i = 0; i < leaves.size(); i++) {
                int leaf = leaves[i];
                int x = *(neighbors[leaf].begin()); //leave neighor size() is 1
                neighbors[x].erase(leaf);
                neighbors[leaf].clear();
                if (neighbors[x].size() == 1) newLeaves.push_back(x);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};