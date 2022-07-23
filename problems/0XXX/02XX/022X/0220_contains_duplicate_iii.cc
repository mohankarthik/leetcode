#include "../../../../common/Includes.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> mem;
        
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            const long x = nums[i];
            if (i > k) mem.erase(nums[i-k-1]);
            
            const auto pos = mem.lower_bound(x - t);
            if (pos != mem.end() && *pos - x <= t) return true;
            
            mem.insert(nums[i]);
        }
        return false;
    }
};