#include "../../../../common/Includes.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adjacency;
        for (auto const &time: times) {
            adjacency[time[0]].push_back({time[1], time[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_set<int> seen;
        pq.push({0,k});
        
        int nodesLeft = n;
        int answer = 0;
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            if (seen.find(curr.second) != seen.end()) continue;
            seen.insert(curr.second);
            
            nodesLeft--;
            answer = curr.first;
            if (nodesLeft == 0) return answer;
            for (auto &neighbor: adjacency[curr.second]) {
                pq.push({curr.first + neighbor.second, neighbor.first});
            }
        }
        return nodesLeft == 0 ? answer : -1;
    }
};