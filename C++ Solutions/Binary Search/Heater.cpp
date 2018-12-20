/*
Now, you are given positions of houses and heaters on a horizontal line, 
find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected 
output will be the minimum radius standard of heaters.

Note:
    Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
    Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
    As long as a house is in the heaters' warm radius range, it can be warmed.
    All the heaters follow your radius standard and the warm radius will the same.

Example 1:
Input: [1,2,3],[2]  Output: 1

Example 2:
Input: [1,2,3,4],[1,4] Output: 1
*/

class Solution {
public:
    //Time: O(M*lgN)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) return 0;
        sort(houses.begin(), houses.end()); ////M*O(lgM) Optional, but faster
        sort(heaters.begin(), heaters.end()); //N*O(lgN)
        int radius = INT_MIN;
        for(auto house: houses){ //M
            int index = find(heaters, house);
            int left = index - 1 >= 0? abs(house-heaters[index-1]): INT_MAX;
            int right = index < heaters.size()? abs(house-heaters[index]): INT_MAX;          
            radius = max(radius, min(left, right));
        }
        return radius;
    }

private:
    //fint the closest heater for the house. O(lgN)
    int find(vector<int>& heaters, int house){
        int l = 0, r = heaters.size()-1;
        while(l+1 < r){
            int mid = l + (r-l)/2;
            if(heaters[mid] == house){
                return mid;
            }else if(heaters[mid] > house){
                r = mid;
            }else{
                l = mid;
            }
        }
        return abs(l-house) < abs(r-house)? l: r;
    }
};