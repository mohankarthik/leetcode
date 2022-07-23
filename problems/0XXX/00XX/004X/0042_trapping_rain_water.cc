#include "../../../../common/Includes.h"

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        
        vector<int> leftMax(n), rightMax(n);
        
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(height[i], leftMax[i-1]);
        
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
            rightMax[i] = max(height[i], rightMax[i+1]);
        
        int answer = 0;
        for (int i = 1; i < n-1; i++)
            answer += min(leftMax[i], rightMax[i]) - height[i];
        
        return answer;
    }
};