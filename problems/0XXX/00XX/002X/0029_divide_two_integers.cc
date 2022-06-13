#include "../../../../common/Includes.h"

class Solution {
private:
    const static int HALF_INT_MIN = -1073741824;
    
    void _invertSign(int& value, int& negatives) {
        if (value > 0) {
            value = -value;
            negatives--;
        }
    }
    
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN and divisor == -1)
            return INT_MAX;
        
        int negatives = 2;
        _invertSign(dividend, negatives);
        _invertSign(divisor, negatives);
        
        int highestDouble = divisor;
        int highestPowerOfTwo = -1;
        while (highestDouble > HALF_INT_MIN and dividend <= highestDouble + highestDouble) {
            highestPowerOfTwo += highestPowerOfTwo;
            highestDouble += highestDouble;
        }
        
        int quotient = 0;
        while (dividend <= divisor) {
            while (dividend <= highestDouble) {
                quotient += highestPowerOfTwo;
                dividend -= highestDouble;
            }
            
            highestPowerOfTwo >>= 1;
            highestDouble >>= 1;
        }
        
        return (negatives != 1) ? -quotient : quotient;
    }
};