#include "../../../../common/Includes.h"

class Solution {
private:
    int do_dp(vector<int>& nums) {
        const int n = nums.size();
        int dp[2501];
        for (int i = 0; i < n; i++)
            dp[i] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    break;
                }
            }
        }
        
        return dp[n-1];
    }
    
    int do_greedy(vector<int>& nums) {
        vector<int> sub, subIdx;
        const int n = nums.size();
        vector<int> path(n, -1);
        for (int i = 0; i < n; i++) {
            if (sub.empty() or sub.back() < nums[i]) {
                path[i] = sub.empty() ? -1 : subIdx.back();
                sub.emplace_back(nums[i]);
                subIdx.emplace_back(i);
            } else {
                const int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                path[i] = (idx == 0) ? -1 : subIdx[idx-1];
                sub[idx] = nums[i];
                subIdx[idx] = i;
            }
        }
        vector<int> ans;
        int t = subIdx.back();
        while (t != -1) {
            ans.push_back(nums[t]);
            t = path[t];
        }
        reverse(ans.begin(), ans.end());
        for (int num: ans) cout << num << " ";
        cout << endl;
        return sub.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return do_greedy(nums);
    }
};