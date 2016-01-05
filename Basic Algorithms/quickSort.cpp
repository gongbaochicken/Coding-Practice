//  QuickSort
//  Created by Jason Zhuo Jia on 7/27/15.
//
//Average Time Cost: T(N) = T(N/2)+O(N)===> T(N) = O(NlogN)
//Worst: T(n) = T(n - 1) + O(n), T(n) = O(n^2).

#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int front, int end){
    int pivot = nums[front];
    while(front < end){
        while(nums[front] < pivot){
            front++;
        }
        while(nums[end] > pivot){
            end--;
        }
        if(front >= end) break;
        swap(nums[front], nums[end]);
    }
    return front;
}

void quickSortHelper(vector<int>& nums, int front, int end){
    if(front > end) return;
    int pivot = partition(nums, front, end);
    quickSortHelper(nums, front, pivot-1);
    quickSortHelper(nums, pivot+1, end);
}

void quickSort(vector<int>& nums){
    int len = (int) nums.size();
    if(len == 0) return;
    quickSortHelper(nums, 0, len-1);
}


/****************Test for Quick Sort********************/
void printV(vector<int>& ve){
    for (int j = 0; j < ve.size(); j++) {
        printf("%d ", ve[j]);
    }
    printf("\n");
}

int main() {
    vector<int> v1={1,9,5,7,2,6};
    printV(v1);
    quickSort(v1);
    printV(v1);
    
    return 0;
}

