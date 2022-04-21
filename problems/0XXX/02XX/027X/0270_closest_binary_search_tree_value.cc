#include "../../../../common/Includes.h"

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root == NULL)
            return INT_MAX;
        
        int ans;
        if (target == root->val)
            ans = root->val;
        else if (target < root->val)
            ans = closestValue(root->left, target);
        else
            ans = closestValue(root->right, target);
        
        return (abs(root->val - target) < abs(ans - target)) ? root->val : ans;
    }
};