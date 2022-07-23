#include "../../../../common/Includes.h"

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;

public:
    int groups;
    UnionFind(int size) {
        groups = size;
        root = vector<int>(size);
        rank = vector<int>(size, 0);
        for(int i = 0; i < size; i++) {
            root[i] = i;
        }
    }
    
    int find(int a) {
        if (root[a] == a)
            return a;
        return root[a] = find(root[a]);
    }
    
    void unionSet(int a, int b) {
        const int rootA = find(a);
        const int rootB = find(b);
        if (rootA != rootB) {
            groups--;
            if (rank[rootA] > rank[rootB]) {
                root[rootB] = rootA;
            } else if (rank[rootB] > rank[rootA]) {
                root[rootA] = rootB;
            } else {
                root[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UnionFind *uf = new UnionFind(n);
        for (auto const &log: logs) {
            uf->unionSet(log[1], log[2]);
            if (uf->groups == 1)
                return log[0];
        }
        return -1;
    }
};