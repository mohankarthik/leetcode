#include "../../../../common/Includes.h"

class Solution {
public:
    int numSplits(string s) {
        const int n = s.length();
        vector<int> left(n), right(n);
        unordered_set<char> store;
        
        for (int i = 0; i < n; i++) {
            store.insert(s[i]);
            left[i] = store.size();
        }
        
        store.clear();
        
        for (int i = n-1; i >= 0; i--) {
            store.insert(s[i]);
            right[i] = store.size();
        }
        
        int answer = 0;
        for (int i = 1; i < n; i++) {
            if (left[i-1] == right[i]) {
                answer++;
            }
        }
        
        return answer;
    }
};