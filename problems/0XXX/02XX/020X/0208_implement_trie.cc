#include "../../../../common/Includes.h"

struct TrieNode {
    bool isWord;
    map<char, TrieNode*> children; 
};
class Trie {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (auto ch: word) {
            if ((p->children).count(ch) <= 0) {
                // insert a new node if the path does not exist
                (p->children).insert({ch, new TrieNode()});
            }
            p = (p->children)[ch];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (auto ch: word) {
            if ((p->children).count(ch) <= 0) return false;
            p = (p->children)[ch];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (auto ch: prefix) {
            if ((p->children).count(ch) <= 0) return false;
            p = (p->children)[ch];
        }
        return true;
    }
};