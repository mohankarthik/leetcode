#include "../../../../common/Includes.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        
        for (int num: nums) {
            sum += num;
            smax = max(sum, smax);
            if (sum < 0) sum = 0;
        }
        
        return smax;
        
    }
};