#include "../../../../common/Includes.h"

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
        {
            return x;
        }

        uint32_t hi = (uint32_t)x, lo = 0;
        uint32_t mid;
        while (lo < (hi - 1))
        {
            mid = ((hi + lo) / 2);
            uint32_t val = mid * mid;
            if (val == x)
            {
                return mid;
            }
            if (val > x)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo - 1;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->mySqrt(4) == 2);
    assert(sol->mySqrt(8) == 2);
}