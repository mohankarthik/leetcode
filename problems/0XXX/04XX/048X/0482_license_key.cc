#include "../../../../common/Includes.h"

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int i = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (*it == '-') continue;
            if ((i % k) == 0) res += '-';
            i++;
            res += toupper(*it);
        }
        if (res.begin() != res.end())
            res.erase(res.begin());
        reverse(res.begin(), res.end());
        return res;
    }
};