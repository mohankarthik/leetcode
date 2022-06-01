#include "../../../../common/Includes.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) 
            return sum == 0;
        return 
            hasPathSum(root->left, sum - root->val)
            || hasPathSum(root->right, sum - root->val);
    }
};