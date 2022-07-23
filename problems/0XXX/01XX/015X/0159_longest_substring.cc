#include "../../../../common/Includes.h"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> mem;
        const int n = s.length();
        
        int answer = 0;
        for (int left = 0, right = 0; right < n; right++) {
            mem[s[right]]++;
            
            while(mem.size() > 2) {
                mem[s[left]]--;
                if (mem[s[left]] <= 0) mem.erase(s[left]);
                left++;
            }
            
            answer = max(answer, right-left+1);
        }
        return answer;
    }
};
