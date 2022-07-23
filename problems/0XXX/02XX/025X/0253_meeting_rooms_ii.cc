#include "../../../../common/Includes.h"

struct pair_comparator {
    bool operator()(const pair<int,bool> &lhs, const pair<int,bool> &rhs) {
        return ((lhs.first > rhs.first) or ((lhs.first == rhs.first) and lhs.second));
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<pair<int,bool>,vector<pair<int,bool>>,pair_comparator> q;
        
        for(auto const &interval: intervals) {
            q.push({interval[0], true});
            q.push({interval[1], false});
        }
        
        int answer = 0;
        int current = 0;
        while(!q.empty()) {
            auto const curr = q.top();
            q.pop();
            if (curr.second == true) {
                current++;
                answer = max(answer, current);
            }
            else {
                current--;
            }
        }
        return answer;
    }
};