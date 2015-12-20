//Summary Ranges
/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> list = new ArrayList<String>();
        if(nums.length == 0) return list;
        int l, r;
        for(int i = 0; i < nums.length; i++){
            l = i;
            String s = Integer.toString(nums[i]);
            while(i+1 < nums.length && nums[i] == nums[i+1]-1){
                i++;
            }
            r = i;
            if(l < r){
                s = s + "->" + Integer.toString(nums[r]);
            }
            list.add(s);
        }
        return list;
    }
}