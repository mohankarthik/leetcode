#include "../../../../common/Includes.h"

class Solution {
private:
    vector<int> with_sets(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> ans;
        set_intersection(set1.begin(), set1.end(),
                         set2.begin(), set2.end(),
                         back_inserter(ans));
        return ans;
    }
    
    vector<int> with_single_set(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num: nums2)
            if (set.erase(num) > 0) {
                ans.push_back(num);
            }
        return ans;
    }
    
    vector<int> without_extra_space(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int p1 = 0, p2 = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        while (p1 < n && p2 < m) {
            if (nums1[p1] == nums2[p2]) {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if (nums1[p1] > nums2[p2]) {
                p2++;
            }
            else {
                p1++;
            }
            while(p1 > 0 && p1 < n && nums1[p1] == nums1[p1 - 1]) p1++;
            while(p2 > 0 && p2 < m && nums2[p2] == nums2[p2 - 1]) p2++;
        }
        return ans;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        return without_extra_space(nums1, nums2);
    }
};