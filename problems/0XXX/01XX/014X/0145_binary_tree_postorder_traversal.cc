#include "../common/Includes.h"

class Solution {
private:
    vector<int> _recursive(TreeNode *root) {
        vector<int> ans;
        
        /* Preconditions */
        if (!root) return ans;
        
        vector<int> left = _recursive(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        
        vector<int> right = _recursive(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        
        ans.push_back(root->val);
        
        return ans;
    }
    
    vector<int> _iterative(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        
        while (curr || !stack.empty()) {
            while (curr) {
                stack.push(curr);
                curr = curr -> left;
            }
            curr = stack.top();
            stack.pop();
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
        
        return ans;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return _recursive(root);
    }
};