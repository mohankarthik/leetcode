#include "../../../../common/Includes.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magazineFreq;
        for (const char ch: magazine) {
            if (magazineFreq.count(ch) <= 0) magazineFreq[ch] = 1;
            else magazineFreq[ch]++;
        }
        
        for (const char ch: ransomNote) {
            if (magazineFreq.count(ch) <= 0) return false;
            magazineFreq[ch]--;
            if (magazineFreq[ch] == 0) magazineFreq.erase(ch);
        }
        
        return true;
    }
};