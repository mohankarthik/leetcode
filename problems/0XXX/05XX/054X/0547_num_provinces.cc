#include "../../../../common/Includes.h"

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int size) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int a) {
        if (a == root[a])
            return a;
        return root[a] = find(root[a]);
    }
    
    void unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
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
    
    bool isConnected(int a, int b) {
        return root[a] == root[b];
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        
        UnionFind *unionFind = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected[i][j]) unionFind->unionSet(i, j);
            }
        }
        
        set<int> answer;
        for (int i = 0; i < n; i++) {
            answer.insert(unionFind->find(i));
        }
        return answer.size();
    }
};

int main(void) {
    Solution *sol = new Solution();
    vector<vector<int>> input1 {{1,1,0},{1,1,0},{0,0,1}};
    assert(sol->findCircleNum(input1) == 2);
    vector<vector<int>> input2 {{1,0,0},{0,1,0},{0,0,1}};
    assert(sol->findCircleNum(input2) == 3);
}