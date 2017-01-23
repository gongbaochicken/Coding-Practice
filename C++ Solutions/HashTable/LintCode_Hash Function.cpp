//Hash Function

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int len = key.length();
        long hashSum = 0;
        if(len == 0) return 0;
        for(int i = 0; i < len; i++){
            long temp = (long) key[i];
            hashSum = temp + hashSum*33;
            hashSum %= HASH_SIZE;
        }
        return (int)hashSum;
    }
};