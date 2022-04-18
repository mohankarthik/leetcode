#include "../../../../common/Includes.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        /* Preconditions */
        if (nums.size() == 0) return 0;
        
        /* Sort */
        sort(nums.begin(), nums.end());
        
        /* Sum alternate elements */
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        
        return sum;
    }
};