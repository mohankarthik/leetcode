#include "../../../../common/Includes.h"

class Solution {
private:
    unordered_map<int, set<int>> adjacency;
    unordered_set<int> seen;
    bool dfs(int curr, int destination) {
        if (adjacency[curr].size() == 0)
            return curr == destination;
        
        for (auto const &neighbor: adjacency[curr]) {
            if (seen.find(neighbor) != seen.end())
                return false;
            seen.insert(neighbor);
            if (!dfs(neighbor, destination))
                return false;
            seen.erase(neighbor);
        }
        
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        for (auto const &edge: edges) {
            adjacency[edge[0]].insert(edge[1]);
        }
        
        seen.insert(source);
        return dfs(source, destination);
    }
};