#include "../../../../common/Includes.h"

class Solution {
private:
    vector<int> _recursive(TreeNode *root) {
        vector<int> ans;
        
        /* Preconditions */
        if (!root) return ans;
        
        vector<int> left = _recursive(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        
        ans.push_back(root->val);
        
        vector<int> right = _recursive(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
    }
    
    vector<int> _iterative(TreeNode *root) {
        vector<int> ans;
        /* Create the stack */
        stack<TreeNode *> stack;
        TreeNode *curr;
        
        /* Preconditions */
        if (!root) return ans;
        
        /* Setup the stack */
        if(root->right) stack.push(root->right);
        stack.push(root);
        if(root->left) stack.push(root->left);
        curr = stack.top();
        stack.pop();
        
        while(curr)
        {
            if(curr->right) stack.push(curr->right);
            stack.push(curr);
            if(curr->left) stack.push(curr->left);
            
            if (!stack.empty())
            {
                curr = stack.top();
                stack.pop();
            }
            else
                curr = NULL;
        }
        
        return ans;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return _recursive(root);
    }
};