#include "../../../../common/Includes.h"

#define GPQ priority_queue<int, vector<int>, std::greater<int> >

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        /* Map to hold all the priority queues */
        unordered_map<int, GPQ> map;
        
        /* Add to the map of priority queues */
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (map.find(i-j) == map.end())
                {
                    GPQ p;
                    map[i-j] = p;
                }
                map[i-j].push(mat[i][j]);
            }
        
        /* Reform the sorted matrix */
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                mat[i][j] = map[i-j].top();
                map[i-j].pop();
            }
        
        return mat;
        
    }
};