#include "../../../../common/Includes.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            throw invalid_argument("Nums is empty");
        if (nums.size() == 1)
            return 0;
        
        int n = nums.size();
        
        int low = 0, high = n-1;
        while(low < high) {
            const int mid = low + ((high - low) / 2);
            if (nums[mid] > nums[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};