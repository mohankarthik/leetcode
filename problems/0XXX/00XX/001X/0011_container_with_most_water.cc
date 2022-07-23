#include "../../../../common/Includes.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        int l = 0, r = n-1;
        
        int answer = 0;
        while (l < r) {
            answer = max(answer, min(height[l], height[r]) * (r-l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return answer;
    }
};