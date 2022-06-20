#include "../../../../common/Includes.h"

class Solution {
private:
    unordered_set<string> wordsPresent;
    vector<string> words;
    unordered_map<string, int> dp;
    
    int dfs(string curr) {
        if (dp.find(curr) != dp.end()) return dp[curr];
        
        int answer = 1;
        for (int i = 0; i < curr.length(); i++) {
            const string newWord = curr.substr(0,i) + curr.substr(i+1);
            if (wordsPresent.find(newWord) != wordsPresent.end()) {
                answer = max(answer, 1 + dfs(newWord));
            }
        }
        dp[curr] = answer;
        return answer;
    }
public:
    int longestStrChain(vector<string>& words) {
        this->words = words;
        for (const auto &word: words) wordsPresent.insert(word);
        int answer = 0;
        for (const string &word: words) answer = max(answer, dfs(word));
        return answer;
    }
};