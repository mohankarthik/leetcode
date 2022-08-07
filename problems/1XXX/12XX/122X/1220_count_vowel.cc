#include "../../../../common/Includes.h"

#define MOD_VAL (1000000007U)

class Solution {
public:
    int countVowelPermutation(int n) {
        /* a, e, i, o, u */
        uint64_t temp[5] = {0, 0, 0, 0, 0};
        uint64_t stringsEndingWith[5] = {1, 1, 1, 1, 1};
        
        for (int i = 2; i <= n; i++) {
            // a -> e
            temp[1] += stringsEndingWith[0];
            
            // e -> a, i
            temp[0] += stringsEndingWith[1];
            temp[2] += stringsEndingWith[1];
            
            // i -> a, e, o, u
            temp[0] += stringsEndingWith[2];
            temp[1] += stringsEndingWith[2];
            temp[3] += stringsEndingWith[2];
            temp[4] += stringsEndingWith[2];
            
            // o -> i, u
            temp[2] += stringsEndingWith[3];
            temp[4] += stringsEndingWith[3];
            
            // u -> a
            temp[0] += stringsEndingWith[4];
            
            for (int j = 0; j < 5; j++) {
                temp[j] %= MOD_VAL;
                stringsEndingWith[j] = temp[j];
                temp[j] = 0ull;
            }
        }
        
        uint64_t answer = 0ull;
        for (int j = 0; j < 5; j++) {
            answer += stringsEndingWith[j];
        }
        return (answer % MOD_VAL);
    }
};