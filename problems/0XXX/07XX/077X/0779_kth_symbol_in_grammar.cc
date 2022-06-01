#include "../../../../common/Includes.h"

class Solution {
private:
    int _recurse(int n, int k) {
        if (n == 1)
            return 0;
        
        int prevK = 0;
        int prevSz = 1 << (n-2);
        if (k > prevSz) {
            prevK = k - prevSz;
            return 1 - _recurse(n-1, prevK);
        } else {
            prevK = k;
            return _recurse(n-1, prevK);
        }
    }
public:
    int kthGrammar(int n, int k) {
        return _recurse(n,k);
    }
};