#include "../../../../common/Includes.h"

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<uint32_t,uint8_t> encodings;
        const uint32_t left_mask = 0xFu << 1u, mid_mask = 0xFu << 3u, right_mask = 0xFu << 5u;
        
        for (auto &res: reservedSeats) {
            if (res[1] > 1 and res[1] < 10)
                encodings[res[0]] |= 1 << (res[1]-2);
        }
        
        uint32_t answer = 2 * n;
        for (auto seats: encodings) {
            uint32_t left = seats.second & 0xF0u;
            uint32_t mid = seats.second & 0x3Cu;
            uint32_t right = seats.second & 0x0FU;
            
            if (left == 0 && right == 0) continue;
            if (left == 0 || mid == 0 || right == 0) answer--;
            else answer -= 2;
        }
        
        return (int)answer;
    }
};