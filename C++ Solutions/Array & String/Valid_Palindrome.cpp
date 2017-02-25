// Valid Palindrome
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// “A man, a plan, a canal: Panama” is a palindrome.
// “race a car” is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.
// For the purpose of this problem, we define empty string as valid palindrome.

// My Solution:

bool isPalindrome(string s) {
  int start = 0;
  int end = s.size()-1;
  while(start < end){
    if(isalnum(s[start]) == false) {start++; continue;}
    if(isalnum(s[end]) == false) {end--; continue;}
    if(tolower(s[start]) != tolower(s[end])){
      return false;
    }else{
      start++;
      end--;
    }
  }
  return true;
}
