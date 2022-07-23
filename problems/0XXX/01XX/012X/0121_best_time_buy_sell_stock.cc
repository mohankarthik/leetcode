#include "../../../../common/Includes.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int answer = 0;
        for (int num: prices) {
            minVal = min(minVal, num);
            answer = max(answer, num - minVal);
        }
        return answer;
    }
};