#include "../../../../common/Includes.h"

class Solution {
private:
    bool check(const string& sentence, const string& word) {
        int n = sentence.size(), m = word.size(), j = 0;
        
        for (int i = 0; i < n; i++) {
            if ((j < m) and (sentence[i] == word[j])) { 
                j++; 
            } else if ((i > 1) and (sentence[i - 2] == sentence[i - 1]) and (sentence[i - 1] == sentence[i])) {
                // Nothing to do
            } else if ((0 < i) and (i < (n - 1)) and (sentence[i - 1] == sentence[i]) and (sentence[i] == sentence[i + 1])) {
                // Nothing to do
            } else { 
                return false; 
            }
        }
        return (j == m);
    }
    
public:
    int expressiveWords(const string& sentence, const vector<string>& words) {
        int answer = 0;
        for (const string &word: words) 
            if (check(sentence, word)) 
                answer++;
        return answer;
    }
};