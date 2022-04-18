#include "../../../../common/Includes.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int result = INT_MAX;
        
        /* Two pointer loop */
        while(r < n) {
            sum += nums[r++];
            while(sum >= s) {
                result = min(result, r-l);
                sum -= nums[l++];
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};