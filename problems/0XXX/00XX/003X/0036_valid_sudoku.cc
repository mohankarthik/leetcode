#include "../../../../common/Includes.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> cols(9), rows(9), diags(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                
                const int diag = ((i/3)*3) + (j/3);
                if ((rows[i].count(board[i][j]) > 0)
                    or (cols[j].count(board[i][j]) > 0)
                    or (diags[diag].count(board[i][j]) > 0)) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                diags[diag].insert(board[i][j]);
            }
        }
        return true;
    }
};