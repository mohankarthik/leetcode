#include "../../../../common/Includes.h"

class NumMatrix {
private:
    vector<vector<int>> rowSums;
    vector<vector<int>> matrix;
    int n, m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        n = matrix.size();
        m = matrix[0].size();
        rowSums.resize(n);
        
        for (int r = 0; r < n; r++) {
            int curSum = 0;
            rowSums[r].push_back(curSum);
            for (int c = 0; c < m; c++) {
                curSum += matrix[r][c];
                rowSums[r].push_back(curSum);
            }
        }
    }
    
    void update(int row, int col, int val) {
        const int diff = val - matrix[row][col];
        matrix[row][col] = val;
        for (int c = col+1; c <= m; c++) {
            rowSums[row][c] += diff;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            sum += rowSums[r][col2+1] - rowSums[r][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */ 