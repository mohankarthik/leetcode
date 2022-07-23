#include "../../../../common/Includes.h"

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(const string& s, int k) {
        const int n = s.size();
        int left = 0;
        int right = 0;
        unordered_map<char, int> seen;
        int answer = 0;
        while (right < n) {
            if (seen.count(s[right]) <= 0)
                seen[s[right]] = 0;
            seen[s[right]]++;
            right++;
            
            while (seen.size() > k) {
                seen[s[left]]--;
                if (seen[s[left]] == 0)
                    seen.erase(s[left]);
                left++;
            }
            
            //cout << left << " " << right << " " << seen.size() << endl;
            
            answer = max(answer, right-left);
        }
        return answer;
    }
};