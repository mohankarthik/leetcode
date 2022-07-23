#include "../../../../common/Includes.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int maxReached = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxReached)
                return false;
            maxReached = max(maxReached, i + nums[i]);
            cout << i << " " << maxReached << endl;
            if (maxReached >= n-1)
                return true;
        }
        return false;
    }
};