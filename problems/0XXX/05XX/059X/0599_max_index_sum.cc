#include "../../../../common/Includes.h"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map1;
        const int n = list1.size();
        const int m = list2.size();
        for (int i = 0; i < n; i++) {
            map1[list1[i]] = i;
        }
        
        int answerSum = INT_MAX;
        vector<string> answer;
        for (int i = 0; i < m; i++) {
            if (map1.find(list2[i]) != map1.end()) {
                const int newSum = map1[list2[i]] + i;
                if (answerSum > newSum) {
                    answerSum = newSum;
                    answer = vector<string>({list2[i]});
                } else if (answerSum == newSum) {
                    answer.emplace_back(list2[i]);
                }
            }
        }
        return answer;
    }
};