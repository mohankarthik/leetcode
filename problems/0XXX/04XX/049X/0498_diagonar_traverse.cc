#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if (n == 0) return result;
        int m = matrix[0].size();
        int i = 0;
        int j = 0;
        bool bUp = true;
        
        /* Loop for each pass */
        for (int c = 0; c < (n + m - 1); c++) {
            /* Set the start */
            if (bUp == true) {
                i = c; j = 0;
                
                while(i >= 0) {
                    if ((i < n) && (j < m)) result.push_back(matrix[i][j]);
                    i--; j++;
                }
            } else {
                i = 0; j = c;
                
                while(j >= 0) {
                    if ((i < n) && (j < m)) result.push_back(matrix[i][j]);
                    i++; j--;
                }
            }
            
            /* Set states for next value */
            bUp = !bUp;
        }
        
        return result;
    }
};