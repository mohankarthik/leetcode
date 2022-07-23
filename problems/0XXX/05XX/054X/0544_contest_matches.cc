#include "../../../../common/Includes.h"

class Solution {
private:
    vector<string> current;
    void recurse(void) {
        const int n = current.size();
        if (n == 1)
            return;
        
        vector<string> next;
        int left = 0, right = n-1;
        while(left < right) {
            next.push_back("("+current[left]+","+current[right]+")");
            left++;
            right--;
        }
        swap(current, next);
        recurse();
    }
public:
    string findContestMatch(int n) {
        for (int i = 0; i < n; i++)
            current.push_back(to_string(i+1));
        recurse();
        
        return current[0];
    }
};