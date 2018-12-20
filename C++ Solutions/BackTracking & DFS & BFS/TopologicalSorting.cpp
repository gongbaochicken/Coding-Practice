//Topological Sorting
/*
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.
*/

//Solution: BFS
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
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> ans;
        if(graph.size() == 0) return ans;
        queue<DirectedGraphNode*> q;
        unordered_map<DirectedGraphNode*, int> map;

        //Find all nodes with no parent, and push them into queue and ans;
        for(auto node: graph){
            for(auto neighbor: node->neighbors){
                if(map.find(neighbor) != map.end()){
                    map[neighbor]++;
                }else{
                    map[neighbor] = 1;
                }
            }
        }
        
        for(auto node: graph){
            if(map.find(node) == map.end()){
                q.push(node);
                ans.push_back(node);
            }
        }
        
        //BFS, everytime minus 1 for someone recognize "current node" as a neighbor, when map[neibo]==0, 
        //it means all its parents has listes in the vector before it. So it is safe to push in the queue and ans;
        while(!q.empty()){
            DirectedGraphNode* node = q.front();
            q.pop();
            for(auto neibo: node->neighbors){
                map[neibo]--;
                if(map[neibo] == 0){
                    q.push(neibo);
                    ans.push_back(neibo);
                }
            }
        }
        
        return ans;
    }
};