#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            /* Add the 1 if it's the last digit, or just add the carry */
            if (i == digits.size() - 1) {
                digits[i] += 1 + c;
            } else {
                digits[i] += c;
            }
            
            /* Check if there is a new carry */
            if (digits[i] >= 10) {
                digits[i] -= 10;
                c = 1;
            } else {
                c = 0;
            }
        }
        
        /* If there is still a carry left */
        if (c != 0) digits.insert(digits.begin(), c);
        
        /* Return */
        return digits;
    }
};