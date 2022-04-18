#include "../common/Includes.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
            
        int mid, low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (nums[mid] == target)
                return mid;
            if (nums[low] > target)
                return low;
            if (nums[high] < target)
                return high + 1;
            
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        assert(false);
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> nums{1,3,5,6};
    assert(sol->searchInsert(nums, 5) == 2);
    assert(sol->searchInsert(nums, 2) == 1);
    assert(sol->searchInsert(nums, 7) == 4);
}