#include "../../../../common/Includes.h"

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int diff = 0;
        for(int i: nums)
        {
            if (i == 1)
            {
                if (diff > 0) return false;
                diff = k;
            }
            else diff--;
        }
        return true;
    }
};