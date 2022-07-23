#include "../../../../common/Includes.h"

/*
12
dp[3] = 0
dp[2] = 1
dp[1] = 
*/
class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> codes;
        for (int i = 1; i <= 26; i++) {
            stringstream iss;
            iss << i;
            codes.insert(iss.str());
        }
        
        const int n = s.length();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; (i + j) <= n; j++) {
                string str = s.substr(i, j);
                if (codes.count(str))
                    dp[i] += dp[i+j];
            }
        }
        return dp[0];
    }
};