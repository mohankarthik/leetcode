#include "../common/Includes.h"

class Solution
{
public:
    int reverse(int x)
    {
        bool bNegative = x < 0 ? true : false;
        int64_t a = x < 0 ? -(int64_t)x : (int64_t)x;

        int64_t y = 0;
        while (a)
        {
            y *= 10;
            y += a % 10;
            a /= 10;
        }

        if (y > (1LL << 31LL))
            return 0;

        return bNegative ? -y : y;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->reverse(123) == 321);
    assert(sol->reverse(-123) == -321);
    assert(sol->reverse(120) == 21);
    assert(sol->reverse(0) == 0);
    assert(sol->reverse(1534236469) == 0);
    assert(sol->reverse(-2147483648) == 0);
}