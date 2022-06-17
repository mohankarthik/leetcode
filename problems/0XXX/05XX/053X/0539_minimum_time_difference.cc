#include "../../../../common/Includes.h"

class Solution {
private:
    int timediff(string lhs, string rhs) {
        const int h1 = stoi(lhs.substr(0,2));
        const int m1 = stoi(lhs.substr(3,2));
        const int h2 = stoi(rhs.substr(0,2));
        const int m2 = stoi(rhs.substr(3,2));
        return ((h1 * 60) + m1) - ((h2 * 60) + m2);
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        const int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int answer = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            int diff = abs(timediff(timePoints[(i-1+n)%n], timePoints[i]));
            diff = min(diff, 1440 - diff);
            answer = min(answer, diff);
        }
        
        return answer;
    }
};