#include "../../../../common/Includes.h"

class Solution {
public:
    /*
        if (n == 1) return k;
        if (n == 2) return k + (k-1)*(1) => k + k(k-1);
        
        if (n == 3) return (k-1)*(2) + (k-1)*(1) => (k-1)*(k + k(k-1)) + (k-1)*(2k)
        
    */
    int numWays(int n, int k) {
        int dp_prev_prev = k;
        int dp_prev = k + ((k-1)*dp_prev_prev);
        int dp_curr = 0;
        
        if (n == 1) return dp_prev_prev;
        if (n == 2) return dp_prev;
        
        for (int i = 3; i <= n; i++) {
            dp_curr = ((k-1)*dp_prev) + ((k-1)*dp_prev_prev);
            dp_prev_prev = dp_prev;
            dp_prev = dp_curr;
        }
        
        return dp_curr;
    }
};