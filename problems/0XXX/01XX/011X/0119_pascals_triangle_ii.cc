#include "../../../../common/Includes.h"

class Solution {
private:
    void _recurse(vector<int>& result, int rowIndex) {
        if(rowIndex == 0) {
            result[0] = 1;
            return;
        }
        _recurse(result, rowIndex-1);
        for (int i = rowIndex; i >= 1; i--) {
            result[i] += result[i-1];
        }
    }   
    
    vector<int> _iterate(vector<int>& result, int rowIndex) {
        result[0] = 1;
        
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                result[j] += result[j-1];
            }
        }
        return result;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        _recurse(result, rowIndex);
        return result;
    }
};