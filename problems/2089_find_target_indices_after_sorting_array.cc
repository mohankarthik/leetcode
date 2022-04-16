#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int num_lower = 0, num_occurances = 0;
        
        // Count the number of smaller and matching elements
        for (int n: nums) {
            if (n < target) {
                num_lower++;
            } else if (n == target) {
                num_occurances++;
            }
        }
        
        vector<int> answer = vector<int>();
        for (int i = 0; i < num_occurances; i++) {
            answer.push_back(num_lower + i);
        }
        return answer;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> nums{1,2,5,2,3};
    auto ans1 = sol->targetIndices(nums, 2);
    assert(ans1.size() == 2);
    assert(ans1[0] == 1);
    assert(ans1[1] == 2);
    auto ans2 = sol->targetIndices(nums, 3);
    assert(ans2.size() == 1);
    assert(ans2[0] == 3);
    auto ans3 = sol->targetIndices(nums, 5);
    assert(ans3.size() == 1);
    assert(ans3[0] == 4);
}