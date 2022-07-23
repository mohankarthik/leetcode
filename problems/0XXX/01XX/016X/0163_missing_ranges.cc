#include "../../../../common/Includes.h"

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> answer;
        
        nums.insert(nums.begin(), lower-1);
        nums.push_back(upper+1);
        
        const int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]+1) {
                stringstream iss;
                if (nums[i]-1 > nums[i-1]+1) {
                    iss << nums[i-1]+1 << "->" << nums[i]-1;
                } else {
                    iss << nums[i]-1;
                }
                answer.push_back(iss.str());
            }
        }
        
        return answer;
    }
};