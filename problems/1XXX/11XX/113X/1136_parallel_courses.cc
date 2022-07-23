#include "../../../../common/Includes.h"

class Solution {
public:
    int minimumSemesters(int n, const vector<vector<int>>& relations) {
        unordered_map<int,int> indegree;
        unordered_map<int,unordered_set<int>> adj;
        
        /* Initialize */
        const int m = relations.size();
        for (int i = 0; i < n; i++) {
            indegree[i] = 0;
            adj[0] = unordered_set<int>();
        }
        
        /* Fill */
        for (auto const &rel: relations) {
            indegree[rel[1]]++;
            adj[rel[0]].insert(rel[1]);
        }
        
        int answer = -1;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                answer = 0;
            }
        }
        if (answer == 0) {
            q.push(-1);
        }
        
        while(!q.empty()) {
            while(!q.empty() and q.front() != -1) {
                int curr = q.front();
                q.pop();
                
                for (int next: adj[curr]) {
                    indegree[next] = max(indegree[next]-1, 0);
                    if (!indegree[next]) {
                        q.push(next);
                    }
                }
            }
            
            // Remove the -1
            q.pop();
            
            // Add a new -1 (market)
            if (!q.empty()) {
                q.push(-1);
            }
            answer += 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] != 0) {
                answer = -1;
            }
        }
        
        return answer;
    }
};