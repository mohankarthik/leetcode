#include "../../../../common/Includes.h"

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        const int n = s.size();
        const int m = t.size();
        
        int i = n-1, j = m-1;
        int s_skip = 0, t_skip = 0;
        while(i >= 0 or j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') { s_skip++; i--; }
                else if (s_skip > 0) { s_skip--; i--; }
                else break;
            }
            while (j >= 0) {
                if (t[j] == '#') { t_skip++; j--; }
                else if (t_skip > 0) { t_skip--; j--; }
                else break;
            }
            
            if (i >= 0 and j >= 0 and s[i] != t[j])
                return false;
            
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        
        return true;
    }
};