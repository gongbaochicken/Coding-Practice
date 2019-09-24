// 857. Minimum Cost to Hire K Workers
/*
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

Example 1:
Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 

Note:
1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.
*/

class Solution {
public:
    struct Worker{
        int quality, wage;
        double ratio;
        Worker(int q, int w): quality(q), wage(w) {
            ratio = (double) (1.0*w/q);
        }
        
        bool operator<(const Worker& w2) {
            return ratio < w2.ratio;
        }
    };

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<Worker> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.push_back(Worker(quality[i], wage[i]));
        }
        sort(workers.begin(), workers.end());
        double ans = DBL_MAX;
        int totalQ = 0;
        // Now we are sure that the first K members of this group will give the best scenario
        // But There might be a case where we can have people later with higher rates(for sure) and lower quality required
        // SO we just remove the top quality person till now and use the rate of the higher guy
        priority_queue<int> pq; //max heap for quality
        for(Worker worker: workers) {
            double rate = worker.ratio; // apply to all totalQ
            totalQ += worker.quality;
            pq.push(worker.quality);
            if (pq.size() > K) {
                totalQ -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, rate*totalQ);
            }
        }
        return ans;
    }
};