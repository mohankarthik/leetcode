#include "../../../../common/Includes.h"

class Solution {
    vector<int> _with_map(const vector<int>& nums1, const vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        
        unordered_map<int,int> map; 
        for (const int num: nums1) {
            if (!map.count(num) > 0) {
                map[num] = 1;
            } else {
                map[num]++;
            }
        }
        
        vector<int> result;
        for (const int num: nums2) {
            if (map.count(num) > 0 && map[num] > 0) {
                result.push_back(num);
                map[num]--;
            }
        }
        
        return result;
    }
    
    vector<int> _with_two_pointers(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        
        return result;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return _with_map(nums1, nums2);
        //return _with_two_pointers(nums1, nums2);
    }
};