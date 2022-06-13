#include "../../../../common/Includes.h"

class Solution {
private:
    unordered_set<char> _seen;
    int two_pointer(string s) {
        int st = 0, en = 0;
        int n = s.size();
        int answer = 0;
        while(en < n) {
            if (!_seen.count(s[en])) {
                _seen.insert(s[en]);
                en++;
                answer = max(answer, en-st);
            } else {
                _seen.erase(s[st]);
                st++;
            }
        }
        return answer;
    }
    
    unordered_map<char,int> _pos;
    int sliding_window(string s) {
        const int n = s.size();
        int answer = 0;
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (_pos.count(s[i]) and _pos[s[i]] > start)
                start = _pos[s[i]];
            _pos[s[i]] = i;
            answer = max(answer, i-start);
        }
        return answer;
    }
public:
    int lengthOfLongestSubstring(string s) {
        return sliding_window(s);
    }
};