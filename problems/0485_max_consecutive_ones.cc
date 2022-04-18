#include "../common/Includes.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int currCnt = 0;
        
        /* Loop through the array */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currCnt++;
            } else {
                if (maxOnes < currCnt) {
                    maxOnes = currCnt;
                }
                currCnt = 0;
            }
        }
        
        /* Check for the end case */
        if (maxOnes < currCnt) {
            maxOnes = currCnt;
        }
        
        return maxOnes;
    }
};

int main(void) {
    Solution *sol = new Solution();
    vector<int> nums1 = {1,1,0,1,1,1};
    assert(sol->findMaxConsecutiveOnes(nums1) == 3);
    vector<int> nums2 = {1,0,1,1,0,1};
    assert(sol->findMaxConsecutiveOnes(nums2) == 2);
}