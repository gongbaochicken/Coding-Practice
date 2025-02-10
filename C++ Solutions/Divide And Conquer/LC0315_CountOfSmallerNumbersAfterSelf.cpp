/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is 
the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

class Solution {
    int[] count;
    int[] helper;
    int[] nums;
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        count = new int[n];
        helper = new int[n];
        int[] index = new int[n];
        for (int i = 0; i < n; i++) index[i] = i;
        
        mergeSort(index, 0, n - 1);
        List<Integer> res = new ArrayList();
        for (int i = 0; i < n; i++) {
            res.add(count[i]);
        }
        return res;
    }
    
    private void mergeSort(int[] index, int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        mergeSort(index, start, mid);
        mergeSort(index, mid + 1, end);
        merge(index, start, mid, end);
        return;
    }
    
    private void merge(int[] index, int start, int mid, int end) {
        int rightCount = 0;
        int i = start, j = mid + 1, k = start;
        for (int a = start; a <= end; a++) {
            helper[a] = index[a];
        }
        
        while (i <= mid || j <= end) {
            if (i > mid || j <= end && nums[helper[i]] > nums[helper[j]]) {
                rightCount++;
                index[k++] = helper[j++];
            } else {
                count[helper[i]] += rightCount;
                index[k++] = helper[i++];
            }
        }   
        return;
    }
}