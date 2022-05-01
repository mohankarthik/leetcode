#include "../../../../common/Includes.h"

class Solution {
private:
    int _using_linked_list(const vector<int>& nums) {
        int p1 = nums[0];
        int p2 = nums[0];
        
        do {
            p1 = nums[p1];
            p2 = nums[nums[p2]];
        } while (p1 != p2);
        
        p1 = nums[0];
        while(p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
    
    int _using_binary_search(const vector<int>& nums) {
        auto count_small = [&](int cur) {
            int count = 0;
            for (auto &num: nums) {
                if (num <= cur)
                    count++;
            }
            return count;
        };
        
        int low = 1, high = nums.size();
        int answer = -1;
        while (low <= high) {
            const int mid = low + ((high - low) / 2);
            if (count_small(mid) > mid) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return answer;
    }
public:
    int findDuplicate(vector<int>& nums) {
        return _using_linked_list(nums);
    }
};