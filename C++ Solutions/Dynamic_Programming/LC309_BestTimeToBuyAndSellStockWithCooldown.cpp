//Best Time to Buy and Sell Stock with Cooldown
//
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

//Dynamic Programming:
//Time: O(N)  Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        
        //buy[i] = max(cool[i-1]-price, buy[i-1]);
        //sell[i] = max(buy[i-1]+prices, sell[i-1]);
        //cool[i] = max(cool[i-1], sell[i-1], buy[i-1]);
        
        //However, cool[i] = sell[i-1];
        //so buy[i] = max(sell[i-2]-price, buy[i-1]);
        
        //When i = 0:We can buy. The max profit at i = 0 ending with a buy is -prices[0].
        //We cannot sell. The max profit at i = 0 ending with a sell is 0.
        int buy0 = -prices[0], buy1 = buy0, sell0 = 0, sell1 = 0, sell2 = 0;  //reduce space to O(1)
        for(int i = 1; i < prices.size(); i++){
            buy0 = max(sell2 - prices[i], buy1);
            sell0 = max(sell1, buy1 + prices[i]);
            buy1 = buy0;
            sell2 = sell1;
            sell1 = sell0;
        }
        return sell0;
    }
};