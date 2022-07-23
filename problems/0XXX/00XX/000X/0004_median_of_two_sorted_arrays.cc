#include "../../../../common/Includes.h"

class Solution {
private:
    double _merge_and_sort(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        if ((N % 2) == 0)
            return (nums[(N/2)-1] + nums[N/2])/2.0;    
        return nums[N/2];
    }
    
    double _two_pointer(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        const int N1 = nums1.size(), N2 = nums2.size();
        const int M = N1 + N2;
        while ((p1 + p2) <= (M/2)) {
            if (p1 < N1 && nums1[p1] <= nums2[p2])
                p1++;
            else if (p2 < N2 && nums2[p2] < nums1[p1])
                p2++;
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return _two_pointer(nums1, nums2);
    }
};