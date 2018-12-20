//Find the Connected Component in the UDG
/*
Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

Have you met this question in a real interview? Yes
Example
Given graph:

A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
*/

//Solution in C++11 style:
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int>> ans;
        if(nodes.size() == 0) return ans;
        unordered_set<UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> current;
        
        for (const auto& node : nodes) {
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                current.push(node);

                vector<int> component;
                while (!current.empty()) {
                    auto node = current.front();
                    current.pop();
                    component.push_back(node->label);
                    //iteration for its neighbors
                    for (const auto& n : node->neighbors) {
                        if (visited.find(n) == visited.end()) {
                            visited.insert(n);
                            current.push(n);
                        }
                    }
                }
                // Sort component.
                sort(component.begin(), component.end());
                ans.push_back(component);
            }
        }
        return ans;
    }
};
