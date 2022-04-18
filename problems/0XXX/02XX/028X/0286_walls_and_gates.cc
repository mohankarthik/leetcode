#include "../../../../common/Includes.h"

class Solution {
private:
    const static inline vector<int> diff = {-1,1};
    static const int INF = 2147483647;
    queue<pair<int,int>> queue;
    int n, m;
    
    bool isIndexValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    void add_gates(vector<vector<int>>& rooms) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    /* Insert these into the queue */
                    queue.push(make_pair(i,j));
                }
            }
        }
    }
    
    void add_neighbors(vector<vector<int>>& rooms, int i, int j) {
        for (int dir = 0; dir <= 1; dir++) {
            for (int delta: diff) {
                int new_i = i, new_j = j;
                if (dir)
                    new_i = i + delta;
                else
                    new_j = j + delta;
                if (isIndexValid(new_i, new_j) 
                    && rooms[new_i][new_j] == INF) {
                    queue.push(make_pair(new_i, new_j));
                    rooms[new_i][new_j] = rooms[i][j] + 1;
                }
            }
        }
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        /* Preconditions */
        if (rooms.empty() || rooms[0].empty())
            throw invalid_argument("Rooms are empty");
        
        /* Store the sizes */
        n = rooms.size();
        m = rooms[0].size();
        
        /* Find the gates & add them to the queue */
        add_gates(rooms);
        
        while(!queue.empty()) {
            /* Get the first element */
            auto curr = queue.front();
            queue.pop();
            
            /* Find & add the neighbors */
            add_neighbors(rooms, curr.first, curr.second);
        }
    }
};