#include "../common/Includes.h"

class Solution {
public:
    typedef enum DIR {
        UP,
        DOWN,
        LEFT,
        RIGHT
    } DIR;
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        DIR eDir = RIGHT;
        
        /* Preconditions */
        if (matrix.size() == 0) return result;
        if (matrix[0].size() == 0) return result;
        
        /* Set the staring parameters */
        int minCol = 0;
        int minRow = 0;
        int maxRow = matrix.size() - 1;
        int maxCol = matrix[0].size() - 1;
        int currCol = 0;
        int currRow = 0;
        
        while(true) {
            /* Boundary conditions */
            if ((minRow > maxRow) || (minCol > maxCol)) break;
            
            if (eDir == RIGHT) {
                int i = currRow;
                cout << "RIGHT" << endl;
                for (int j = minCol; j <= maxCol; j++) {
                    cout << i << ' ' << j << endl;
                    result.push_back(matrix[i][j]);
                }
                eDir = DOWN;
                currRow++;
                currCol = maxCol;
                minRow = currRow;
            } else if (eDir == DOWN) {
                int j = currCol;
                cout << "DOWN" << endl;
                for (int i = minRow; i <= maxRow; i++) {
                    cout << i << ' ' << j << endl;
                    result.push_back(matrix[i][j]);
                }
                eDir = LEFT;
                currRow = maxRow;
                currCol--;
                maxCol = currCol;
            } else if (eDir == LEFT) {
                int i = currRow;
                cout << "LEFT" << endl;
                for (int j = maxCol; j >= minCol; j--) {
                    cout << i << ' ' << j << endl;
                    result.push_back(matrix[i][j]);
                }
                eDir = UP;
                currRow--;
                currCol = minCol;
                maxRow = currRow;
            } else {
                int j = currCol;
                cout << "UP" << endl;
                for (int i = maxRow; i >= minRow; i--) {
                    cout << i << ' ' << j << endl;
                    result.push_back(matrix[i][j]);
                }
                eDir = RIGHT;
                currRow = minRow;
                currCol++;
                minCol = currCol;
            }
        };
        
        return result;
    }
};