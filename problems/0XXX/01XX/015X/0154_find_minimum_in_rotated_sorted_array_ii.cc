#include "../../../../common/Includes.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
            const int mid = low + ((high - low) / 2);
            if (nums[mid] > nums[high]) low = mid + 1;
            else if (nums[mid] < nums[high]) high = mid;
            else high--;
        }
        return nums[low];
    }
};