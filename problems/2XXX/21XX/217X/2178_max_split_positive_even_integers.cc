#include "../../../../common/Includes.h"

#define ll long long
class Solution {
public:
    vector<long long> maximumEvenSplit(ll finalSum) {
        // Preconditions
        if (finalSum % 2 or finalSum < 0) return {};
        
        ll currSum = 0;
        ll i = 2;
        vector<ll> answer;
        
        while ((currSum + i) <= finalSum) {
            answer.push_back(i);
            currSum += i;
            i += 2;
        }
        
        answer.back() += (finalSum - currSum);
        return answer;
    }
};