#include "../../../../common/Includes.h"
class ArrayReader {
  public:
    int get(int index) {
        return INT_MAX;
    }
};
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 10000;
        
        while(left <= right) {
            const int mid = left + ((right - left) / 2);
            const int val = reader.get(mid);
            if (val == target) return mid;
            if (val > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};