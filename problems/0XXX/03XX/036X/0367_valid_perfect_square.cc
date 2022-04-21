#include "../../../../common/Includes.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num;
        
        while(low <= high) {
            const int mid = low + ((high - low) / 2);
            const long long sq = (long long)mid * (long long)mid;
            if (sq == num) return true;
            if (sq > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};