#include "../../../../common/Includes.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Preconditions
        if (nums.empty())
            return -1;
        
        int mid, left = 0, right = nums.size()-1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};