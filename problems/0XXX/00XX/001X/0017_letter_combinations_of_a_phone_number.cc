#include "../../../../common/Includes.h"

class Solution {
private:
    vector<vector<char>> pad {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> answer;
    string digits;
    string curr = "";
    
    void _dfs(int i) {
        if (i == digits.size()) {
            answer.push_back(curr);
            return;
        }
        
        const int digit = digits[i] - '0';
        for (auto ch: pad[digit]) {
            curr += ch;
            _dfs(i+1);
            curr.pop_back();
        }
    }
    
    void _iterate() {
        answer.push_back("");
        
        for(auto digitStr: digits) {
            vector<string> tmp;
            const int digit = digitStr - '0';
            for (auto ch: pad[digit]) {
                for (auto str: answer) {
                    tmp.push_back(str + ch);
                }
            }
            swap(tmp, answer);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        this->digits = digits;
        _dfs(0);
        //_iterate();
        return answer;
    }
};