#include "../../../../common/Includes.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for (int i = 0; i < numRows; i++) {
            /* Create the row with i+1 elements of all 1s */
            vector<int> row (i+1, 1);
            
            if (i > 0) {
                for (int j = 1; j < i; j++) {
                    row[j] = result[i-1][j-1] + result[i-1][j];
                }
            }
            
            /* Insert the array */
            result.push_back(row);
        }
        
        return result;
    }
};