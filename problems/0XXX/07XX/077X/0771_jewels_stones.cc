#include "../../../../common/Includes.h"

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> mem(jewels.begin(), jewels.end());
        int answer = 0;
        for(const char& ch: stones) {
            if (mem.count(ch)) {
                answer++;
            }
        }
        return answer;
    }
};