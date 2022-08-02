#include "../../../../common/Includes.h"

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        queue<pair<int,vector<int>>> q;
        const int n = candidates.size();
        
        unordered_set<vector<int>, VectorHash> seen;
        for (int i = 0; i < n; i++) {
            if (candidates[i] <= target) {
                q.push({candidates[i], {candidates[i]}});
            }
        }
        
        unordered_set<vector<int>> set;
        while(!q.empty()) {
            const auto [value, path] = q.front();
            q.pop();

            if (seen.count(path) > 0)
                continue;
            
            seen.insert(path);
            
            if (value == target) {
                vector<int> temp = path;
                set.insert(temp);
                continue;
            }
            
            for (int i = 0; i < n; i++) {
                if (candidates[i] + value <= target) {
                    vector<int> temp = path;
                    temp.push_back(candidates[i]);
                    sort(temp.begin(), temp.end());
                    q.push({candidates[i] + value, temp});
                }
            }
        }
        
        vector<vector<int>> answer(set.begin(), set.end());
        return answer;
    }
};