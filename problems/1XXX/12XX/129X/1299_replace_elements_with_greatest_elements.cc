#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int prev_max = 0;
        int max = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        
        for(int i = arr.size() - 2; i >= 0; i--) {
            prev_max = max;
            if (max < arr[i]) { max = arr[i]; }
            arr[i] = prev_max;
        }
        
        return arr;
    }
};