#include "../../../../common/Includes.h"
/*
[1,2,3,4,5]
[1,2,3,5,4]
[1,2,4,3,5]
[1,2,4,5,3]
[1,2,5,3,4]
[1,2,5,4,3]
[1,3,2,4,5]

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};