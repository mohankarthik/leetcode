#include "../../../../common/Includes.h"

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        const int n = s.length();
        for(const char &ch: s) {
            map[ch]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (map[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};