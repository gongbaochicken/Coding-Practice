//LintCode-Median II
//Numbers keep coming, return the median of numbers at every time a new number added.
//Trans: 数字是一个个不断进入数组的，在每次添加一个新的数字进入数组的同时，会返回当前新数组的中位数。
//Example
//For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3]

//For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3]

//For numbers coming list: [2, 20, 100], return [2, 2, 20]

class solution{
public:
	vector<int> medianII(vector<int>& nums){
		vector<int> result;
		if(nums.size() == 0) return result;
		int median = nums[0];
		priority_queue<int> maxHeap, minHeap;
		result.push_back(median);
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] < median){
				maxHeap.push(nums[i]);
			}else(nums[i] > median){
				minHeap.push(-nums[i]);
			}

			//Adjust if they are not balanced
			if(maxHeap.size() > minHeap.size()){
				minHeap.push(-median);
				median = maxHeap.top();
				maxHeap.pop();
			}else if(maxHeap.size() + 1 < minHeap.size()){ //maxHeap Size can have 1 more spot than minHeap's
				maxHeap.push(median);
				median = -minHeap.top();
				minHeap.pop();
			}
			result.push_back(median);
		}
		return result;
	}
}

//Time:O(nlogn) time