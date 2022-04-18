#include "../../../../common/Includes.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> max(3, LLONG_MIN);
        
        if (nums.size() == 0) return 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (max[0] < nums[i]) {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = nums[i];
            }
            if ((max[1] < nums[i]) && (nums[i] != max[0])) {
                max[2] = max[1];
                max[1] = nums[i];
            }
            if ((max[2] < nums[i]) && (nums[i] != max[0]) && (nums[i] != max[1])) {
                max[2] = nums[i];
            }
        }
        
        if (max[2] == LLONG_MIN) {
            return max[0];
        } else {
            return max[2];
        }
    }
};