#include "../../../../common/Includes.h"

class Solution {
    vector<string> board;
    vector<vector<string>> answer;
    int n;
    
    bool canPlaceQueen(int row, int col){
        for(int i = row; i >= 0; i--) 
            if(board[i][col] == 'Q') 
                return false;
        for(int i = row, j = col; i >= 0 and j >= 0; i--, j--) 
            if(board[i][j] == 'Q') 
                return false;
        for(int i = row, j = col; i >= 0 and j < n; i--, j++)
            if(board[i][j] == 'Q') 
                return false;
        return true;
    }
    
    void recurse(int row) {
        /* Edge case */
        if (row == n) {
            answer.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (canPlaceQueen(row, col)) {
                board[row][col] = 'Q';
                recurse(row + 1);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        recurse(0);
        return answer;
    }
};