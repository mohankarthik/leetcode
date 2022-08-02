#include "../../../../common/Includes.h"

class Solution {
private:
    int n;
    void permuteUniqueHelper(int idx, vector<int>& nums, vector<vector<int>>& result) {
        if (idx == n) { 
            result.push_back(nums); 
            return; 
        }
        
        unordered_set<int> temp;
        for (int i = idx; i < n; i++) {
            if (temp.count(nums[i]) > 0)
                continue;
            
            temp.insert(nums[i]);
            swap(nums[idx], nums[i]);
            permuteUniqueHelper(idx + 1, nums, result);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->n = nums.size();
        vector<vector<int>> result;
        permuteUniqueHelper(0, nums, result);
        return result;
    }
};