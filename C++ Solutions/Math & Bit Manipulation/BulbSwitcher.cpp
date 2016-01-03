//Bulb Switcher
/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/

//Solutions:
// For prime numbers, they must be off because we can only reach them twice.
/* For other numbers, if we can reach them odd times, then they are on; otherwise, they are off. So only 
 those numbers who have square root will be reached odd times and there are sqrt(n). The square number has
 odd number of unique factor numbers.  9=factor(1, 3, 9), 16 = factor(1, 2, 4, 8, 16)*/

 return (int)sqrt(n);

 class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        for(int i = 1; i*i <= n; i++){
            count++;
        }
        return count;
    }
};