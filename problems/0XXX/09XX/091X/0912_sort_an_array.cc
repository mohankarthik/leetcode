#include "../../../../common/Includes.h"
class MergeSort {
private:
    void _outPlaceMerge(vector<int> &nums, int low, int mid, int high) {
        if (low >= high) 
            return;
        
        int left = low, right = mid + 1, i = 0, size = high - low + 1;
        
        vector<int> sorted(size, 0);
        while (left <= mid and right <= high)
            sorted[i++] = nums[left] < nums[right] ? nums[left++] : nums[right++];
        while (left <= mid) 
            sorted[i++] = nums[left++];
        while (right <= high) 
            sorted[i++] = nums[right++];
        
        for (i = 0; i < size; i++)
            nums[i + low] = sorted[i];
    }
    
    void _inPlaceMerge(vector<int> &nums, int low, int mid, int high) {
        if (low >= high)
            return;
        
        int left = low, right = mid + 1, size = high - low + 1;
        
        while (left <= mid and right <= high) {
            if (nums[left] <= nums[right]) 
                left++;
            else {
                int val = nums[right];
                for (int i = right++; i > left; i--) {
                    nums[i] = nums[i - 1];
                }
                nums[left++] = val;
                mid++;
            }
        }
    }
public:
    void recursiveSort(vector<int>& nums, int low, int high) {
        if (low >= high) 
            return;
        const int mid = (high - low) / 2 + low;
        recursiveSort(nums, low, mid);
        recursiveSort(nums, mid + 1, high);
        _outPlaceMerge(nums, low, mid, high);
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort* sorter = new MergeSort();
        sorter->recursiveSort(nums, 0, nums.size()-1);
        return nums;
    }
};