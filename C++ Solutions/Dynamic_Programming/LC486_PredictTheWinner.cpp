// 486. Predict the Winner
/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and 
then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores 
have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False

Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.  Hence, player 1 will never be the winner and you need to return False.

Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int finalScore = helper(nums, dp, 0, n-1);
        return finalScore >= 0;
    }
    
private:
    /*
        Since each player wanna win the game, which means he must get >= sum/2 score.
        From one player's perspective: 
            Each time, when I choose, I plus the score.  
            When opponent choose, I minus the score.
        As long as finally I got a positive score, which means I eat all the opponent score 
        and win. Through minus operation, one function includes both I and the opponents optimized option
    */
    int helper(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
        if (l == r) return nums[l];
        if (dp[l][r] != 0) return dp[l][r];
        
        int chooseLeft = nums[l] - helper(nums, dp, l+1, r); // if I choose left, my opponent will optimize in this way. Get what's left
        int chooseRight = nums[r] - helper(nums, dp, l, r-1);
        dp[l][r] = max(chooseLeft, chooseRight);
        return dp[l][r];
    }
};