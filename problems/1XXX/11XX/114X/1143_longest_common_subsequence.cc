#include "../../../../common/Includes.h"

class Solution {
private:
    string text1, text2;
    int n, m;
    int dp[1001][1001];
    
    int recurse(int i, int j) {
        if (i >= n or j >= m)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int answer = 0;
        if (text1[i] == text2[j]) {
            answer = 1 + recurse(i+1, j+1);
        } else {
            answer = max(max(answer, recurse(i, j+1)), recurse(i+1, j));
        }
        dp[i][j] = answer;
        return answer;
    }
    
    int iterate() {
        memset(dp, 0, sizeof(dp));
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        this->n = text1.length();
        this->m = text2.length();
        /*
        memset(dp, -1, sizeof(dp));
        return recurse(0, 0);
        */
        return iterate();
    }
};