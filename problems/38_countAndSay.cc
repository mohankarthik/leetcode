#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        int sz = s.length();
        char cur = s[0];
        int curLen = 1;
        std::stringstream buffer;
        for (int i = 1; i < sz; i++)
        {
            if (s[i] == cur)
                curLen++;
            else
            {
                buffer << curLen << cur;
                curLen = 1;
                cur = s[i];
            }
        }
        buffer << curLen << cur;
        return buffer.str();
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->countAndSay(1) == "1");
    assert(sol->countAndSay(4) == "1211");
}