//Permutation Sequence 
/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

// We have to return the k-th permutation 
// in lexicographic order.
//
// We can take a recursive approach.
// The lexicographic order means that first
// we have those starting with digit 1 then
// those starting with 2 and so on until
// digit n.
// 
// For example, for n = 4, we have: 
// k   perm
// --------
// 1   1234
// 2   1243
// 3   1324
// 4   1342
// 5   1423
// 6   1432
//
// 7   2134
// 8   2143
// 9   2314
// 10  2341
// 11  2413
// 12  2431
// 
// 13  3124
// 14  3142
// 15  3214
// 16  3241
// 17  3412
// 18  3421
// 
// 19  4123
// 20  4132
// 21  4213
// 22  4231
// 23  4312
// 24  4321
//
// Since there are n digits, the number of all 
// permutations starting with a given digit d
// is equal to (n-1)!.
// Given k, the permutation order number,
// we can determine which one is the first 
// digit d: d = [(k-1)/(n-1)!]+1;
// 
// Once we determined the first digit
// we recursively determine the remaining
// digits.
// 
// We keep all digits in a vector: {1,2,3,...,n}.
// Once we determine a digit we remove it
// from there and recursively solve
// the problem for the remaining n-1 digits.
// The formula above to determine the digit
// is written slightly different in code
// such that instead of the digit we first
// get its index in this vector.
//
// From k we can also determine k for the
// n-1 problem as: prevK = k%prevFact.
// This is the order number within the 
// current digit's group.
//
// Now we can recursively solve the problem 
// for n-1 and prevK and determine the rest 
// of the digits.

class Solution
{
    int factorial(int n)
    {
        int fact = 1;
        for (int i = 1; i <= n; i++)
            fact *= i;

        return fact;
    }

    string getPermutation(int n, int k, vector<int>& digits)
    {
        if (n == 1)
        {
            return to_string(digits[0]);
        }

        int prevFact = factorial(n - 1);

        int idx = (k - 1) / prevFact;
        int d = digits[idx];

        digits.erase(digits.begin() + idx);

        int prevK = k%prevFact;
        if (prevK == 0)
            prevK = prevFact;

        string prev = getPermutation(n - 1, prevK, digits);

        return to_string(d) + prev;
    }

public:
    string getPermutation(int n, int k)
    {
        vector<int> digits;
        for (int i = 1; i <= n; i++)
        {
            digits.push_back(i);
        }

        return getPermutation(n, k, digits);
    }
};



//Iterative Solution:
// The idea behind is just to choose the number for the ith place of the resulting string; 
// it changes every time that k is larger than factorial of the length of the remainder of 
// the string (hope the code clarifies it a bit). 

class Solution {
        inline int fact(int i){
            //i>=1&& i<=8 (since n<=9)
            static int fact[]={1,2,6,24,120,720,5040,40320};
            return fact[i-1];
        }
    public:
        string getPermutation(int n, int k) {
            k-=1;
            string s;
            for(int i=0;i<n;++i){
                s.push_back('1'+i);
            }
            if(n==1) return s;

            for(int i=0;i<n-1;++i){
                int remLength=n-1-i; //always at least 1
                int mod=fact(remLength);
                int next=k/mod;
                //s[i+next] is the value we want s[i] to have;
                //s[i+1] should be what s[i] was, the remaining part should keep ordering

                if(next!=0){
                    char tmp=s[i];
                    s[i]=s[i+next];
                    s.erase(s.begin()+i+next);
                    s.insert(s.begin()+i+1, tmp);
                }
                k%=mod;
            }
            return s;
        }
    };


//More elegant way:

class Solution {

public:
    string getPermutation(int n, int k) {
            k = k-1;
            string s;
            int fact = 1;
            if(n == 1) return "1";
            for(int i = 0; i < n; ++i){
                fact *= i+1;
                s.push_back('1'+i);
            }
            
            for(int i = 0; i < n-1; i++){
                fact = fact/(n-i);
                int remLength = n-1-i; //always at least 1
                int pos = k/fact;
                //s[i+pos] is the value we want s[i] to have;
                //s[i+1] should be what s[i] was, the remaining part should keep ordering
                //Put s[i+pos] in front of original s[i]
                if(pos!=0){
                    char tmp = s[i];
                    s[i] = s[i + pos];
                    s.erase(s.begin() + i + pos);
                    s.insert(s.begin() + i + 1, tmp);
                }
                k %= fact;
            }
            return s;
    }
};

