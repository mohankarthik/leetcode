#include "../../../../common/Includes.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        const int n = fruits.size();
        
        int answer = 0;
        for (int left = 0, right = 0; right < n; right++) {
            count[fruits[right]]++;
            
            while(count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] <= 0)
                      count.erase(fruits[left]);
                left++;
            }
            
            answer = max(answer, right-left+1);
        }
        return answer;
    }
};