//Kth Largest Element in an Array
/*Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

//Solution 1:
//Cost: O(N*logN)
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


// Kth Smallest 
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

int quickKthLarge(vector<int>& v, int k){
    int l = 0, r = v.size()-1;
    while (true) {
        int pivot = partition(v, l, r);
        if (pivot == k-1) return v[pivot];
        if (pivot > k-1) {
            r = pivot-1;
        } else {
            l = pivot+1;
        }
    }
    return -1;
}

// quick sort in ascending order:
// Quick Sort
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

void quickSortHelper(vector<int>& nums, int front, int end){
    if(front > end) return;
    //Pivot will be at the right place
    int pivot = partition(nums, front, end);
    quickSortHelper(nums, front, pivot-1);
    quickSortHelper(nums, pivot+1, end);
}
