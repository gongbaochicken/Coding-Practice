//Best Time to Buy and Sell Stock III

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        for(auto curr: prices){
            if(buy1 < -curr) buy1 = -curr;
            if(sell1 < buy1 + curr) sell1 = buy1 + curr;
            if(buy2 < sell1 - curr) buy2 = sell1 - curr;
            if(sell2 < buy2 + curr) sell2 = buy2 + curr;
        }
        return sell2;
    }
};