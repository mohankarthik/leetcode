#include "../../../../common/Includes.h"

class Solution {
private:
    double getDist(const vector<int> &point) {
        return sqrt((point[0] * point[0]) + (point[1] * point[1]));
    } 
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> q;
        
        const int n = points.size();
        for(int i = 0; i < n; i++) {
            q.push({getDist(points[i]), i});
            if (q.size() > k)
                q.pop();
        }
        
        vector<vector<int>> answer(k);
        for(int i = k-1; i >= 0; i--) {
            auto curr = q.top(); q.pop();
            answer[i] = points[curr.second];
        }
        return answer;
    }
};