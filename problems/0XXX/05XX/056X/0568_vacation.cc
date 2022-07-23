#include "../../../../common/Includes.h"

struct pairHash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }  
};

class Solution {
    vector<vector<int>> flights;
    vector<vector<int>> days;
    int n, k;
    unordered_map<pair<int,int>, int, pairHash> dp;

    int dfs(int city, int week) {
        if (week == k)
            return 0;
        
        if (dp.count({city, week}) > 0)
            return dp[{city, week}];
        
        // Stay in the same city
        int answer = days[city][week] + dfs(city, week+1);
        
        // Try travelling around
        for (int i = 0; i < n; i++) {
            if (i == city or flights[city][i] == 0)
                continue;
            
            answer = max(answer, days[i][week] + dfs(i, week+1));
        }
        
        dp[{city, week}] = answer;
        return answer;
    }
    
public:
    int maxVacationDays(const vector<vector<int>>& flights, const vector<vector<int>>& days) {
        this->flights = flights;
        this->days = days;
        n = flights.size();
        k = days[0].size();
        
        return dfs(0, 0);
    }
};