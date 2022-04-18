#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        /* Pass through the array, and for every number seen,
        negate the index, so that we encode a seen/unseen into 
        the existing array itself
        i.e.: If we see 1, then nums[1] is set to negative. At
        the end of the pass, any value we've not seen, will have
        it's nums[i] to be positive 
        We do the -1 because it's a 0 based index but numbers start from 1
        */
        for (int i = 0; i < nums.size(); i++) {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        
        /* Do a second pass, get all the positive values and insert
        into result */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) result.push_back(i + 1);
        }
        
        return result;
    }
};