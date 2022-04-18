#include "../common/Includes.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int orig_m = m;
        
        while((i < m) && (j < n)) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
                i++;
                m++;
            }
        }
        
        if (j < n) {
            for (; j < n; j++) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                i++;
            }
        }
        
        nums1.resize(orig_m+n);
    }
};