#include "../../../../common/Includes.h"

class Solution {
private:
    int getByteSequence(uint8_t data) {
        if ((data & 0xF8u) == 0xF0u)
            return 4;
        if ((data & 0xF0u) == 0xE0u)
            return 3;
        if ((data & 0xE0u) == 0xC0u)
            return 2;
        if ((data & 0x80u) == 0x80u)
            return 0;
        if ((data & 0x80u) == 0x00u)
            return 1;
        return -1;
    }
public:
    bool validUtf8(const vector<int>& dataSeq) {
        int numInCurSeq = 0;
        for (int data: dataSeq) {
            int decode = getByteSequence(data);
            // Check if code is valid
            if (decode == -1)
                return false;
            
            // Check if ordering is valid
            if (numInCurSeq > 0 and decode != 0)
                return false;
            
            if (decode >= 1) {
                numInCurSeq = decode-1;
            } else {
                numInCurSeq--;
                if (numInCurSeq < 0)
                    return false;
            }            
        }
        return numInCurSeq == 0;
    }
};