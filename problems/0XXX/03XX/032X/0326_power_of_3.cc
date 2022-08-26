#include "../../../../common/Includes.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        // const int maxPow3 = pow(3, floor(log(INT_MAX)/log(3)));
        // return ((n > 0) and ((maxPow3 % n) == 0));
        if (n < 1) return false;
        const float ans = log(n) / log(3);
        return pow(3, ans) == n;
    }
};