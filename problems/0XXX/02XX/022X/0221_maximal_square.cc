#include "../../../../common/Includes.h"

class Solution {
private:
    vector<vector<char>> matrix;
    int n, m;
    int dp[2][301];
    
    int iterate() {
        memset(dp, 0, sizeof(dp));
        
        int answer = 0;
        int ping = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[ping][j] = min({dp[1-ping][j], dp[1-ping][j-1], dp[ping][j-1]}) + 1;
                    answer = max(answer, dp[ping][j]);
                } else {
                    dp[ping][j] = 0;
                }
            }
            ping = 1-ping;
        }
        
        return answer * answer;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        this->matrix = matrix;
        this->n = matrix.size();
        this->m = matrix[0].size();
        return iterate();
    }
};