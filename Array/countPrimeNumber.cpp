/*
Leetcode Question:Count the number of prime numbers less 
than a non-negative number, n.
(https://leetcode.com/problems/count-primes/)

This solution is based on Sieve of Eratosthenes, which might sound 
too academic, but actually pretty straightforward. 

Time: O(n)       Space:O(n)
*/


class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) {      //Base case;
            return 0;
        }
        bool checkPrime[n];              
        for(int i = 0; i < n; i++) {
            checkPrime[i]=true;
        }
        int prime = 2;
        while(prime <= sqrt(n)){    //If a number is not a prime, this number at least has a factor <= n/2
            for(int x = 2; prime*x < n; x++){
                checkPrime[x*prime] = false;
            }
            prime++; //move to the next number
            while(prime <= n/2 && checkPrime[prime] == false) {  //if the number has been marked as not a prime, jump over it.
                prime++;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){  //Trap: remember start from 2.
            if(checkPrime[i]) count++;
        }
        return count;
    }
};