#include "../../../../common/Includes.h"

struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (std::pair<T1, T2> const &v) const
    {
        return ((v.first * 31) + v.second);
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        unordered_set<pair<int,int>, pair_hash> seen;
        queue<pair<pair<int,int>,int>> q;
        
        /* Preconditions */
        if (mat.empty() || mat[0].empty())
            throw invalid_argument("Mat is empty");
        
        int n = mat.size();
        int m = mat[0].size();
        
        /* Add all the 0s */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    seen.insert({i, j});
                }
            }
        }
        
        /* Start the search */
        while(!q.empty()) {
            auto curr = q.front();
            int i = curr.first.first;
            int j = curr.first.second;
            int d = curr.second;
            q.pop();
            
            for (int dir = 0; dir <= 2; dir++) {
                for (int delta = -1; delta <= 2; delta += 2) {
                    int new_i = i, new_j = j;
                    if (dir == 0) {
                        new_i += delta;
                    } else {
                        new_j += delta;
                    }
                    
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && seen.find({new_i,new_j}) == seen.end()) {
                        mat[new_i][new_j] = d+1;
                        q.push({{new_i, new_j}, d+1});
                        seen.insert({new_i, new_j});
                    }
                }
            }
        }
        
        return mat;
    }
};