#include "../../../../common/Includes.h"

class Solution {
private:
    const static inline vector<int> diff = {-1, 1};
    int n, m;
    
    bool isIndexValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    void traverseBfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        
        /* Add the root */
        grid[i][j] = '0';
        q.push(make_pair(i,j));
        
        while(!q.empty()) {
            /* Get the current */
            auto curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();
            
            /* Add the neigbors */
            for (int dir = 0; dir <= 1; dir++) {
                for (int delta: diff) {
                    int new_r = r, new_c = c;
                    if (dir == 0)
                        new_r += delta;
                    else
                        new_c += delta;
                    if (isIndexValid(new_r, new_c)
                       && grid[new_r][new_c] == '1') {
                        grid[new_r][new_c] = '0';
                        q.push(make_pair(new_r,new_c));
                    }
                }
            }
        }
    }
    
    int usingBfs(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int num_islands = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    traverseBfs(grid, i, j);
                }
            }
        }
        
        return num_islands;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            throw invalid_argument("Grid is empty");
        
        n = grid.size();
        m = grid[0].size();
        
        return usingBfs(grid);
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    assert(sol->numIslands(grid1) == 1);
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    assert(sol->numIslands(grid2) == 3);
    return 0;
}