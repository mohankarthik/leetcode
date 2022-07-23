#include "../../../../common/Includes.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int d = prices.size();
        
        // Preconditions
        if (d <= 0 or k <= 0) return 0;

        // If we've enough transcations to buy/sell each day, be greedy and go nuts
        if (2*k > d) {
            int res = 0;
            for (int i = 1; i < d; i++)
                res += max(0, prices[i]-prices[i-1]);
            return res;
        }
        
        // day, transactions left, sell/buy
        int dp[2][k+1][2];
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = dp[0][i][1] = dp[1][i][0] = dp[1][i][1] = -1e9;
        }
        
        // If we sell on last day
        dp[0][0][0] = 0;
        // if we buy on last day
        dp[0][1][1] = -prices[0];
        int ping = 1;
        for (int i = 1; i < d; i++) {
            for (int j = 0; j <= k; j++) {
                dp[ping][j][0] = max(dp[1-ping][j][0], dp[1-ping][j][1] + prices[i]);
                if (j != 0)
                    dp[ping][j][1] = max(dp[1-ping][j][1], dp[1-ping][j-1][0] - prices[i]);
            }
            ping = 1-ping;
        }
        
        int res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, dp[1-ping][i][0]);
        }
        return res;        
    }
};