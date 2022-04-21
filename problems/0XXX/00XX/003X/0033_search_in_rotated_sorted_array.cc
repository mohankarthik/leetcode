#include "../../../../common/Includes.h"

class Solution {
private:
    int n;
    int search_pivot(const vector<int>& nums) {
        int low = 0,high = n-1;
        while(low < high){
            const int mid = (low + ((high-low) / 2));
            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    int search_rotate(const vector<int>& nums, const int target, const int pivot) {
        int low = 0, high = n-1;
        while(low <= high){
            const int mid = (low + high) / 2;
            const int realMid=(mid + pivot) % n;
            if(nums[realMid]==target) return realMid;
            if(nums[realMid]<target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
public:
    int search(const vector<int>& nums, const int target) {
        /* Preconditions */
        if (nums.empty())
            throw invalid_argument("Nums is empty");
        
        /* Save the size */
        n = nums.size();
        int pivot = search_pivot(nums);
        
        return search_rotate(nums, target, pivot);
    }
};