#include "../../../../common/Includes.h"

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
    
public:
    int groups;
    UnionFind(int size) {
        root = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
        groups = size;
    }
    
    int find(int a) {
        if (a == root[a])
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
            } else if (rank[rootA] < rank[rootB]) {
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind *unionFind = new UnionFind(n);
        for (auto &edge: edges) {
            unionFind->unionSet(edge[0], edge[1]);
        }
        return unionFind->groups;
    }
};