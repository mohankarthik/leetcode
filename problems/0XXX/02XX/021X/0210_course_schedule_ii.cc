#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        int indegree[n];
        unordered_map<int,vector<int>> adjacency;
        
        memset(indegree, 0, sizeof(indegree));
        
        for (auto const &pre: prerequisites) {
            indegree[pre[0]]++;
            adjacency[pre[1]].emplace_back(pre[0]);
        }
        cout << indegree[0] << endl;
        unordered_set<int> seen;
        queue<int> q;
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                seen.insert(i);
                answer.emplace_back(i);
            }
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor: adjacency[curr]) {
                indegree[neighbor] = max(indegree[neighbor]-1, 0);
                if (!indegree[neighbor] and !seen.count(neighbor)) {
                    q.push(neighbor);
                    seen.insert(neighbor);
                    answer.emplace_back(neighbor);
                }
            }
        }
        
        return answer;
    }
};

int main(void) {
    vector<vector<int>> input {{0,1},{0,2},{1,2}};
    vector<int> output {2,1,0};
    Solution *sol = new Solution();
    assert(sol->findOrder(3, input) == output);
}