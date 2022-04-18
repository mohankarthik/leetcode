#include "../../../../common/Includes.h"

class Solution {
private:
    int badVersion;
    bool isBadVersion(int n) {
        return n >= badVersion;
    }
public:
    void setFirstBadVersion(int n) {
        badVersion = n;
    }

    int firstBadVersion(int n) {
        int mid, low = 1, high = n;
        int ans = INT_MAX;
        while (low <= high) {
            mid = (int)(((long long)low + (long long)high) / 2);
            if (isBadVersion(mid)) {
                ans = min(ans,mid);
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    sol->setFirstBadVersion(4);
    assert(sol->firstBadVersion(5) == 4);
    sol->setFirstBadVersion(1);
    assert(sol->firstBadVersion(1) == 1);
}
