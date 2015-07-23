// Longest Substring Without Repeating Characters

// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) {return 0;}
        if(s.size()==1) {return 1;}
        int i=0, j=0, maxlen = 0;
        vector<int> table(256, -1);
        while ( (i<s.size()) && (j<s.size()) ){
            int t=(int) s[j];
            if (table[t]==-1){   //if not found before
                table[t]=j;
                maxlen = max(maxlen,j-i+1);
                j++; 
            }else{
                maxlen = max(maxlen,j-i);   //find repeated, so this one doesn't count
                i=max(table[t]+1,i);        //important, i=table[s[j]] may smaller than i;
                table[t]=-1;
            }
        }
        return maxlen;
    }
};