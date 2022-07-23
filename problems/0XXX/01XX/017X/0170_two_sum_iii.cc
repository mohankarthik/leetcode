#include "../../../../common/Includes.h"

class TwoSum {
private:
    unordered_map<long,int> counts;
public:
    TwoSum() {}
    
    void add(int number) {
        counts[number]++;
    }
    
    bool find(int value) {
        for(const auto &mem: counts) {
            const long diff = value - mem.first;
            if (diff == mem.first) {
                if (mem.second > 1)
                    return true;
            } else {
                if (counts.count(diff) > 0)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */