#include "../../../../common/Includes.h"

class Solution {
private:
    vector<vector<int>> answer;
    vector<int> curr;
    unordered_set<int> seen;
    vector<int> nums;
    
    void _dfs(int n) {
        if (n == 0) {
            answer.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if(seen.count(nums[i]) == 0) {
                seen.insert(nums[i]);
                curr.push_back(nums[i]);
                _dfs(n-1);
                seen.erase(nums[i]);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        _dfs(nums.size());
        return answer;
    }
};