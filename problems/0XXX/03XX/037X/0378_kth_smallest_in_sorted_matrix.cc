#include "../../../../common/Includes.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>> q;
        for(auto const &row: matrix) {
            for (int const &val: row) {
                q.push(val);
                if (q.size() > k)
                    q.pop();
            }
        }
        return q.top();
    }
};