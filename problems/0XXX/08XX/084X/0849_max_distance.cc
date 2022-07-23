#include "../../../../common/Includes.h"

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int answer = 0;
        int last = -1;
        const int n = seats.size();
        for(int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                answer = (last == -1) ? i : max(answer, ((i - last)/2));
                last = i;
            }
        }
        answer = max(answer, n - last -1);
        return answer;
    }
};