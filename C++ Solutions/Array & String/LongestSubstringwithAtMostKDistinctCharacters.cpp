//Longest Substring with At Most K Distinct Characters 
//2 pointers, Hashmap
/*
Given a string s, find the length of the longest substring T that contains at most k distinct characters.
Have you met this question in a real interview?
Example

For example, Given s = "eceba", k = 3,

T is "eceb" which its length is 4.
*/
class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
                //2 pointers and hashmap
        int slow = 0, fast = 0, maxLen = 0;
                                     
		// Key: letter;  value: the number of occurrences.
		unordered_map<char, int> map;
		for (; fast < s.length(); ++fast) {
			char c = s[fast];
			if (map.find(c) != map.end()) {
				map[c]++;
			} else {
				map[c] = 1;
				while (map.size() > k) {
					char slowChar = s[slow++];
					int count = map[slowChar];
					if (count > 1) {
						map[slowChar] = count - 1;
					} else {
						map.erase(slowChar);
					}
				}
			}

			maxLen = max(maxLen, fast - slow + 1);
		}
		return maxLen;
    }
};