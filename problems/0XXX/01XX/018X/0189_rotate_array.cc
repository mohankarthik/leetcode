#include "../../../../common/Includes.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        /* Preconditions */
        if (n == 0) return;
        
        /* Take mod, since k > n dosen't matter and will wrap around */
        k = k % n;
        
        /* Do the black magic, where 3 reverses = shifting */
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};