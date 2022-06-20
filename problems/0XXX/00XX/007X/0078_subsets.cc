#include "../../../../common/Includes.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = nums.size();
        const int max = (1 << n);
        
        vector<vector<int>> answer;
        for (int i = 0; i < max; i++) {
            answer.push_back({});
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    answer.back().push_back(nums[j]);
                }
            }
        }
        
        return answer;
    }
};