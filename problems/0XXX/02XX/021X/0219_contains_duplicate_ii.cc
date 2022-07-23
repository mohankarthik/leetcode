#include "../../../../common/Includes.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mem;
        const int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (mem.find(nums[i]) != mem.end()) {
                if ((i - mem[nums[i]]) <= k)
                    return true;
            }
            mem[nums[i]] = i;
        }
        
        return false;
    }
};