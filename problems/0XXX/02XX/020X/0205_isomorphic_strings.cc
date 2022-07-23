#include "../../../../common/Includes.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        const int n = s.length();
        unordered_map<char,char> map;
        unordered_set<char> seen;
        
        for (int i = 0; i < n; i++) {
            if (map.find(s[i]) != map.end()) {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (seen.find(t[i]) != seen.end()) {
                    return false;
                }
                seen.insert(t[i]);
                map[s[i]] = t[i];
            }
        }
        return true;
    }
};