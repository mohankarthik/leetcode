#include "../../../../common/Includes.h"

class DisjointSets {
private:
    vector<int> root;
    vector<int> rank;
    int size;
    
public:
    DisjointSets(int size) {
        this->size = size;
        root = vector<int>(size);
        rank = vector<int>(size, 0);
        for (int i = 0; i < size; i++) {
            root[i] = i;
        }
    }
    
    int find(int a) {
        if (a == root[a])
            return a;
        return root[a] = find(root[a]);
    }
    
    void insert(int a, int b) {
        const int rootA = find(a);
        const int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                root[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                root[rootA] = rootB;
            } else {
                root[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
    
    unordered_map<int, vector<int>> getSets() {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < size; i++) {
            const int root = find(i);
            map[root].emplace_back(i);
        }
        return map;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = s.length();
        DisjointSets *ds = new DisjointSets(n);
        for (auto const &pair: pairs) {
            ds->insert(pair[0], pair[1]);
        }
        unordered_map<int, vector<int>> components = ds->getSets();
        
        string answer(n, ' ');
        for(auto const &comp: components) {
            vector<char> temp;
            vector<int> indices = comp.second;
            for (auto const &index: indices) {
                temp.emplace_back(s[index]);
            }
            sort(temp.begin(), temp.end());
            
            for (int i = 0; i < indices.size(); i++) {
                answer[indices[i]] = temp[i];
            }
        }
        
        return answer;
    }
};