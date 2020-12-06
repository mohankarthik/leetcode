#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>

using namespace std;

class Solution
{
private:
    set<string> _seen;
    queue<pair<string, int>> _q;

    char _shiftLever(char ch, bool Up)
    {
        int val = ch - '0';
        val = Up ? val + 1 : val - 1;
        if (val < 0)
            val += 10;
        else if (val >= 10)
            val -= 10;
        return val + '0';
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        /* Corner case, find if the starting point is in deadends */
        for (int i = 0; i < deadends.size(); i++)
            if (deadends[i] == "0000")
                return -1;

        /* Push the start state */
        _q.push({"0000", 0});

        /* Add the deadends into the seen list so we don't go through them */
        for (int i = 0; i < deadends.size(); i++)
            _seen.insert(deadends[i]);

        while (!_q.empty())
        {
            /* Get the first element */
            auto cur = _q.front();
            string val = cur.first;
            int steps = cur.second;
            _q.pop();

            /* If already seen, continue */
            if (_seen.find(val) != _seen.end())
                continue;

            /* Mark this as seen */
            _seen.insert(val);

            /* Check if it matches our target */
            if (val == target)
                return steps;

            /* Add all possible transitions, as long as we've not seen them */
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    string newVal = val;
                    newVal[i] = _shiftLever(val[i], j);
                    if (_seen.find(newVal) == _seen.end())
                        _q.push({newVal, steps + 1});
                }
            }
        }

        return -1;
    }

    void clear(void)
    {
        _seen.clear();
        while (!_q.empty())
            _q.pop();
    }
};

int main(void)
{
    Solution *sol = new Solution();

    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    sol->clear();
    assert(sol->openLock(deadends, target) == 6);

    deadends = {"8888"};
    target = "0009";
    sol->clear();
    assert(sol->openLock(deadends, target) == 1);

    deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    target = "8888";
    sol->clear();
    assert(sol->openLock(deadends, target) == -1);

    deadends = {"0000"};
    target = "8888";
    sol->clear();
    assert(sol->openLock(deadends, target) == -1);
}