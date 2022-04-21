#include "../../../../common/Includes.h"

class Solution {
    int val;
    int guess(int num) {
        if (num > val) return -1;
        else if (num < val) return 1;
        else return 0;
    }
public:
    void setNum(int val) {
        val = val;
    }
    int guessNumber(int n) {
        int high = n, low = 1;
        int mid;
        while(low <= high) {
            mid = low + ((high - low)/2);
            int ret = guess(mid);
            if (ret == 0)
                return mid;
            else if (ret == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};