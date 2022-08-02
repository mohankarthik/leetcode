#include "../../../../common/Includes.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, INT_MAX);
        
        int farthest = 0;
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > farthest)
                return -1;
            
            farthest = max(farthest, i + nums[i]);
            for (int j = 1; j <= nums[i]; j++)
                if (i+j < n)
                    dp[i+j] = min(dp[i+j], dp[i]+1);
        }
        
        if (dp.back() == INT_MAX)
            return -1;
        return dp.back();
    }
};