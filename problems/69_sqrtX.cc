#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

using namespace std;

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