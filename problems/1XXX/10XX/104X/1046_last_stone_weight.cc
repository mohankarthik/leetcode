#include "../../../../common/Includes.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() >= 2) {
            int st1 = pq.top(); pq.pop();
            int st2 = pq.top(); pq.pop();
            if (st1 != st2)
                pq.push(abs(st1-st2));
        }
        return pq.empty() ? 0 : pq.top();
    }
};