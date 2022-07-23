#include "../../../../common/Includes.h"

/*
5,1,9,11
2,4,8,10
13,3,6,7
15,14,12,16

5,2,13,15
1,4,3,14
9,8,6,12
11,10,7,16

15,13,2,5
14,3,4,1
12,6,8,9
16,7,10,11
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        // Mirror by Diagonal
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < m; j++) {
                const int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Mirror by vertical
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (m/2); j++) {
                const int temp = matrix[i][j];
                matrix[i][j] = matrix[i][m-j-1];
                matrix[i][m-j-1] = temp;
            }
        }
    }
};