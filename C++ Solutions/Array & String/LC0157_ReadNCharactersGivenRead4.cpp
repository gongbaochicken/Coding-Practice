/*
157. Read N Characters Given Read4

Given a file and assume that you can only read the file using a given method read4, 
implement a method to read n characters.

Method read4:
The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf.
The return value is the number of actual characters read.
Note that read4() has its own file pointer, much like FILE *fp in C.
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        int count = -1;
        for (int i = 0; i <= n/4 && count !=0; ++i) {
            count = read4(buf + index);
            index += count;
        }
        return min(index, n);
    }
};