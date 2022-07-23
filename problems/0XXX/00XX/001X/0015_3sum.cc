#include "../../../../common/Includes.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        const int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if (i != 0 and nums[i - 1] == nums[i])
                continue;
            
            int j = i+1, k = n-1;
            while(j < k) {
                const int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    answer.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
                else if (sum > 0) k--;
                else j++;
            }
        }
        
        return answer;
    }
};