/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction 
on how your encode/decode algorithm should work. You just need to ensure that a URL 
can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
    unordered_map<string, string> longToShort, shortToLong;
    int countRef = 0;

    string convertToCode(int Count) {
        string pattern = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string s = "";
        while(Count) {
            int i = Count%62;
            s += pattern[i];
            Count /= 62;
        }
        while (s.size() < 6) {
            s = "0" + s;
        }
        s = "http//tinyurl.com/" + s;
        return s;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end()) return longToShort[longUrl];
        //lock guard
        ++countRef;
        string shortUrl = convertToCode(countRef);
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortToLong.find(shortUrl) != shortToLong.end()) return shortToLong[shortUrl];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));