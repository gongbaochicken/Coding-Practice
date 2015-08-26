//Add Digits
//Tags: Math
/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example: Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/

//Analysis:
// abc = 100a + 10b + c = a + b + c + 99a + 9b
// (a+b+c)%9 = (100a+10b+c)%9 = (abc) % 9
//This means when a num mod 9, it equals to the add digits mod 9. Since we just return only one digit, 
//so there is a large chance to return remainder, except for a few corner case. 

class Solution {
public:
	int addDigits(int num) {
     	if(num == 0) return 0;
        if(num % 9 == 0) return 9;
        return num%9;
    }
};


//More concise code.
class Solution {
public:
    int addDigits(int num) {
        return num%9 == 0? (num == 0? 0 : 9) : num%9;
    }
};
