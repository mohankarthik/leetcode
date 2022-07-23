#include "../../../../common/Includes.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mem;
        for(const string &str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mem[key].emplace_back(str);
        }
        
        vector<vector<string>> answer;
        for (const auto &element: mem) {
            answer.emplace_back(element.second);
        }
        return answer;
    }
};