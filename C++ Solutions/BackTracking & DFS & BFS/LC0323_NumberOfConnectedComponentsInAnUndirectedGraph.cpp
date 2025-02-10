// 323. Number of Connected Components in an Undirected Graph
/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2

Example 2:
Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus 
will not appear together in edges.
*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        vector<bool> visited(n, false);
        for(auto e: edges){
            adjList[e.first].push_back(e.second);
            adjList[e.second].push_back(e.first);
        }
        if(adjList.size() == 0) return n;
        int ans = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;

            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int p = q.front();
                q.pop();
                for(auto adj: adjList[p]){
                    if(!visited[adj]){
                        q.push(adj);
                        visited[adj] = true;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};