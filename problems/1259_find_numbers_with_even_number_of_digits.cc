/* Algorithm */
#include <algorithm>

/* Error */
#include <cassert>
#include <exception>
#include <stdexcept>

/* String */
#include <string>

/* Contains */
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <span>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int digits = 0;
            int num = nums[i];
            while(num) {
                digits++;
                num /= 10;
            }
            if ((digits % 2) == 0) ans++;
        }
        
        return ans;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> nums1 = {12,345,2,6,7896};
    assert(sol->findNumbers(nums1) == 2);
    vector<int> nums2 = {555,901,482,1771};
    assert(sol->findNumbers(nums2) == 1);
    return 0;
}