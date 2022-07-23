#include "../../../../common/Includes.h"

class Solution {
private:
    // Jobs Left, Days Left
    int dp[301][11];
    int nj, nd;
    vector<int> diff;
    vector<int> hardestJobRemaining;
    
    int recurse(int jobsDone, int day) {
        if (day == nd)
            return hardestJobRemaining[jobsDone];
        
        if (dp[jobsDone][day] != -1)
            return dp[jobsDone][day];
        
        int answer = INT_MAX;
        int maxDiff = 0;
        for (int i = jobsDone; i < nj-(nd-day); i++) {
            maxDiff = max(maxDiff, diff[i]);
            answer = min(answer, maxDiff + recurse(i+1, day+1));
        }
        dp[jobsDone][day] = answer;
        return answer;        
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        nj = jobDifficulty.size();
        nd = d;
        diff = jobDifficulty;
        
        if (nj < nd)
            return -1;
        
        hardestJobRemaining = vector<int>(nj);
        hardestJobRemaining[nj-1] = jobDifficulty[nj-1];
        for (int i = nj-2; i >= 0; i--) {
            hardestJobRemaining[i] = max(hardestJobRemaining[i+1], jobDifficulty[i]);
        }
        
        memset(dp, -1, sizeof(dp));
        return recurse(0, 1);
    }
};