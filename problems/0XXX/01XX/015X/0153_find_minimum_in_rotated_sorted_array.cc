#include "../../../../common/Includes.h"

/* Tests
[3,4,5,1,2]
[4,5,6,7,0,1,2]
[11,13,15,17]
[-2,-1,-4,-3]
[0]
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            throw invalid_argument("Nums is empty");
        
        const int n = nums.size();
        int left = 0, right = n-1;
        
        while(left < right) {
            const int mid = left + ((right - left) / 2);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};