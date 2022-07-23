#include "../../../../common/Includes.h"

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q (sticks.begin(), sticks.end());
        int answer = 0;
        while(q.size() > 1) {
            const int num1 = q.top(); q.pop();
            const int num2 = q.top(); q.pop();
            q.push(num1 + num2);
            answer += num1 + num2;
        }
        return answer;
    }
};