#include "../../../../common/Includes.h"

#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        const int m = points[0].size();
        
        // Initialize two DP, prev (which tracks the prev row) and dp which tracks curr
        // Initialize prev with points itself since for row 0, it is just points
        vector<ll> dp(m);
        for (int c = 0; c < m; c++) {
            dp[c] = points[0][c];
        }

        /*
        We want to optimize for dp[r][c] = points[r][c] + max(dp[r-1][j] - abs(c-j)) for all j
        Splitting this into left & right sections
        If j < c (i.e. left)
        dp[r][c] = points[r][c] + dp[r-1][j] - c + j
        */
        for (int r = 1; r < n; r++) {
            vector<ll> left(m,0), right(m,0);
            
            left[0] = dp[0] + 0;
            for (int c = 1; c < m; c++) {
                left[c] = max(left[c-1], dp[c] + c); 
            }
            
            right[m-1] = dp[m-1] - (m-1);
            for (int c = m-2; c >= 0; c--) {
                right[c] = max(right[c+1], dp[c] - c);
            }
            
            for (int c = 0; c < m; c++) {
                dp[c] = points[r][c] + max(left[c]-c, right[c]+c);
            }
        }
        
        ll answer = 0;
        for (int c = 0; c < m; c++) {
            answer = max(answer, dp[c]);
        }
        return answer;
    }
};