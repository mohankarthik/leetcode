#include "../../../../common/Includes.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Preconditions
        if (nums.empty())
            return -1;
        
        int mid, left = 0, right = nums.size()-1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> people1{-1,0,3,5,9,12};
    assert(sol->search(people1, 9) == 4);
    vector<int> people2{-1,0,3,5,9,12};
    assert(sol->search(people2, 2) == -1);
}