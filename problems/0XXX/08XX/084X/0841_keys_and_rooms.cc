#include "../../../../common/Includes.h"

class Solution {
private:
    unordered_set<int> seen;
    void dfs(vector<vector<int>>& rooms, int curr) {
        seen.insert(curr);
        while(!rooms[curr].empty()) {
            int key = rooms[curr][0];
            rooms[curr].erase(rooms[curr].begin());
            if (seen.find(key) == seen.end()) {
                dfs(rooms, key);    
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        for (int i = 0; i < rooms.size(); i++)
            if (seen.find(i) == seen.end())
                return false;
        return true;
    }
};