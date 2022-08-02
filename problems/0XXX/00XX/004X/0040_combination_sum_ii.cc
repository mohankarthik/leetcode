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
    vector<vector<int>> answer;
    vector<int> current;
    vector<int> candidates;
    int n;
    
    void check(int index, int target) {
        if (target == 0) {
            answer.push_back(current);
            return;
        }
        
        if (target < 0 or index >= n) {
            return;
        }

        
        for (int i = index; i < n; i++) {
            if (i > index and i != 0 and candidates[i] == candidates[i-1])
                continue;
            if (target < candidates[i])
                return;
            current.push_back(candidates[i]);
            check(i+1, target-candidates[i]);
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        this->candidates = candidates;
        this->n = candidates.size();
        
        check(0, target);
        
        return answer;
    }
};