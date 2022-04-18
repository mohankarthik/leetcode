#include "../../../../common/Includes.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return true;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (((i == 0) || (flowerbed[i-1] == 0))
                && (flowerbed[i] == 0) 
                && ((i == (flowerbed.size() - 1)) || (flowerbed[i+1] == 0))) {
                flowerbed[i] = 1;
                n--;
            }
            if (!n) return true;
        }
        return false;
    }
};