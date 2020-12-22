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
    int climbStairs(int n)
    {
        assert(n != 0);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->climbStairs(1) == 1);
    assert(sol->climbStairs(2) == 2);
    assert(sol->climbStairs(3) == 3);
}