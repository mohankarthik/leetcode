#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        /* Preconditions */
        assert(n >= 0);
        if (n == 0)
            return 0;

        unordered_set<int> _seen;
        queue<pair<int, int>> _q;
        _q.push({0, 0});

        while (!_q.empty())
        {
            /* Get the value */
            const auto val = _q.front();
            _q.pop();

            /* Check if we've reached the exit condition */
            if (val.first == n)
                return val.second;

            /* Mark as seen */
            _seen.insert(val.first);

            /* Add all possible squares to it */
            int i = 1;
            int newval = val.first + (i * i);
            while (newval <= n)
            {
                /* If we find the answer, then huzzah */
                if (newval == n)
                    return val.second + 1;

                /* Check if we've not seen the new value */
                if (_seen.count(newval) == 0)
                {
                    _q.push({newval, val.second + 1});
                    _seen.insert(newval);
                }

                /* Increment to the next integer */
                i++;
                newval = val.first + (i * i);
            }
        }

        /* We should never come here */
        assert(false);
        return -1;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->numSquares(0) == 0);
    assert(sol->numSquares(16) == 1);
    assert(sol->numSquares(41) == 2);
    assert(sol->numSquares(12) == 3);
    assert(sol->numSquares(13) == 2);
}