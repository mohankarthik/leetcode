#include "../../../../common/Includes.h"

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count;
    TrieNode(): count(0) {}
};

class Solution {
private:
    string getAbbreviation(string word, int index=0) {
        const int n = word.length();
        if (n - index <= 3) return word;
        
        return word.substr(0, index+1) + to_string(n - index - 2) + word.back();
    }
    
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, vector<pair<string,int>>> groups;
        const int n = words.size();
        
        for (int i = 0; i < n; i++) {
            groups[getAbbreviation(words[i])].push_back({words[i],i});
        }
        
        vector<string> answer(n);
        for(const auto& [_, group]: groups) {
            TrieNode *root = new TrieNode();
            
            for (const auto& [word, _]: group) {
                TrieNode *curr = root;
                const string wordSuffix = word.substr(1);
                
                for (const char& ch: wordSuffix) {
                    if (curr->children.count(ch) == 0)
                        curr->children[ch] = new TrieNode();
                    curr->count++;
                    curr = curr->children[ch];
                }
            }
            
            for (const auto& [word, index]: group) {
                TrieNode *curr = root;
                int i = 1;
                const string wordSuffix = word.substr(1);
                
                for (const char& ch: wordSuffix) {
                    if (curr->count == 1) break;
                    curr = curr->children[ch];
                    i++;
                }
                answer[index] = getAbbreviation(word, i-1);
            }
        }
        
        return answer;
    }
};