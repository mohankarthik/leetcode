#include "../../../../common/Includes.h"

/** Tests
 * [1,2,3,4,5], k = 4, x = 3 => [1,2,3,4]
 * [1,2,3,4,5], k = 4, x = -1 => 1,2,3,4]
 * [1], k = 1, x = 1 => [1]
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /* Preconditions */
        if (arr.empty())
            throw invalid_argument("Array is empty");
        if (k > arr.size())
            throw invalid_argument("K > array size");
        
        /* Get the size */
        const int n = arr.size();

        /* Find the index of value lower than x */
        int left = 0, right = n-k;
        while (left < right) {
            const int mid = left + ((right - left) / 2);
            if (x - arr[mid] > arr[mid+k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};