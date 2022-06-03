#include "../../../../common/Includes.h"

class Solution {
private:
    vector<string> _answer;
    string _curr = "";
    void _backtrack(int n, int numOpen) {
        if (n == 0) {
            _answer.push_back(_curr);
            return;
        }
        if (numOpen < n) {
            _curr += '(';
            _backtrack(n, numOpen+1);
            _curr.pop_back();
        }
        if (numOpen > 0) {
            _curr += ')';
            _backtrack(n-1, numOpen-1);
            _curr.pop_back();
        }
    }
    
    void _iterate(int n) {
        
    }
public:
    vector<string> generateParenthesis(int n) {
        _backtrack(n, 0);
        return _answer;
    }
};