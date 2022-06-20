#include "../../../../common/Includes.h"

struct vector_int_hash {
    size_t operator()(const vector<int> &myVector) const 
    {
        hash<int> hasher;
        size_t answer = 0;
        for (int i: myVector) 
        {
            answer ^= hasher(i) + 0x9e3779b9 + (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int n = nums.size();
        const int max = (1 << n);
        
        sort(nums.begin(), nums.end());
        
        unordered_set<vector<int>, vector_int_hash> answer_set;
        for (int i = 0; i < max; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }
            answer_set.insert(temp);
        }
        
        vector<vector<int>> answer (answer_set.begin(), answer_set.end());
        
        return answer;
    }
};