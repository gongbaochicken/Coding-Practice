/*
68. Text Justification
Example 1:
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.

Example 3:
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

// very trivial and tricky
class Solution {
public:
    void formatStr(string& str, int wordCount, int maxWidth, bool isLastLine) {
        str.pop_back(); //remove tailing one space
        int spaceNum = wordCount - 1;
        // if there is no space (one word) or is last line, just need insert tail spaces
        if (spaceNum == 0 || isLastLine) {
            str.insert(str.end(), maxWidth-str.size(), ' ');
            return;
        }
        int spaceSpace = maxWidth - str.size(), eachSpace = spaceSpace/spaceNum;
        int leftSpace = spaceSpace % spaceNum, rightSpace = spaceNum - leftSpace;
        for (int x = str.size() - 1; x >= 0; x--) {
            if (str[x] == ' ') {
                if (rightSpace) {
                    str.insert(x, eachSpace, ' ');
                    --rightSpace;
                } else {
                    str.insert(x, eachSpace + 1, ' ');
                }
            }
        }
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {        
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            int wordCount = 1;
            string str = words[i];
            // if the word equals to maxWidth
            if(str.size() == maxWidth) {
                ans.push_back(str);
                continue;
            }
            // try to fetch more words to fit
            while(i < words.size()) {
                str += " ";
                bool isLastWord = i == words.size()-1;
                if (str.size() == maxWidth || isLastWord || str.size() + words[i+1].size() > maxWidth) {
                    // adujust for the row
                    formatStr(str, wordCount, maxWidth, isLastWord);
                    break;
                }
                str += words[++i];
                ++wordCount;
            }
            ans.push_back(str);
        }
        return ans;
    }
};