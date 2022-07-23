#include "../../../../common/Includes.h"

class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool isWord;
    
    TrieNode() {
        children.clear();
        isWord = false;
    }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (auto &ch: word) {
            if (cur->children.count(ch) <= 0)
                cur->children.insert({ch, new TrieNode()});
            cur = cur->children[ch];
        }
        cur->isWord = true;
    }
    
    string getSmallestPrefixInDict(string word) {
        TrieNode *cur = root;
        
        string answer = "";
        for (auto &ch: word) {
            if (cur->isWord or cur->children.count(ch) <= 0) break;
            answer += ch;
            cur = cur->children[ch];
        }
        if (cur->isWord) return answer;
        return "";
    }
};

class Solution {
private:
    Trie *trie;
    void populateTrie(vector<string>& dict) {
        trie = new Trie();
        for (auto &word: dict) {
            trie->insert(word);
        }
    }
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        populateTrie(dictionary);
        
        istringstream iss(sentence);
        string word;
        
        string answer = "";
        while(getline(iss, word, ' ')) {
            string prefix = trie->getSmallestPrefixInDict(word);
            if (prefix != "") {
                answer += prefix + " ";
            } else {
                answer += word + " ";
            }
        }
        
        // Remove the last space
        answer.pop_back();
        return answer;
    }
};