#include "../../../../common/Includes.h"

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1.length() != str2.length())
            return false;
        if (str1 == str2)
            return true;
        
        unordered_map<char,char> mappings;
        unordered_set<char> uniqueStr2Chars;
        
        const int n = str1.length();
        for (int i = 0; i < n; i++) {
            if (mappings.count(str1[i]) > 0) {
                if (mappings[str1[i]] != str2[i])
                    return false;
            } else {
                mappings[str1[i]] = str2[i];
            }
            uniqueStr2Chars.insert(str2[i]);
        }
        
        return uniqueStr2Chars.size() != 26;
    }
};