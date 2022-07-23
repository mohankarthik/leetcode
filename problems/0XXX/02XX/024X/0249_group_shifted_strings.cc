#include "../../../../common/Includes.h"

class Solution {
private:
    string getKey(const string& x) {
        string answer = x;
        char st = x[0];
        const int n = x.length();
        for (int i = 0; i < n; i++) {
            answer[i] = x[i] - st + 'a';
            if (answer[i] > 'z')
                answer[i] -= 26;
            if (answer[i] < 'a')
                answer[i] += 26;
        }
        return answer;
    }
public:
    vector<vector<string>> groupStrings(const vector<string>& strings) {
        unordered_map<string, vector<string>> mem;
        
        const int n = strings.size();
        for (int i = 0; i < n; i++) {
            mem[getKey(strings[i])].emplace_back(strings[i]);
        }
        
        vector<vector<string>> answer;
        for (const auto& element: mem) {
            answer.emplace_back(element.second);
        }
        return answer;
    }
};