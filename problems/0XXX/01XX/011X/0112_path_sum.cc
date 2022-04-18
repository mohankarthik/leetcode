#include "../../../../common/Includes.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) return true;
            else return false;
        }
        return 
            hasPathSum(root->left, sum - root->val)
            || hasPathSum(root->right, sum - root->val);
    }
};