#include "../../../../common/Includes.h"

class Solution {
private:
    int n;
    
    vector<int> _current;
    vector<vector<int>> _answer;
    
    void _backtrack(int k, int curr) {
        if (k == 0) {
            vector<int> newComb(_current);
            _answer.push_back(newComb);
            return;
        }
        
        for (int i = curr; i <= n; i++) {
            _current.push_back(i);
            _backtrack(k-1, i+1);
            _current.erase(_current.end()-1);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        _backtrack(k, 1);
        return _answer;
    }
};