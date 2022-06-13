#include "../../../../common/Includes.h"

class Solution {
private:
    void flipColumn(vector<vector<int>>& grid, int n, int col) {
        for (int i = 0; i < n; i++)
            grid[i][col] = 1 - grid[i][col];
    }
public:
    bool removeOnes(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1)  {
                flipColumn(grid, n, i);
            }
        }
        
        for (auto row: grid) {
            int sum = 0;
            for (auto cell: row) {
                sum += cell;
            }
            if (sum != 0 and sum != m)
                return false;
        }
        
        return true;
    }
};