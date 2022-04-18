#include "../../../../common/Includes.h"

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