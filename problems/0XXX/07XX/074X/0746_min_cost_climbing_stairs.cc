#include "../../../../common/Includes.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        int prevToPrevStep = 0;
        int prevStep = cost[0];
        int currStep = 0;
        
        for (int i = 2; i <= n; i++) {
            currStep = cost[i-1] + min(prevStep, prevToPrevStep);
            prevToPrevStep = prevStep;
            prevStep = currStep;
        }
        
        return min(prevStep, prevToPrevStep);
    }
};