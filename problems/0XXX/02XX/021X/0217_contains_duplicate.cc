#include "../../../../common/Includes.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mem;
        for(int num: nums) {
            if (mem.find(num) != mem.end()) return true;
            mem.insert(num);
        }
        return false;
    }
};