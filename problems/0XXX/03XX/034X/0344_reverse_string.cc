#include "../../../../common/Includes.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 0) return;
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
};