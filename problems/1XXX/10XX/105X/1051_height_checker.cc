#include "../../../../common/Includes.h"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        
        /* Create a new array */
        vector<int> sorted = heights;
        
        /* Sort the array */
        sort(sorted.begin(), sorted.end());
        
        /* Loop through and find faults */
        for(int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) ans++;
        }
        
        return ans;
    }
};