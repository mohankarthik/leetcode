#include "../../../../common/Includes.h"

class Solution {
private:
    typedef enum DIRECTION {
        UP,
        DOWN,
        LEFT,
        RIGHT
    } DIRECTION;
    
public:
    vector<vector<int>> generateMatrix(int n) {
        /* Create the resulting matrix */
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        /* Initialize */
        DIRECTION eDir = RIGHT;
        int x = 0;
        int y = 0;
        int minX = 0;
        int maxX = n;
        int minY = 0;
        int maxY = n;
        int val = 1;
        const int n_sq = (n*n);
        
        /* Loop */
        while(val <= n_sq)
        {
            result[x][y] = val;
            val++;
            
            if (eDir == RIGHT)
            {
                y++;
                if (y >= maxY) 
                {
                    eDir = DOWN;
                    minX++;
                    y--;
                    x++;
                }
            }
            else if (eDir == DOWN)
            {
                x++;
                if (x >= maxX)
                {
                    eDir = LEFT;
                    maxY--;
                    x--;
                    y--;
                }
            }
            else if (eDir == LEFT)
            {
                y--;
                if (y < minY)
                {
                    eDir = UP;
                    maxX--;
                    x--;
                    y++;
                }
            }
            else
            {
                x--;
                if (x < minX)
                {
                    eDir = RIGHT;
                    minY++;
                    x++;
                    y++;
                }
            }
        }
        
        return result;
    }
};