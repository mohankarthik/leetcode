#include "../../../../common/Includes.h"

class Solution {
private:
    vector<vector<char>> board;
    vector<unordered_set<char>> cols;
    vector<unordered_set<char>> rows;
    vector<unordered_set<char>> cells;
    
    int _findCell(int row, int col) {
        return ((row/3)*3) + (col/3);
    }
    
    void _initialize() {
        cols.resize(9);
        rows.resize(9);
        cells.resize(9);
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    const int cell = _findCell(row,col);
                    rows[row].insert(board[row][col]);
                    cols[col].insert(board[row][col]);
                    cells[cell].insert(board[row][col]);
                }
            }
        }
    }
    
    bool _check(int row, int col, char ch) {
        const int cell = _findCell(row,col);
        return 
            (cols[col].count(ch) == 0 
            and rows[row].count(ch) == 0 
            and cells[cell].count(ch) == 0);
    }
    
    bool _backtrack(int row, int col) {
        if (row == 9) return true;
        if (col == 9) return _backtrack(row+1, 0);
        if(board[row][col] != '.') return _backtrack(row, col+1);
        
        
        for (char ch = '1'; ch <= '9'; ch++) {
            if (!_check(row, col, ch))
                continue;

            const int cell = _findCell(row,col);
            
            board[row][col] = ch;
            cols[col].insert(ch);
            rows[row].insert(ch);
            cells[cell].insert(ch);

            if (_backtrack(row, col+1)) 
                return true;

            board[row][col] = '.';
            cols[col].erase(ch);
            rows[row].erase(ch);
            cells[cell].erase(ch);
        }
        
        return false;
    }
        
public:
    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        _initialize();
        const auto result = _backtrack(0, 0);
        assert(result == true);
        swap(board, this->board);
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<vector<char>> input {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sol->solveSudoku(input);
}