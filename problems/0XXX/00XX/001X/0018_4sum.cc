#include "../../../../common/Includes.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n < 4) return {};
        
        sort(nums.begin(), nums.end());
        
        unordered_set<vector<int>> set;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int left = j+1;
                int right = n-1;
                while(left < right) {
                    const int64_t sum = (int64_t)nums[i] + (int64_t)nums[j] + (int64_t)nums[left] + (int64_t)nums[right];
                    if (sum == (int64_t)target) {
                        set.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                    }
                    else if (sum > (int64_t)target) 
                        right--;
                    else 
                        left++;
                }
            }
        }
        
        vector<vector<int>> answer(set.begin(), set.end());
        return answer;
    }
};