/* 973. K Closest Points to Origin
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
*/

// Time: O(NlogK), Space: O(K)
class Solution {
public:
    struct compare {
        bool operator()(const vector<int>& p1, const vector<int>& p2) {
            return pow(p1[0], 2) + pow(p1[1], 2) < pow(p2[0], 2) + pow(p2[1], 2);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> q;
        for (int i = 0; i < points.size(); ++i) {
            q.push(points[i]);
            if (q.size() > K) {
                vector<int> x = q.top();
                q.pop();
            }
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> pair = q.top();
            q.pop();
            ans.push_back(pair);
        }
        return ans;
    }
};