#include "../../../../common/Includes.h"

class Solution {
private:
    unordered_map<int,int> _cache;
public:
    int fib(int n) {
        if (_cache.count(n) > 0)
            return _cache[n];
        if (n == 0 || n == 1)
            return n;
        _cache[n] = fib(n-1) + fib(n-2);
        return _cache[n];
    }
};