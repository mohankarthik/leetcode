#include "../../../../common/Includes.h"

class TrieNode {
public:
    string str;
    unordered_map<char,TrieNode*> children;
    TrieNode(): str("") {}
};

class Solution {
private:
    TrieNode* root;
    void buildTrie(vector<string>& wordDict) {
        root = new TrieNode();
        for (const string& str: wordDict) {
            TrieNode* curr = root;
            for (const char& ch: str) {
                if (curr->children.count(ch) <= 0) {
                    curr->children[ch] = new TrieNode();
                }
                curr = curr->children[ch];
            }
            curr->str = str;
        }
    }
    
    vector<string> getPrefixes(string s) {
        const int n = s.length();
        TrieNode* curr = root;
        vector<string> answer;
        
        for (int i = 0; i < n; i++) {
            if (curr->children.count(s[i])) {
                cout << s[i];
                curr = curr->children[s[i]];
            } else {
                break;
            }
            if (curr->str != "") {
                answer.emplace_back(curr->str);
                cout << "(" << curr->str << "), ";
            }
        }
        cout << endl;
        return answer;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        buildTrie(wordDict);
        unordered_map<int,bool> dp;
        const int n = s.length();
        
        dp[n] = true;
        for (int i = n-1; i >= 0; i--) {
            dp[i] = false;
            cout << i << " " << s.substr(i) << " -> ";
            for(const string& prefix: getPrefixes(s.substr(i))) {
                dp[i] |= dp[i+prefix.length()];
            }
        }
        return dp[0];
    }
};

int main(void) {
    Solution *sol = new Solution();
    vector<string> input1 {"leet","code"};
    sol->wordBreak("leetcode", input1);
}