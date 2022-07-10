#include "../../common/Includes.h"

bool compareInterval(const vector<int> &lhs, const vector<int> &rhs) {
    return ((lhs[1] < rhs[1]) or ((lhs[1] == rhs[1]) and (lhs[2] < rhs[2])));
}

class Solution {
public:
    vector<int> findFreeSlots(vector<vector<int>> &schedules, int maxVal) {
        sort(schedules.begin(), schedules.end(), compareInterval);
        const int n = schedules.size();
        int st = schedules[0][1], en = schedules[0][2];
        int i = 0;
        vector<int> answer;
        while(i < n) {
            if (schedules[i][1] <= en) {
                en = max(en, schedules[i][2]);
            } else {
                for (int j = en+1; j < schedules[i][1]; j++) 
                    answer.emplace_back(j);
                st = schedules[i][1];
                en = schedules[i][2];
            }
            i++;
        }
        for (int i = en+1; i <= maxVal; i++) answer.emplace_back(i);
        return answer;
    }
};

int main(void) {
    vector<vector<int>> input {{1, 4, 5}, {1, 1, 5}, {2, 2, 6}, {3, 8, 9}, {3, 2, 4}};
    Solution *sol = new Solution();
    vector<int> output {7,10};
    assert(sol->findFreeSlots(input, 10) == output);
    return 0;
}