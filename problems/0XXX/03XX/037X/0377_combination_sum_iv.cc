#include "../../../../common/Includes.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        uint64_t dp[target+1];
        memset(dp, 0ull, sizeof(dp));
        dp[0] = 1ull;
        
        for (int i = 1; i <= target; i++) {
            for (const int val: nums) {
                if (i >= val)
                    dp[i] += dp[i-val];
            }
        }
        
        return (int)dp[target];
    }
};