#include "../../../../common/Includes.h"

#define RETURN_TOP_N    3

class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    int occurances;
    string str;
    
    TrieNode() {
        children.clear();
        occurances = 0;
        str = "";
    }
};

struct pair_comp {
    bool operator ()(const pair<string,int> &lhs, const pair<string,int> &rhs) {
        return ((lhs.second < rhs.second) or ((lhs.second == rhs.second) and (lhs.first > rhs.first)));
    }
};

class AutocompleteSystem {
private:
    TrieNode *root, *curr;
    priority_queue< pair<string,int>, vector< pair<string,int> >,pair_comp> q;
    int index = 0;
    string current;

    void insert(string sentence, int newOccurances = 1) {
        TrieNode *cur = root;
        for (auto &ch: sentence) {
            if (cur->children.count(ch) <= 0)
                cur->children.insert({ch, new TrieNode()});

            cur = cur->children[ch];
        }
        cur->occurances += newOccurances;
        cur->str = sentence;
    }

    void _dfs(TrieNode *cur) {
        if (cur->str != "") {
            q.push({cur->str,cur->occurances});
        }
        
        for (auto next: cur->children)
            _dfs(next.second);
    }

    void pruneQ(char newChar, int index) {
        vector< pair<string,int> > temp;
        while(q.size()) {
            temp.emplace_back(q.top());
            q.pop();
        }

        for (auto it = temp.begin(); it != temp.end(); ) {
            if (it->first[index] != newChar) {
                it = temp.erase(it);
            } else {
                q.push(*it);
                it++;
            }
        }
    }

    void getVectorFromPQ(vector<string> &answer) {
        vector< pair<string,int> > temp;
        while(answer.size() < RETURN_TOP_N and q.size()) {
            auto curr = q.top();
            temp.emplace_back(curr);
            answer.emplace_back(curr.first);
            q.pop();
        }
        for (auto it = temp.begin(); it != temp.end(); it++) {
            q.push(*it);
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        curr = root;
        current = "";
        index = 0;
        q = priority_queue< pair<string,int>, vector< pair<string,int> >,pair_comp>();
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char ch) {
        if (ch == '#') {
            insert(current);
            current = "";
            curr = root;
            index = 0;
            q = priority_queue< pair<string,int>, vector< pair<string,int> >,pair_comp>();
            return {};
        }

        current += ch;

        if (index != 0) {
            pruneQ(ch, index);
        } else {
            if (!curr || curr->children.count(ch) <= 0) {
                curr = NULL;
                return {};
            }
            curr = curr->children[ch];
            
            _dfs(curr);
        }
        index++;

        vector<string> answer;
        getVectorFromPQ(answer);
        return answer;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
int main(void) {
    vector<string> sentences1 {"i love you","island","iroman","i love leetcode"};
    vector<int> times1 {5,3,2,2};
    vector<char> inputs1 {'i',' ','a','#','i',' ','a','#','i',' ','a','#'};
    vector<vector<string>> outputs1 {
        {"i love you","island","i love leetcode"},
        {"i love you","i love leetcode"},
        {},
        {},
        {"i love you","island","i love leetcode"},
        {"i love you","i love leetcode","i a"},
        {"i a"},
        {},
        {"i love you","island","i a"},
        {"i love you","i a","i love leetcode"},
        {"i a"},
        {}
    };
    AutocompleteSystem *system = new AutocompleteSystem(sentences1, times1);
    for (int i = 0; i < inputs1.size(); i++)
        assert(system->input(inputs1[i]) == outputs1[i]);
}