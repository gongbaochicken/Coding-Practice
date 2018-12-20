/*
Given a list of sorted characters letters containing only lowercase letters, 
and given a target letter target, find the smallest element in the list that 
is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and 
letters = ['a', 'b'], the answer is 'a'.

Examples:
Input: letters = ["c", "f", "j"]  target = "a"
Output: "c"

Input: letters = ["c", "f", "j"] target = "c"
Output: "f"

Input: letters = ["c", "f", "j"] target = "d"
Output: "f"

Input: letters = ["c", "f", "j"] target = "g"
Output: "j"

Input: letters = ["c", "f", "j"] target = "j"
Output: "c"

Input: letters = ["c", "f", "j"] target = "k"
Output: "c"

Note:
    letters has a length in range [2, 10000].
    letters consists of lowercase letters, and contains at least 2 unique letters.
    target is a lowercase letter.
*/

//solution: Time: O(lgN), Space: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target < letters[0] || target >= letters.back()) return letters[0];
        int l = 0, r = letters.size() - 1;
        //break condition: l == r
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (letters[mid] <= target) l = mid+1; //try to find the NEXT smallest
            else r = mid;
        }
        return letters[l];
    }
};