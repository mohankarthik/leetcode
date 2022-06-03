#include "../../../../common/Includes.h"

class Solution {
private:
    int size;
    
    int _backtrack(int row, unordered_set<int>& diags, unordered_set<int>& inv_diags, unordered_set<int>& cols) {
        if (row == size)
            return 1;
        
        int solutions = 0;
        for (int col = 0; col < size; col++) {
            int diag = row - col;
            int inv_diag = row + col;
            
            if (cols.count(col) > 0 or diags.count(diag) > 0 or inv_diags.count(inv_diag) > 0) {
                continue;
            }
            
            // Make the change
            cols.insert(col);
            diags.insert(diag);
            inv_diags.insert(inv_diag);
            
            // Find solutions for other rows
            solutions += _backtrack(row+1, diags, inv_diags, cols);
            
            // Backtrack
            cols.erase(col);
            diags.erase(diag);
            inv_diags.erase(inv_diag);
        }
        
        return solutions;
    }
public:
    int totalNQueens(int n) {
        size = n;
        
        unordered_set<int> diags;
        unordered_set<int> inv_diags;
        unordered_set<int> cols;
        
        return _backtrack(0, diags, inv_diags, cols);
    }
};