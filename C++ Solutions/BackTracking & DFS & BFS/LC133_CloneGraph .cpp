//Clone Graph 
//Tags: BSF, DFS, Map
/*Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/


//Solution 1---BFS:

/*
Note that if you make a new copy of the node, these copies are not the same 
and the graph structure will be wrong! Now you see the trickiest part of this 
problem. In fact, we need to maintain a mapping from each node to its copy. 
If the node has a copy, we simply use the existed copy. 
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m; //old To New
        queue<UndirectedGraphNode*> toVisit;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        toVisit.push(node);
        m[node] = copy;
        while(!toVisit.empty()){
            UndirectedGraphNode* curr = toVisit.front();
            toVisit.pop();
            for(const auto& n: curr->neighbors){
                if(m.find(n) == m.end()){
                    UndirectedGraphNode* newNeighbor = new UndirectedGraphNode(n->label);
                    toVisit.push(n);
                    m[n] = newNeighbor;
                }
                m[curr]->neighbors.push_back(m[n]);
            }
        }
        return copy;
    }
};

//Solution 2---DFS:

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (map.find(node) == map.end()) {
            map[node] = new UndirectedGraphNode(node->label);
            for (auto neigh : node->neighbors)
                map[node]->neighbors.push_back(cloneGraph(neigh));
        }
        return map[node];
    }
};