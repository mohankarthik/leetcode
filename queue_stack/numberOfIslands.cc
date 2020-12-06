#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        /* Preconditions */
        if ((grid.size() == 0) || (grid[0].size() == 0))
            return 0;

        /* Get the dimensions */
        int n = grid.size(), m = grid[0].size();

        /* Result */
        int result = 0;

        /* Loop through each element and see if it's a land */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                /* Check if it's a land */
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    _mapIslandDfs(grid, i, j);
                    result++;
                }
            }
        }

        return result;
    }

private:
    const int _offsets[5] = {0, 1, 0, -1, 0};

    /* Function to map a single island starting from stX and stY */
    void _mapIslandBfs(vector<vector<char>> &grid, int stX, int stY)
    {
        const int n = grid.size();
        const int m = grid[0].size();

        queue<pair<int, int>> bfsQ;
        bfsQ.push({stX, stY});

        while (!bfsQ.empty())
        {
            /* Get the first element */
            auto pos = bfsQ.front();
            bfsQ.pop();

            /* Add it's neighbors if they are land */
            for (int i = 0; i < 4; i++)
            {
                int r = pos.first + _offsets[i];
                int c = pos.second + _offsets[i + 1];
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1')
                {
                    grid[r][c] = '0';
                    bfsQ.push({r, c});
                }
            }
        }
    }

    /* Function to map a single island starting from stX and stY using DFS */
    void _mapIslandDfs(vector<vector<char>> &grid, int stX, int stY)
    {
        int n = grid.size();
        int m = grid[0].size();

        /* Add it's neighbors if they are land */
        for (int i = 0; i < 4; i++)
        {
            int r = stX + _offsets[i];
            int c = stY + _offsets[i + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1')
            {
                grid[r][c] = '0';
                _mapIslandDfs(grid, r, c);
            }
        }
    }
};

int main(void)
{
    vector<vector<char>> grid1{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    vector<vector<char>> grid2{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    vector<vector<char>> grid3{
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'},
        {'1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};

    Solution *sol = new Solution();
    cout << sol->numIslands(grid1) << endl;
    cout << sol->numIslands(grid2) << endl;
    cout << sol->numIslands(grid3) << endl;

    return 0;
}