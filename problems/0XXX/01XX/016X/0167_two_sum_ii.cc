#include "../common/Includes.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /* Initialize the result */
        vector<int> result(2,-1);
        
        /* Preconditions */
        if (numbers.size() == 0) return result;
        
        /* Initialize the 2 pointers */
        int i = 0;
        int j = numbers.size() - 1;
        
        while (i < j) {
            int sum = (numbers[i] + numbers[j]);
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                result[0] = i+1;
                result[1] = j+1;
                break;
            }
        }
        
        return result;
    }
};