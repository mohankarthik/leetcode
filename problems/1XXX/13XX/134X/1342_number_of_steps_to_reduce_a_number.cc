#include "../../../../common/Includes.h"

class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num)
        {
            count++;
            if (num % 2) num -= 1;
            else num >>= 1;
        }
        return count;
    }
};