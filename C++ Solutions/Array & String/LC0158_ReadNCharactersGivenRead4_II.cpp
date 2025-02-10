/*
158. Read N Characters Given Read4 II - Call multiple times

Given a file and assume that you can only read the file using a given method read4, 
implement a method read to read n characters. Your method read may be called multiple times.
*/

int read4(char *buf);
 
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int cacheIndex = 0;
    int cacheSize = 0;
    char cache[4];
 
    int read(char *buf, int n) {
        int count = 0;
        while (count < n) {
            if (cacheIndex < cacheSize) {
                buf[count++] = cache[cacheIndex++];
            } else {
                cacheSize = read4(cache);
                cacheIndex = 0;
                if (cacheSize == 0) {
                    break;
                }
            }
        }
        return count;
    }
};
 