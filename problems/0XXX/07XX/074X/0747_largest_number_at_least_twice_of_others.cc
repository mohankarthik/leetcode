#include "../../../../common/Includes.h"

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        int max_idx = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (max1 < nums[i]) {
                max2 = max1;
                max1 = nums[i];
                max_idx = i;
            } 
            if ((max2 < nums[i]) && (max1 != nums[i])) {
                max2 = nums[i];
            }
        }
        
        if (max1 >= (2 * max2)) return max_idx;
        return -1;
    }
};