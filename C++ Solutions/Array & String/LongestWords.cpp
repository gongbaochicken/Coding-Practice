//Longest Words
//Solution in One pass
/*
Given a dictionary, find all of the longest words in the dictionary.

Given
{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}
the longest words are(is) ["internationalization"].

Given
{
  "like",
  "love",
  "hate",
  "yes"
}
the longest words are ["like", "love", "hate"].
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int currLen = 0;
        vector<string> ans;
        if(dictionary.size() == 0) return ans;
        if(dictionary.size() == 1) return dictionary;
        currLen = dictionary[0].length();
        ans.push_back(dictionary[0]);
        for(int i = 1; i < dictionary.size(); ++i){
            if(dictionary[i].length() == currLen){
                ans.push_back(dictionary[i]);
            }else if(dictionary[i].length() > currLen){
                currLen = dictionary[i].length();
                ans.clear();
                ans.push_back(dictionary[i]);
            }
        }
        return ans;
    }
};