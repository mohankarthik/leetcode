#include "../../../../common/Includes.h"

class Solution {
    static const int LENGTH = 4;
    static const inline string START = "0000";
    
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        queue<pair<string,int>> q;
        
        if (dead.count(START))
            return -1;
        
        /* Add the root */
        q.push(make_pair(START,0));
        
        while(!q.empty()) {
            /* Get the first element */
            auto curr_elem = q.front();
            string curr = curr_elem.first;
            int dist = curr_elem.second;
            q.pop();
            
            if (curr == target)
                return dist;
            
            /* Add the neighbors */
            for (int i = 0; i < LENGTH; i++) {
                for (int delta = -1; delta <= 1; delta += 2) {
                    string newStr = curr;
                    newStr[i] = ((curr[i] - '0' + delta + 10) % 10) + '0';
                    
                    if (!dead.count(newStr)) {
                        q.push(make_pair(newStr, dist + 1));
                        dead.insert(newStr);
                    }
                }
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<string> deadends1 = {"0201","0101","0102","1212","2002"};
    assert(sol->openLock(deadends1, "0202") == 6);
    vector<string> deadends2 = {"8888"};
    assert(sol->openLock(deadends2, "0009") == 1);
    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    assert(sol->openLock(deadends3, "8888") == -1);
    vector<string> deadends4 = {"0000"};
    assert(sol->openLock(deadends4, "8888") == -1);
    return 0;
}