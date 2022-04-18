#include "../../../../common/Includes.h"

class Solution {
private:
    vector<int> _recursive(TreeNode *root) {
        vector<int> ans;
        
        /* Preconditions */
        if (!root) return ans;
        
        ans.push_back(root->val);
        
        vector<int> left = preorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        
        vector<int> right = preorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
    }
    
    vector<int> _iterative(TreeNode *root) {
        vector<int> ans;
        /* Create the stack */
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        
        /* Preconditions */
        if (!root) return ans;
        
        while(curr)
        {
            if(curr->right) stack.push(curr->right);
            if(curr->left) stack.push(curr->left);
            ans.push_back(curr->val);
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
    vector<int> preorderTraversal(TreeNode* root) {
        return _iterative(root);
    }
};