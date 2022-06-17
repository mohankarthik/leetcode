#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> answer;
        map<int,int> intervals;
        for (auto &row : paint) {
            int left = row[0], right = row[1];

            // Find the interval that's closest to left (just after left)
            auto next = intervals.upper_bound(left), cur = next;

            // Merge the left side interval
            if (cur != intervals.begin() and prev(cur)->second >= left) {
                cur = prev(cur);
                left = cur->second;
            }
            else {
                cur = intervals.insert({left, right}).first;
            }

            // Get the area
            int paint = right - left;

            // Merge the right side while subtracting area as needed & delete those intervals since they
            // are overlaps
            while (next != intervals.end() and next->first < right) {
                paint -= min(right, next->second) - next->first;
                right = max(right, next->second);
                intervals.erase(next++);
            }
            cur->second = max(cur->second, right);
            answer.push_back(max(0, paint));
        }
        return answer;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<vector<int>> input1 {{1,4},{4,7},{5,8}};
    vector<int> output1 {3,3,1};
    assert(sol->amountPainted(input1) == output1);

    vector<vector<int>> input2 {{1,4},{5,8},{4,7}};
    vector<int> output2 {3,3,1};
    assert(sol->amountPainted(input2) == output2);
    
    vector<vector<int>> input3 {{1,5},{2,4}};
    vector<int> output3 {4,2};
    assert(sol->amountPainted(input3) == output3);
    
    vector<vector<int>> input4 {{0,2},{0,5},{2,4}};
    vector<int> output4 {2,3,0};
    assert(sol->amountPainted(input4) == output4);
}