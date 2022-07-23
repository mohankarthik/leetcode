#include "../../../../common/Includes.h"

class Solution {
private:
    int check(int exp, const vector<int>& A, const vector<int>& B, const int n) {
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != exp and B[i] != exp) return -1;
            if (A[i] != exp) rotations_a++;
            else if (B[i] != exp) rotations_b++;
        }
        return min(rotations_a, rotations_b);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int n = tops.size();
        int rotations = check(tops[0], bottoms, tops, n);
        if (rotations != -1 or tops[0] == bottoms[0]) return rotations;
        return check(bottoms[0], bottoms, tops, n);
    }
};