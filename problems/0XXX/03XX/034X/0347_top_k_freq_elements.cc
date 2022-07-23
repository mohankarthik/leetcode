#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int num: nums) {
            map[num]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        for (auto const &val: map) {
            q.push({val.second, val.first});
            if (q.size() > k) q.pop();
        }
        
        vector<int> answer(k);
        for (int i = k-1; i >= 0; i--) {
            auto val = q.top();
            q.pop();
            answer[i] = val.second;
        }
        return answer;
    }
};