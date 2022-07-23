#include "../../../../common/Includes.h"

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        const int n = nums.size();
        if (n <= k)
            q = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        else {
            q = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.begin()+k);
            for (int i = k; i < n; i++) {
                q.push(nums[i]);
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */