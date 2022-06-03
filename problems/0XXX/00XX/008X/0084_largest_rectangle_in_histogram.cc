#include "../../../../common/Includes.h"

class Solution {
private:
    stack<int> stk;
    int max_area = 0;
    
    void updateMaxArea(const vector<int>& heights, int idx) {
        const int curr_height = heights[stk.top()];
        stk.pop();
        const int curr_width = idx - stk.top() - 1;
        max_area = max(max_area, curr_height * curr_width);
    }
public:
    int largestRectangleArea(const vector<int>& heights) {
        const int n = heights.size();
        stk.push(-1);
        for (int i = 0; i < n; i++) {
            while(stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                updateMaxArea(heights, i);
            }
            stk.push(i);
        }
        
        while(stk.top() != -1) {
            updateMaxArea(heights, heights.size());
        }
        
        return max_area;
    }
};