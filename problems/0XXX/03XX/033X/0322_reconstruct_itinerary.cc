#include "../../../../common/Includes.h"

class Solution {
public:
    unordered_map<string, multiset<string>> adjacency;
    vector<string> path;
    
    void _dfs(string curr) {
        while(adjacency[curr].size()) {
            string next = *adjacency[curr].begin();
            adjacency[curr].erase(adjacency[curr].begin());
            _dfs(next);            
        }
        path.emplace_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto const &ticket: tickets) {
            adjacency[ticket[0]].insert(ticket[1]);
        }
        
        _dfs("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
};