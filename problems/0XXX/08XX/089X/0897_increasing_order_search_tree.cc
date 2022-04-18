#include "../../../../common/Includes.h"

class Solution {
private:
    TreeNode *_newHead = NULL;
    TreeNode *_curr = NULL;
    void _inOrderTraversal(TreeNode *root)
    {
        if (root->left) _inOrderTraversal(root->left);
        
        TreeNode *temp = new TreeNode(root->val);
        temp->left = NULL;
        if (!this->_newHead)
        {
            this->_newHead = temp;
            this->_curr = temp;
        }
        else
        {
            this->_curr->right = temp;
            this->_curr = temp;
        }
        
        if (root->right) _inOrderTraversal(root->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        _inOrderTraversal(root);
        this->_curr->right = NULL;
        return this->_newHead;
    }
};