#include "../../../../common/Includes.h"

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        const int n = s.length();
        const int m = indices.size();
        
        string answer;

        if (indices[0] != 0) {
            answer += s.substr(0, indices[0]);
        }
        
        for(int i = 0; i < m; i++) {
            // Update targets based on whether a match is found or not
            const int st = indices[i];
            const int len = sources[i].length();
            const int end = st + len;
            answer += (sources[i] == s.substr(st, len)) ? targets[i] : sources[i];
            
            // Add targets if there is a gap
            if (i < m-1 and end < indices[i+1])
                answer += s.substr(end, indices[i+1]-(end));
        }
        
        const int end = indices.back()+sources.back().length();
        answer += s.substr(end);
        return answer;
    }
};

int main(void) {
    Solution *sol = new Solution();
    vector<int> indices1 {0, 2};
    vector<string> sources1 {"a", "cd"};
    vector<string> targets1 {"eee", "ffff"};
    assert(sol->findReplaceString("abcd", indices1, sources1, targets1) == "eeebffff");
}