// There are N students in a class. Some of them are friends, while some are not. 
// Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C,
// then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class.
// If M[i][j] = 1, then the ith and jth students are direct friends with each other, 
// otherwise not. And you have to output the total number of friend circles among all the students.

// Example 1:
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.
// Example 2:
// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
// so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
// Note:
// N is in range [1,200].
// M[i][i] = 1 for all students.
// If M[i][j] = 1, then M[j][i] = 1.

class UnionFindSet {
public:
    UnionFindSet(int n) {
        m_parents = vector<int>(n+1, 0);
        m_ranks = vector<int>(n+1, 0);

        for (int i = 0; i < n+1; i++) {
            m_parents[i] = i;
        }
    }
    
    bool Union(int u, int v){
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        if(m_ranks[pu] > m_ranks[pv]) {
            m_parents[pv] = pu;
        } else if (m_ranks[pv] > m_ranks[pu]) {
            m_parents[pu] = pv;
        } else {
            m_parents[pu] = pv;
            m_ranks[pv]++;
        }
        return true;
    }

    int Find(int id) {
        if(id != m_parents[id]) {
            m_parents[id] = Find(m_parents[id]);
        }
        return m_parents[id];
    }
private:
    vector<int> m_parents;
    vector<int> m_ranks;
}; 

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFindSet s(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) s.Union(i, j);
            }
        }
        unordered_set<int> circles;
        for (int i = 0; i < n; ++i) {
            circles.insert(s.Find(i));
        }
        return circles.size();
    }
};