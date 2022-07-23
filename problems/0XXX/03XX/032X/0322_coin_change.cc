#include "../../../../common/Includes.h"

class Solution {
private:
    int dp[10001];
    
public:
    int coinChange(vector<int>& coins, int amount) {
        for (int i = 0; i <= amount; i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        
        const int n = coins.size();
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j] and dp[i-coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};