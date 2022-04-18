#include "../../../../common/Includes.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        /* Find the maximum sub array in the middle that's sum(nums) - x. If so found, then the outside 
         * is the answer */
        /* Get the total */
        int total = 0;
        for (int val: nums) total += val;
        
        /* This is what we need to find a subarray for */
        int target = total - x;
        if (target == 0) return n;
        
        /* Do a sliding window to find the longest sub array */
        int l = 0, r = 0;
        int sum = 0;
        int longest = -1;
        while (l < n && r < n)
        {
            if (sum < target)
            {
                sum += nums[r++];
            }
            else if (sum > target)
            {
                sum -= nums[l++];
            }
            else
            {
                longest = max(longest, r-l);
                sum -= nums[l++];
            }
        }
        /* Handle the left over condition */
        if (sum == target) longest = max(longest, r-l);
        /* Handle the corner case, where we did not find a sub array */
        if (longest == -1) return longest;
        /* Return the length of outside the sub array */
        return n-longest;
    }
};