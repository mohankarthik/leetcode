#include "../../../../common/Includes.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);
        
        sort(nums.begin(), nums.end());
        
        const int n = nums.size();
        int answer = 0;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                const int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < minDiff) {
                    minDiff = abs(target - sum);
                    answer = sum;
                }
                if (sum > target) right--;
                else left++;
            }
        }
        
        return answer;
    }
};