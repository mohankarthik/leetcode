#include "../../../../common/Includes.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    /**
     * Recursive solution
     */
    bool _recursive(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) 
            return left == right;
        if (left->val != right->val)
            return false;
        return _recursive(left->left, right->right) && (_recursive(left->right, right->left));
    }
    
    bool _iterative(TreeNode* left, TreeNode* right) {
        queue<TreeNode *> q;
        q.push(left);
        q.push(right);
        
        while(!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            
            if (left == NULL && right == NULL) continue;
            if (left == NULL || right == NULL) return false;
            if (left->val != right->val) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
    
   
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return _iterative(root->left, root->right);
    }
};