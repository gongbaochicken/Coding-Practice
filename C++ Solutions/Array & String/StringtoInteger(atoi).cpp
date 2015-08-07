//String to Integer (atoi) 

//Implement atoi to convert a string to an integer.

//Solution 1:
//Use stringStream to convert
class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0) return 0;
        int result;
        stringstream strStream;
        strStream<<str;
        strStream>>result;
        return result;
    }
};

//Solution 2:
/* Care about 4 things:
1. clean the leading whitespaces;
2. sign
3. overflow
4. invalid input
*/
//Original Version:
class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0) return 0;
        int i = 0, sign = 1, base = 0;
        while(str[i] == ' ') {i++;}
        if(str[i] == '-'){
            sign = -1;
            i++;
        }else if(str[i] == '+'){
            sign = 1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && str[i] - '0'> 7)) {
                if(sign == 1){
                    return INT_MAX;
                }else{
                    return INT_MIN;
                }
            }
            base = base*10 + str[i]-'0';
            i++;
        }
        return sign*base;
    }
};


//Concise Version:
class Solution {
public:
    int myAtoi(string str) {
        int i = 0, sign = 1, base = 0;
        while(str[i] == ' ') {i++;}
        if(str[i] == '-' || str[i] == '+'){
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && str[i] - '0'> 7)) {
                if(sign == 1) return INT_MAX;
                return INT_MIN;
            }
            base = base*10 + str[i++]-'0';
        }
        return sign*base;
    }
};
