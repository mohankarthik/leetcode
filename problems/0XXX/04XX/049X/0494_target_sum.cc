#include "../../../../common/Includes.h"

class Solution {
private:
    map <pair<int,int>,int> _map;
public:
    int findTargetSumWays(vector<int>& nums, int S, int idx=0, int sum=0) {
        /* Exit case */
        if (idx >= nums.size())
        {
            if (sum == S) return 1;
            else return 0;
        }
        
        /* Check if we've already seen the result */
        if (!_map.count({idx,sum}))
            _map[{idx,sum}] = findTargetSumWays(nums, S, idx+1, sum+nums[idx])
                + findTargetSumWays(nums, S, idx+1, sum-nums[idx]);
        
        return _map[{idx,sum}];
    }
};