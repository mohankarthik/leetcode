#include "../../../../common/Includes.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst)
            return 0;
        
        vector<vector<int>> dp(2, vector<int>(n,INT_MAX));
        dp[0][src] = 0;
        
        for (int i = 0; i < k+1; i++) {
            dp[1][src] = 0;
            for (auto const &flight: flights) {
                const int prev = flight[0];
                const int curr = flight[1];
                const int cost = flight[2];
                
                if (dp[0][prev] != INT_MAX)
                    dp[1][curr] = min(dp[1][curr], dp[0][prev] + cost);
            }
            for (int j = 0; j < n; j++) {
                dp[0][j] = dp[1][j];
            }
        }
        
        return dp[1][dst] == INT_MAX ? -1 : dp[1][dst];
        
    }
};