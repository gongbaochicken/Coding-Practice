// 2506. Count Pairs Of Similar Strings

/*
You are given a 0-indexed string array words.

Two strings are similar if they consist of the same characters.

For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and words[j] are similar.

 

Example 1:

Input: words = ["aba","aabb","abcd","bac","aabc"]
Output: 2
Explanation: There are 2 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 
Example 2:

Input: words = ["aabb","ab","ba"]
Output: 3
Explanation: There are 3 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 0 and j = 2 : both words[0] and words[2] only consist of characters 'a' and 'b'.
- i = 1 and j = 2 : both words[1] and words[2] only consist of characters 'a' and 'b'.
Example 3:

Input: words = ["nba","cba","dba"]
Output: 0
Explanation: Since there does not exist any pair that satisfies the conditions, we return 0.

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consist of only lowercase English letters.
*/

// Solution: Hash Table, 
// Time: O(N * k); k is average length of words
// Space: O(N)
class Solution {
public:
    string hashHelper(string s) {
        vector<bool> collection(26);
        for (auto c: s) {
            collection[c-'a'] = true;
        }

        string res = "";
        for(int i = 0; i < 26; i++) {
            if (collection[i] == true) {
                res += 'a' + i;
            }
        } 
        return res;
    }

    int similarPairs(vector<string>& words) {
        unordered_map<string, vector<string>> m;
        for (auto word: words) {
            string key = hashHelper(word);
            m[key].push_back(word);
        }

        int count = 0;
        for (auto pair: m) {
            int distinctWordPerGroup = pair.second.size();
            if (distinctWordPerGroup > 1) {
                int pariPerGroup = distinctWordPerGroup * (distinctWordPerGroup - 1) /2;
                count += pariPerGroup;
            }
        }
        return count;
    }
};