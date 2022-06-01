#include "../../../../common/Includes.h"

class Solution {
private:
    double _recurse(double x, int N) {
        if (N == 0)
            return 1.0;
        double half = _recurse(x, N/2);
        if (N & 1)
            return half * half * x;
        return half * half;
    }
    void _iterate(double x, int N, double& ans) {
        while(N > 0){
            if(N & 1) ans *= x;
            x *= x;
            N >>= 1;
        }
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0/x;
            N = -N;
        }
        
        /*
        double ans = 1.0;
        _iterate(x, N, ans);
        return ans;
        */
        return _recurse(x, N);
    }
};