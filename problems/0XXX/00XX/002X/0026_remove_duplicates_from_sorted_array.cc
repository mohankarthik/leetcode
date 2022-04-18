#include "../../../../common/Includes.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        
        /* Handle the corner case */
        if (nums.size() == 0) return 0;
        
        while(j < nums.size()) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
            j++;
        }
        
        return i+1;
    }
};