#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        
        /* Preconditions */
        if (nums.size() == 0) return result;
        
        /* Setup a hash table */
        map<int, int> mem;
        
        for (int i = 0; i < nums.size(); i++) {
            auto itr = mem.find(target - nums[i]);
            if (itr != mem.end()) {
                result[0] = itr->second;
                result[1] = i;
                break;
            }
            mem.insert({nums[i], i});
        }
        
        return result;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> nums1 = {2,7,11,15};
    vector<int> res1 = {0,1};
    assert(sol->twoSum(nums1, 9) == res1);
    vector<int> nums2 = {3,2,4};
    vector<int> res2 = {1,2};
    assert(sol->twoSum(nums2, 6) == res2);
    vector<int> nums3 = {3,3};
    vector<int> res3 = {0,1};
    assert(sol->twoSum(nums3, 6) == res2);
    return 0;
}