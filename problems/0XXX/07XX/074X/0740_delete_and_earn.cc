#include "../../../../common/Includes.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int,int> mem;
        int maxNumber = 0;
        for(const int num: nums) {
            mem[num] += num;
            maxNumber = max(maxNumber, num);
        }
        
        int n = mem.size();
        int dp[maxNumber+1];
        dp[0] = 0;
        dp[1] = mem.count(1) ? mem[1] : 0;
        int i = 2;
        for (int i = 2; i <= maxNumber; i++) {
            int gain = mem.count(i) ? mem[i] : 0;
            dp[i] = max(dp[i-1], gain + dp[i-2]);
        }
        return max(dp[maxNumber], dp[maxNumber-1]);
    }
};