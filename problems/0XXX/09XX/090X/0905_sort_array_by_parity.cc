#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        int temp = 0;
        
        while(i < j) {
            if (((A[i] % 2) == 1) && ((A[j] % 2) == 0)) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            } 
            if ((A[i] % 2) == 0) {
                i++;
            }
            if ((A[j] % 2) == 1) {
                j--;
            }
        }
        
        return A;
    }
};