//  QuickSort
//  Created by Jason Zhuo Jia on 7/27/15.
//
//Average Time Cost: T(N) = 2T(N/2)+O(N)===> T(N) = O(NlogN)
//Worst Time: T(n) = T(n - 1) + O(n), T(n) = O(n^2).
//Space: O(NlgN)
//Unstable Sort


#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

//Use partition to make sure the left part are smaller than
//pivot and the right part are larger than pivot, and return the
//pivote as the separate point to do divide and conqure.
int partition(vector<int>& nums, int front, int end){
    int pivot = nums[front];
    while(front < end){
        //Although there are two while statements, but only one will
        //meet the condidition and will be executed.
        //Very begining, left point does not move, right pointer moves.
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
    //Pivot will be at the right place
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
