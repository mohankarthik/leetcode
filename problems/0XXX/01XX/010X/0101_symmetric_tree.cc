#include "../../../../common/Includes.h"

class Solution {
private:
    /**
     * Recursive solution
     */
    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) 
            return left == right;
        if (left->val != right->val)
            return false;
        return _isSymmetric(left->left, right->right) && (_isSymmetric(left->right, right->left));
    }
    
   
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return _isSymmetric(root->left, root->right);
    }
};