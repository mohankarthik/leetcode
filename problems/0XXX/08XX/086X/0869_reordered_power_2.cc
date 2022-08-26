#include "../../../../common/Includes.h"

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string n_str = to_string(n);
        sort(n_str.begin(), n_str.end());
        for (int i = 0; i < 32; i++) {
            string temp = to_string(1<<i);
            if (temp.length() != n_str.length())
                continue;
            sort(temp.begin(), temp.end());
            if (temp == n_str)
                return true;
        }
        return false;
    }
};