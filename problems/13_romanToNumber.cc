#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

using namespace std;

class Solution
{
private:
    map<char, int> _romanMap;
    void _initMap(void)
    {
        _romanMap['M'] = 1000;
        _romanMap['D'] = 500;
        _romanMap['C'] = 100;
        _romanMap['L'] = 50;
        _romanMap['X'] = 10;
        _romanMap['V'] = 5;
        _romanMap['I'] = 1;
    }

public:
    Solution()
    {
        _initMap();
    }

    int romanToInt(string s)
    {
        int n = s.length();
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                val += _romanMap[s[i]];
            }
            else if ((s[i] == 'C') && (s[i + 1] == 'M'))
            {
                val += 900;
            }
            else if ((s[i] == 'C') && (s[i + 1] == 'D'))
            {
                val += 400;
            }
            else if ((s[i] == 'X') && (s[i + 1] == 'C'))
            {
                val += 90;
            }
            else if ((s[i] == 'X') && (s[i + 1] == 'L'))
            {
                val += 40;
            }
            else if ((s[i] == 'I') && (s[i + 1] == 'X'))
            {
                val += 9;
            }
            else if ((s[i] == 'I') && (s[i + 1] == 'V'))
            {
                val += 4;
            }
            else
            {
                val += _romanMap[s[i]];
                i--;
            }
            i++;
        }

        return val;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->romanToInt("III") == 3);
    assert(sol->romanToInt("IV") == 4);
    assert(sol->romanToInt("IX") == 9);
    assert(sol->romanToInt("LVIII") == 58);
    assert(sol->romanToInt("MCMXCIV") == 1994);
}