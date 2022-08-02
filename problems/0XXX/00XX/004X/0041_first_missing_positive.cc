#include "../../../../common/Includes.h"

class Solution {
private:
    bool checkForOne(const vector<int>& nums, int n) {
        /* check if 1 is missing */
        bool oneFound = false;
        for (int num: nums)
            if (num == 1) {
                oneFound = true;
                break;
            }
        
        return oneFound;
    }
    
    void replaceOutOfRangeWithOne(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 or nums[i] > n) {
                nums[i] = 1;
            }
        }
    }
    
    void markAvailable(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            const int temp = abs(nums[i]);
            if (temp == n)
                nums[0] = - abs(nums[0]);
            else
                nums[temp] = - abs(nums[temp]);
        }
    }
    
    int countFirstPositive(vector<int>& nums, int n) {
        for (int i = 1; i < n; i++)
            if (nums[i] > 0)
                return i;

        if (nums[0] > 0)
            return n;
        
        return n+1;
    }
    
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        
        if (!checkForOne(nums, n))
            return 1;
        
        replaceOutOfRangeWithOne(nums, n);
        
        markAvailable(nums, n);
        
        return countFirstPositive(nums, n);
    }
};