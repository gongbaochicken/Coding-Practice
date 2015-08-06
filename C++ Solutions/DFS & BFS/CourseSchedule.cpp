//Course Schedule
//Tags: BFS, DFS, Graph

/*
 There are a total of n courses you have to take, labeled from 0 to n - 1. Some courses may have prerequisites, 
 for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example: 2, [[1,0]], There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
So it is possible.

2, [[1,0],[0,1]], There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to 
take course 0 you should also have finished course 1. So it is impossible.

Note: The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
*/
/*
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, 
no topological ordering exists and therefore it will be impossible to take all courses. Both BFS 
and DFS can be used to solve this problem using the idea of topological sort.
*/

//Solution 1:
/*BFS:
BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to 
do so, there must be a cycle in the graph and we return false. Otherwise we have found one. We set its 
indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. 
This process will be repeated for n (number of nodes) times. If we have not returned false, we will 
return true.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> degree = compute_indegree(graph);
        for(int i = 0; i < numCourses; ++i){
            int j =0;
            for(; j < numCourses; j++){
                if(!degree[j]) break;
            }
            if(j == numCourses) return false;
            degree[j] = -1;
            for(auto itr = graph[j].begin(); itr != graph[j].end(); itr++){
                degree[*itr]--;
            }
        }
        return true;
    }
    
private:
    vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        for(auto itr : prerequisites){
            graph[itr.second].insert(itr.first);
        }
        return graph;
    }
   
    vector<int> compute_indegree(vector<unordered_set<int> >& graph) {
        vector<int> degree(graph.size(), 0);
        for(auto neighor: graph){
            for(auto indegree: neighor){
                degree[indegree]++;
            }
        }
        return degree;
    }
};

//Solution 2(DFS):
/*
For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor... 
and so on. If it meets a node which was visited in the current process of DFS visit, a cycle is detected 
and we will return false. Otherwise it will start from another unvisited node and repeat this process till 
all the nodes have been visited. Note that you should make two records: one is to record all the visited 
nodes and the other is to record the visited nodes in the current DFS visit.

The code is as follows. We use a vector<bool> to record all the visited nodes and an unordered_set<int> to 
record the visited nodes of the current DFS visit. Once the current visit is finished, we erase the starting 
node from the set.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        unordered_set<int> curVisit;
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, curVisit, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs_cycle(vector<unordered_set<int> >& graph, int node, unordered_set<int>& curVisit, vector<bool>& visited) {
        if (visited[node]) return false;
        visited[node] = true;
        curVisit.insert(node);
        for (auto itr = graph[node].begin(); itr != graph[node].end(); itr++)
            if (curVisit.find(*itr) != curVisit.end() || dfs_cycle(graph, *itr, curVisit, visited))
                return true;
        curVisit.erase(node);
        return false;
    }
}; 



