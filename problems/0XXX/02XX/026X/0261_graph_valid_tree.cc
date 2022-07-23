#include "../../../../common/Includes.h"

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> root(n);
        for (int i = 0; i < n; i++) root[i] = i;
        int groups = n;
        for (auto &edge: edges) {
            const int a = edge[0];
            const int b = edge[1];
            const int rootA = root[a];
            const int rootB = root[b];
            if (rootA == rootB) return false;
            if (rootA != rootB) {
                groups--;
                for (int i = 0; i < n; i++) {
                    if (root[i] == rootB) {
                        root[i] = rootA;
                    }
                }   
            }
        }
        
        return groups == 1;
    }
};