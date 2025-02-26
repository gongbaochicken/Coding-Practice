//Kth Largest Element in an Array
/*Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

//Solution 1:
//Cost: O(N*logN), build heap and doing all heapfy
//push: O(logN), pop(): O(logN)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> Q(nums.begin(), nums.end());
        for(int i = 0; i < k-1; i++){
            Q.pop();
        }
        return Q.top();
    }
};

//Solution 2:
//Cost: O(N).  Note that since we only need to consider one half of the array, the time complexity is O(n)
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};

// Other: smallest k elements of array
int partition(vector<int>& v, int left, int right) {
    int pivot = v[left];
    int l = left+1, r = right;
    while(l <= r) {
        if (v[l] > pivot && pivot > v[r])
            swap(v[l++], v[r--]);
        if (v[l] <= pivot) l++;
        if (v[r] >= pivot) r--;
    }
    swap(v[left], v[r]);
    return r;
}