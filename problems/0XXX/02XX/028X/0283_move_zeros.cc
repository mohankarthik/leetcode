#include "../../../../common/Includes.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        /* Preconditions */
        if (nums.size() == 0) return;
        
        for (j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        for (; i < nums.size(); i++) nums[i] = 0;
    }
};