#include "../../../../common/Includes.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left_sum = 0, right_sum = 0;
        int ans = -1;
        
        /* Calculate the right sum */
        for (int num: nums)
            right_sum += num;
        
        for (int i = 0; i < n; i++) {
            if (left_sum == (right_sum - nums[i]))
                return i;
            
            left_sum += nums[i];
            right_sum -= nums[i];
        }
        
        return -1;
    }
};