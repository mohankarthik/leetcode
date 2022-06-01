#include "../../../../common/Includes.h"

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        if (n == 0) return false;
        const int m = matrix[0].size();
        int row = n-1, col = 0;
        while (row >= 0 and col < m) {
            if (matrix[row][col] > target)
                row--;
            else if (matrix[row][col] < target)
                col++;
            else
                return true;
        }
        return false;
    }
};