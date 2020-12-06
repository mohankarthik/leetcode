#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    const int offsets[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> _mem;
    int n, m;

    void _update(vector<vector<int>> &matrix, vector<vector<int>> &res, int x, int y)
    {
        /* Return if we've already computed this position */
        if (res[x][y] != -1)
            return;

        /* If this is a 0 spot, then set as 0 & return */
        if (matrix[x][y] == 0)
        {
            res[x][y] = 0;
            return;
        }

        /* If it's not 0, then search */
        res[x][y] = INT_MAX;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + offsets[i];
            int ny = y + offsets[i + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                _update(matrix, res, nx, ny);
                res[x][y] = min(res[x][y], (res[nx][ny] + 1));
            }
        }

        /* Since there are atleast 1 0s in the matrix, it should never remain INT_MAX here */
        assert(res[x][y] != INT_MAX);
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        /* Preconditions */
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;

        /* Initialize the globals */
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));

        /* Call the recursion */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (res[i][j] != -1)
                {
                    /* Nothing to do, because we've already found the answer */
                }
                else if (matrix[i][j] == 0)
                {
                    /* The distance is just to itself, so we are good */
                    res[i][j] = 0;
                }
                else
                {
                    /* We need to search */
                    _update(matrix, res, i, j);
                }
            }
        }

        /* Return the result */
        return res;
    }
};

void _test(vector<vector<int>> &out, vector<vector<int>> &exp)
{
    assert(out.size() == exp.size());
    for (int i = 0; i < exp.size(); i++)
    {
        assert(out[i].size() == exp[i].size());
        for (int j = 0; j < exp[i].size(); j++)
        {
            assert(out[i][j] == exp[i][j]);
        }
    }
}

int main(void)
{
    Solution *sol = new Solution();

    vector<vector<int>> input{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> exp{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> res = sol->updateMatrix(input);
    _test(res, exp);

    input = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    exp = {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
    res = sol->updateMatrix(input);
    _test(res, exp);
}