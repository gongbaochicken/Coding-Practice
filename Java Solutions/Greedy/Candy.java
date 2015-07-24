//Candy
/* There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? */

     /* Solution:
     * O(n) Time, O(n) Space
     * From left to right, if ratings[i] increase, give one more
     * From right to left, if ratings[i] increase, give one more
     * Answer should be the max of two array
     * Simplify second traversal by calculate and decide max right away
     * And also calculate the sum
     */


public class Solution {

     
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        candies[0] = 1;
        for (int i = 1; i < ratings.length; i++)
            candies[i] = ratings[i] > ratings[i - 1] ? candies[i - 1] + 1 : 1;

        int res = candies[candies.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])    
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            res += candies[i];
        }
        return res;
    }
}