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

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        /* Preconditions */
        if ((image.size() == 0) || (image[0].size() == 0))
            return image;
        assert((sr >= 0) && (sr < image.size()));
        assert((sc >= 0) && (sc < image[0].size()));

        /* Save the sizes */
        int n = image.size();
        int m = image[0].size();

        /* Save the original color */
        int origColor = image[sr][sc];

        /* Create the queue and the set */
        queue<pair<int, int>> _q;
        set<pair<int, int>> _seen;

        /* Push the starting position and assume it to be seen */
        _q.push({sr, sc});
        _seen.insert({sr, sc});

        /* Mark the starting location with the new color */
        image[sr][sc] = newColor;

        /* Traverse through the image */
        while (!_q.empty())
        {
            /* Get the first element */
            auto cur = _q.front();
            _q.pop();

            /* Get all unseen neighbors */
            for (int i = 0; i < 4; i++)
            {
                int nr = cur.first + offsets[i];
                int nc = cur.second + offsets[i + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == origColor && !_seen.count({nr, nc}))
                {
                    image[nr][nc] = newColor;
                    _q.push({nr, nc});
                    _seen.insert({nr, nc});
                }
            }
        }

        return image;
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

    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    vector<vector<int>> expImage{
        {2, 2, 2},
        {2, 2, 0},
        {2, 0, 1}};
    image = sol->floodFill(image, 1, 1, 2);
    _test(image, expImage);

    image = {
        {0, 0, 0},
        {0, 1, 1}};
    expImage = {
        {0, 0, 0},
        {0, 1, 1}};
    image = sol->floodFill(image, 1, 1, 1);
    _test(image, expImage);
}
