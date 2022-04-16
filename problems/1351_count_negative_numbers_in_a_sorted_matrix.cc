#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Preconditions
        if (grid.empty() || grid[0].empty())
            return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        int r = 0;
        int ans = 0;
        for (int c = m - 1; c >= 0; c--) {
            while(r < n && grid[r][c] >= 0)
                r++;
            ans += n - r;
        }
        return ans;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<vector<int>> grid1{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    assert(sol->countNegatives(grid1) == 8);
    vector<vector<int>> grid2{{3,2},{1,0}};
    assert(sol->countNegatives(grid2) == 0);
}