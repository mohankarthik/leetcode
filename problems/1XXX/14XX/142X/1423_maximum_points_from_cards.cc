#include "../../../../common/Includes.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int frontScore = 0, rearScore = 0;
        const int n = cardPoints.size();
        
        
       for (int i = 0; i < k; i++) {
            frontScore += cardPoints[i];
        }
        
        int maxScore = frontScore;
        
        for (int i = k-1; i>=0; i--) {
            rearScore += cardPoints[n-(k-i)];
            frontScore -= cardPoints[i];
            maxScore = max(maxScore, rearScore+frontScore);
        }
        
        return maxScore;
    }
};