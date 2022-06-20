#include "../../../../common/Includes.h"

/**
0000
0001
0011
0010
0110
0111
0101
0100
1100
1101
1111
1110
1010
1011
1001
1000

0th bit: 1 (0) and then 2 (1) -> 2 (0) alternate
1st bit: 2 (0) and then 4 (1) -> 4 (0) alternate
2nd bit: 4 (0) and then 8 (1) -> 8 (0) alternate
3rd bit: 8 (0) and then 16 (1) -> 16 (0) alternate
*/
class Solution {
private:
    void _recurse(vector<int>& answer, int n) {
        if (!n) {
            answer.push_back(0);
            return;
        }
        
        _recurse(answer, n-1);
        const int currSeqLen = answer.size();
        const int mask = (1 << (n-1));
        for (int i = currSeqLen-1; i >= 0; i--) 
            answer.push_back(answer[i] | mask);
    }
    
    void _iterate(vector<int>& answer, int n) {
        answer.push_back(0);
        for (int i = 1; i <= n; i++) {
            const int currSeqLen = answer.size();
            const int mask = (1 << (i-1));
            
            for(int j = currSeqLen-1; j >= 0; j--) {
                answer.push_back(answer[j] | mask);
            }
        }
    }
public:
    vector<int> grayCode(int n) {
        vector<int> answer;
        _iterate(answer, n);
        return answer;
    }
};