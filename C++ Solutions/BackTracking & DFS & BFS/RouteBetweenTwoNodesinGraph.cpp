/*Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

Have you met this question in a real interview? Yes
Example
Given graph:

A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E
for s = B and t = E, return true

for s = D and t = C, return false
*/


/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        //I use iteration: BFS
        if(s == t) return true;
        if(graph.size() == 0) return false;
        stack<DirectedGraphNode*> st;
        set<DirectedGraphNode*> visited;
        st.push(s);
        while(!st.empty()){
            DirectedGraphNode* p = st.top();
            st.pop();
            if(visited.find(p) != visited.end()){
                continue;
            }
            visited.insert(p);
            for(auto neighbor : p->neighbors){
                if(neighbor == t) return true;
                st.push(neighbor);
            }
        }
        return false;
    }
};
