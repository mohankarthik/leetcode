#include "../../../../common/Includes.h"

class Solution {
public:
    int kEmptySlots(const vector<int>& bulbs, int k) {
        const int n = bulbs.size();
        set<int> onBulbs;
        
        for(int i = 0; i < n; i++) {
            const int bulb = bulbs[i];
            onBulbs.insert(bulb);
            const auto it = onBulbs.find(bulb);
            if (it != onBulbs.begin()) {
                if (*it - *prev(it) - 1 == k)
                    return i+1;
            }
            if (next(it) != onBulbs.end()) {
                if (*next(it) - *it - 1 == k)
                    return i+1;
            }
        }
        
        return -1;
    }
};