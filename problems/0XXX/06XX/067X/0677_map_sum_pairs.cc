#include "../../../../common/Includes.h"

class TrieNode {
public:    
    int val;
    unordered_map<char,TrieNode*> children;

    TrieNode() {
        this->val = 0;
        this->children.clear();
    }
};

class MapSum {
    unordered_map<string,int> mem;
    TrieNode *root;
    
public:
    MapSum() {
        this->root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int diff = val - mem[key];
        TrieNode *cur= root;
        cur->val += diff;
        for (auto ch: key) {
            if (cur->children.count(ch) <= 0) 
                cur->children.insert({ch, new TrieNode()});
            cur->children[ch]->val += diff;
            cur = cur->children[ch];
        }
        mem[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode *cur = root;
        for (auto ch: prefix) {
            if (cur->children.count(ch) <= 0) return 0;
            cur = cur->children[ch];
        }
        return cur->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(void) {
    MapSum *sum = new MapSum();
    sum->insert("apple", 3);
    assert(sum->sum("ap") == 3);
    sum->insert("app", 2);
    assert(sum->sum("ap") == 5);
}