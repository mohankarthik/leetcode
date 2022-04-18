#include "../common/Includes.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int answer = 0;
        int l = 0, r = people.size() - 1;
        sort(people.begin(), people.end());
        while (l <= r) {
            if (people[l] + people[r] <= limit) l++;
            r--;
            answer++;
        }
        
        return answer;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<int> people1{ 1, 2 };
    assert(sol->numRescueBoats(people1, 3) == 1);
    vector<int> people2{3,2,2,1};
    assert(sol->numRescueBoats(people2, 3) == 3);
    vector<int> people3{3,5,3,4};
    assert(sol->numRescueBoats(people3, 5) == 4);
}