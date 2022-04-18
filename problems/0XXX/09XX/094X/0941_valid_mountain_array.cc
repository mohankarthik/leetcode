#include "../../../../common/Includes.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        if (arr[1] < arr[0]) return false;
        
        bool bGoingUp = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i-1]) return false;
            if (bGoingUp) {
                if (arr[i] < arr[i-1]) bGoingUp = false;
            } else {
                if (arr[i] > arr[i-1]) return false;
            }
        }
        
        return (bGoingUp == false);
    }
};