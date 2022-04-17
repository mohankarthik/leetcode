#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> q;
        unordered_set<int> seen;

        /* Preconditions */
        if (n <= 0)
            return -1;
        
        int sqrt_n = sqrt(n);
        for (int i = 0; i < sqrt_n+1; i++) {
            int temp = i*i;
            q.push(make_pair(temp,1));
            seen.insert(temp);
        }
        
        while(!q.empty()) {
            int val = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if (val == n)
                return dist;
            
            for (int i = 0; i < sqrt_n+1; i++) {
                int temp = (i*i) + val;
                if (seen.find(temp) == seen.end() && temp <= n) {
                    q.push(make_pair(temp, dist + 1));
                    seen.insert(temp);    
                }
            }
        }
        
        return -1;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->numSquares(12) == 3);
    assert(sol->numSquares(13) == 2);
    assert(sol->numSquares(-1) == -1);
    assert(sol->numSquares(0) == -1);
    return 0;
}