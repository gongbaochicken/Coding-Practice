//Candy
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> ans(size, 1);
        for(int i = 1; i < size; i++){
            if(ratings[i-1] < ratings[i]){
                ans[i] = ans[i-1] + 1;
            }
        }
        int sum = 0;
        for(int i = size-1; i >= 1; i--){
            sum += ans[i];
            if(ratings[i] < ratings[i-1] && ans[i] >= ans[i-1]){
                ans[i-1] = ans[i] + 1;
            }
        }
        sum += ans[0];
        return sum;
    }
};