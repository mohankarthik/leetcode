#include "../../common/Includes.h"

class Solution {
public:
    int bestScore(const vector<vector<int>> &inputs, int w) {
        const int n = inputs.size();
        int dp[n+1][w+1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (!i or !j) dp[i][j] = 0;
                else if (j < inputs[i-1][0]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-inputs[i-1][0]] + inputs[i-1][1]);
            }
        }

        return dp[n][w];
    }
};

int main(void) {
    Solution *sol = new Solution();
    vector<vector<int>> inputs {{4, 10}, {2, 6}, {8, 13}, {10, 15}};
    cout << sol->bestScore(inputs, 10) << endl;
    return 0;
}