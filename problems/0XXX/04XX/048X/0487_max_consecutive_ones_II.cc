#include "../../../../common/Includes.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, ones = 0, ones_and_zeros = 0;
        
        for (int n: nums) {
            if (n == 1) {
                ones++;
                ones_and_zeros++;
            } else {
                ones_and_zeros = ones + 1;
                ones = 0;
            }
            
            ans = max(ans, ones_and_zeros);
        }
        
        return ans;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> nums1 = {1,0,1,1,0};
    assert(sol->findMaxConsecutiveOnes(nums1) == 4);
    vector<int> nums2 = {1,0,1,1,0,1};
    assert(sol->findMaxConsecutiveOnes(nums1) == 4);
    return 0;
}