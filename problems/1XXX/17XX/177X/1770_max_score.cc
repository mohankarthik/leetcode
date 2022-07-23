#include "../../../../common/Includes.h"

using IntPair = std::pair<int, int>;

struct IntPairHash {
    static_assert(sizeof(int) * 2 == sizeof(size_t));

    size_t operator()(IntPair p) const noexcept {
        return size_t(p.first) << 32 | p.second;
    }
};

class Solution {
private:
    vector<int> nums;
    vector<int> multipliers;
    int n, m;
    int recurse();
    long mem[1001][1001];
    
    int recurse(int i, int l) {
        if (i >= m)
            return 0;
        const int r = (n - 1) - (i - l);
        if (mem[i][l] != LONG_MIN)
            return mem[i][l];
        
        const int left = (multipliers[i] * nums[l]) + recurse(i+1, l+1);
        const int right = (multipliers[i] * nums[r]) + recurse(i+1, l);
        mem[i][l] = max(left, right);
        return mem[i][l];
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        this->nums = nums;
        this->multipliers = multipliers;
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 1001; j++) 
                mem[i][j] = LONG_MIN;
        
        return recurse(0,0);
    }
};