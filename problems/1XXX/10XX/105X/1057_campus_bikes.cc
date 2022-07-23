#include "../../../../common/Includes.h"

class Solution {
private:
    int getDistance(const vector<int>& worker, const vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
public:
    vector<int> assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
        const int n = workers.size();
        const int m = bikes.size();
        const int MAX_DIST = 2000;
        
        vector<pair<int,int>> distances[MAX_DIST];
        
        // Form the distances
        int minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                const int dist = getDistance(workers[i], bikes[j]);
                distances[dist].push_back({i, j});
                minDist = min(minDist, dist);
            }
        }
        
        // Form the assignments
        int numAssignments = 0;
        vector<int> assignments(n, -1);
        unordered_set<int> assignedBikes;
        unordered_set<int> assignedWorkers;

        for (int curDist = minDist; curDist < MAX_DIST; curDist++) {
            for (auto [worker, bike]: distances[curDist]) {
                if (assignedBikes.count(bike) == 0 and assignedWorkers.count(worker) == 0)  {
                    numAssignments++;
                    assignments[worker] = bike;
                    assignedWorkers.insert(worker);
                    assignedBikes.insert(bike);
                    
                    if (numAssignments == n)
                        return assignments;
                }
            }
        }
        
        return assignments;
    }
};