// 282. Expression Add Operators
// Time: O(N^2*4^(N-1)), Space: O(N^2)
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.size() == 0) return ans;
        dfs(num, target, 0, "", 0, 0, ans);
        return ans;
    }
    
    void dfs(const string& num, const int target, int pos, const string& expr, long prev, long curr, vector<string>& ans){
        if (pos == num.size()) {
            if (curr == target) ans.push_back(expr);
            return;
        }
        for (int len = 1; len <= num.size() - pos; ++len) {
            string temp = num.substr(pos, len);
            if (temp[0] == '0' && temp.size() > 1) break; // Trick 1: '052'
            long val = stol(temp);
            if (val > INT_MAX) break; // Trick 2: Avoid overflow
            if (pos == 0) { // Special corner case for prefix
                dfs(num, target, len, temp, val, val, ans);
                continue;
            }
            // Key
            dfs(num, target, pos+len, expr + '+' + temp, val, curr + val, ans);
            dfs(num, target, pos+len, expr + '-' + temp, -val, curr - val, ans);
            dfs(num, target, pos+len, expr + '*' + temp, prev*val, curr - prev + prev*val, ans);
        }
    }
};


// Fater version
// Time: O(N*4^(N-1)), Space: O(N)
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.size() == 0) return ans;
        string exp(num.size()*2, '\0'); // Avoid using substr each time, to reduce time and space
        dfs(num, target, 0, exp, 0, 0, 0, ans);
        return ans;
    }
    
    void dfs(const string& num, const int target, int pos, string& expr, int len, long prev, long curr, vector<string>& ans){
        if (pos == num.size()) {
            if (curr == target) ans.push_back(expr.substr(0, len));
            return;
        }
        long val = 0;
        int start = pos, l = len;
        if (start != 0) ++len; // 需要放op,真正放数字的地方需要+1
        while(pos < num.size()) {
            val = val*10 + (num[pos] - '0');
            if (num[start] == '0' && (pos-start) > 0) break;
            if (val > INT_MAX) break;
            expr[len++] = num[pos++];
            if (start == 0) {
                dfs(num, target, pos, expr, len, val, val, ans);
                continue;
            }
            expr[l] = '+'; dfs(num, target, pos, expr, len, val, curr + val, ans);
            expr[l] = '-'; dfs(num, target, pos, expr, len, -val, curr - val, ans);
            expr[l] = '*'; dfs(num, target, pos, expr, len, prev*val, curr - prev + prev*val, ans);
        }
    }
};