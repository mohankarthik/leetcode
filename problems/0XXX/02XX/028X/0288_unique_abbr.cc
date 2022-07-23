#include "../../../../common/Includes.h"

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> abbrMap;
    
    string makeAbbr(string word) {
        if (word.length() <= 2)
            return word;
        else
            return word[0] + to_string(word.length()-2) + word.back();
    }
public:
    ValidWordAbbr(const vector<string>& dictionary) {
        for(const string word: dictionary) {
            abbrMap[makeAbbr(word)].insert(word);
        }
    }
    
    bool isUnique(string word) {
        const string abbr = makeAbbr(word);
        const auto it = abbrMap.find(abbr);
        if (it == abbrMap.end()) return true;
        return it->second.size() == 1 and *(it->second.begin()) == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */