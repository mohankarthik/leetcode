#include "../../../../common/Includes.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, held = INT_MIN, reset = 0;
        
        for (int price: prices) {
            const int temp = sold;
            
            sold = held + price;
            held = max(held, reset-price);
            reset = max(reset,temp);
        }
        
        return max(sold, reset);
    }
};