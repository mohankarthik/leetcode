#include "../../../../common/Includes.h"

class Solution {
private:
    vector<vector<int>> answer;
    vector<vector<int>> graph;
    vector<int> currPath;
    
    void _dfs(int current, int destination) {
        if (current == destination) {
            answer.emplace_back(currPath);
        }
        
        for (auto const &neighbor: graph[current]) {
            currPath.emplace_back(neighbor);
            _dfs(neighbor, destination);
            currPath.pop_back();
        }
    }
    
    void _bfs(int source, int destination) {
        queue<pair<int,vector<int>>> q;
        q.push({source, {source}});
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.first == destination) {
                answer.emplace_back(curr.second);
                continue;
            }
            
            for (auto const &neighbor: graph[curr.first]) {
                vector<int> temp = curr.second;
                temp.emplace_back(neighbor);
                
                q.push({neighbor, temp});
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        const int n = graph.size();
        currPath.emplace_back(0);
        //_dfs(0, n-1);
        _bfs(0, n-1);
        return answer;
    }
};