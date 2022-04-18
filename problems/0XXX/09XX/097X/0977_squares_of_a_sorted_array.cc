#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        /* Create the response array */
        vector<int> ans = A;
        
        int s = 0;
        int t = A.size() - 1;
        int c = A.size() - 1;
        
        while(s <= t) {
            ans[c] = (abs(A[s]) < abs(A[t])) ? (A[t] * A[t--]) : (A[s] * A[s++]);
            c--;
        }
        
        return ans;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> nums1 = {-4,-1,0,3,10};
    vector<int> res1 = {0,1,9,16,100};
    assert(sol->sortedSquares(nums1) == res1);
    vector<int> nums2 = {-7,-3,2,3,11};
    vector<int> res2 = {4,9,9,49,121};
    assert(sol->sortedSquares(nums2) == res2);
    return 0;
}