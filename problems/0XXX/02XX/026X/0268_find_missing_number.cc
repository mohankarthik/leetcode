#include "../../../../common/Includes.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int nums_xor = n;
        for (int i = 0; i < n; i++)
            nums_xor ^= i ^ nums[i];
        return nums_xor;
    }
};